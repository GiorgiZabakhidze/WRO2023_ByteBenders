struct PID // PID-s Struqtura. Sheinaxavs PID-s Mnishvnelobebs.
{
	// Koepicientebi P,I,D.
	float Kp;
	float Ki;
	float Kd;

	float Kn; // Low-Pass Filter-is Maqsimaluri Sixshire

	float T; // Ganaxlebebs Shoris Dro.

	float integrator; // Integratori.
	float prevError; // Wina Errori.
	float derivative; // Wina Warmoebuli
	float prevMeasurement; // Wina Sensoris Measurement

	float outLimMax; // Correction-is Maqsimaluri Limiti.
	float outLimMin; // Correction-is Minimaluri Limiti.

	float moveSpeed; // Modzraobis Sichqare Pirvel Kontrolirebul Motorze Idealur Shemtxvevashi (Tu Borbalia Marcxena)
	float setpoint; // Default Setpointi
	float lineCorrectionTime; // LineFollower-it Gzaze Gasworebis Dro Roca Gyro-ti Midixar Xazamde
	bool oneSided; // Tu Cal Borbals Vatrialebt, Gansazgvravs Romeli Borbals Vatrialebt (True=Marjvena, False=Marcxena)
	bool side; // Tu Cal Borbals Vatrialebt, Gansazgvravs Romeli Borbals Vatrialebt (True=Marjvena, False=Marcxena)
	float acceptableRange; // Misagebi Gansxvaveba Sasurveli Shedegidan Sadac Programas Aqvs Upleba Shewyvitos Robotis Gasworeba

	float out; // Correction
}


/*
	LTI Systemis Cvladebs DasawyisShi Nulovani Mnishvneloba Aqvt

	Varesetebs Cvladebs
*/
void PID_resetVariables(PID* pid)
{
	pid->integrator = 0;
	pid->prevError = 0;
	pid->derivative = 0;
	pid->prevMeasurement = 0;
}


/*
	Ragac Konkretuli PID-s Construction.

	@param [PID] pid            			PID-s structuris reference
	@param [float] Kp_val							P koepicienti
	@param [float] Ki_val							I koepicienti
	@param [float] Kd_val							D koepicienti
	@param [float] Kn_val							N koepicienti
	@param [float] outLimMax_val    	Maqsimaluri Correction
	@param [float] outLimMin_val    	Minimaluri Correction
	@param [float] setpoint_val				Sasurveli Mnishvneloba
	@param [float] moveSpeed_val 		Motor-is Sawyisi Sichqare

*/
void PID_init(PID* pid, float Kp_val, float Ki_val, float Kd_val, float Kn_val, float outLimMax_val, float outLimMin_val, float setpoint_val, float moveSpeed_val)
{
	// Miscems Shesabamis Koepicientebs Funqciashi Gadacemul Mnishvnelobebs

		pid->Kp = Kp_val;
		pid->Ki = Ki_val;
		pid->Kd = Kd_val;
		pid->Kn = Kn_val;

		pid->outLimMax = outLimMax_val;
		pid->outLimMin = outLimMin_val;
		pid->moveSpeed = moveSpeed_val;
		pid->setpoint = setpoint_val;

		pid->T = 0.02;

		pid->lineCorrectionTime = 0;
		pid->oneSided = false;
		pid->side = false;
		pid->acceptableRange = 0;

		PID_resetVariables(pid);
}


/*
	Ragac Konkretuli PID-s update.

	@param [PID] pid            	PID-s structuris reference
	@param [float] setPoint				Sasurveli Setpointi
	@param [float] measurement    sensoris dabrunebuli mnishvneloba
	@return [float] PID-s Correction.
*/
void PID_Update(PID* pid, float setPoint, float measurement)
{
	// Vitvlit Errors.

	float error = setPoint - measurement;


	/*
	** Vitvlit Proporciulis Mnishvnelobas
	*/

	float proportional = error * pid->Kp;



	/*
	** Vitvlit Integratoris Mnishvnelobas
	*/

		// Vitvlit Sashualo Errors, Rac Aris Wina Da Axlandeli Errorebis Jamis Naxevari.
		float averageError = 0.5 * (error + pid->prevError);

		// Sashualo Errors Vamravlebt Ganaxlebebs Shoris Droze. Anu Daaxloebit Vigebt Ra Errori Qonda 'T' Drois Ganmavlobashi.
		float addition = averageError * pid->T;

		// Migebuls Vamravlebt Ki-ze Da Vumatebt Integrators.
		float integrator = pid->integrator +  pid->Ki * addition;


	/*
	** Vitvlit Derivative-s Mnishvnelobas
	*/

		// Axlandel Errors Vaklebt Wina errors, Da Vamravlebt Kd-ze.
		pid->derivative = -(2 * pid->Kd * (measurement - pid->prevMeasurement)	// Azrze Ar Var Ra Pormulaa Ubralod Dakopirebulia Sando Wyarodan dd
                        + (2 * pid->Kn - pid->T) * pid->derivative)
                        / (2 * pid->Kn + pid->T);

	/*
	** Vitvlit Correction-s
	*/

		// Correction Aris Proporciulis, Integratoris Da Derivative-s Jami.
		float Correction = proportional + integrator + pid->derivative;


	/* Vigebt Saboloo Pasuxs */

		// Anti-Windup.
		// Tu Correction-i Maqsimalur Correction-is Mnishvnelobas Gascda Da Erroris Nishani Correctionis Nishanis Tolia Aseve Vclampavt Integrators.
		// Amistvis Shemovigebt Axal Boolean-s.
		bool clamp_integrator = false;

		// Vclampavt Correction-s Mis Maqsimalur Da Minimalur Mnishvnelobebs Shoris
			if(Correction > pid->outLimMax - pid->moveSpeed)
			{
				Correction = pid->outLimMax - pid->moveSpeed;

				if(sign(error) == sign(Correction)) // Tu Nishnebi Emtxveva, Vclampavt Integratorsac.
					clamp_integrator = true;
			}

			else if(Correction < pid->outLimMin + pid->moveSpeed)
			{
				Correction = pid->outLimMin + pid->moveSpeed;

				if(sign(error) == sign(Correction)) // Tu Nishnebi Emtxveva, Vclampavt Integratorsac.
					clamp_integrator = true;
			}

		//

	/*
	** Correctionis Dabrunebamde Vcvlit Shesacvlel Mnishvnelobebs.
	*/

		// Wina Errorad Vsvavt Axlandel Errors.
		pid->prevError = error;

		// Wina Measurementad Vsvavt Axlandel Measurements.
		pid->prevMeasurement = measurement;

		if(!clamp_integrator)// Vcvlit Integrators, Tu Ar Wirdeba Anti-Windup.
			pid->integrator = integrator;

	// Vinaxavt Correction-s Struqturashi
	pid->out = Correction;
}
