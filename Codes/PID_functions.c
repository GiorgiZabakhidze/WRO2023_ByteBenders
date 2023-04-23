/*
	PID LineFollower-is Chartva Ragac Paqtoris Mixedvit

	@param [PID*] pid							PID-is Pointeri Romelic Gveqneba Chartuli
	@param [bool*] factor					Paqtoris Pointer-i Romelzedacaa Damokidebuli Chartuli Iqneba Tu Ara(true=Chartuli, false=Gamortuli)
	@param [bool] rev 						Marjvena Mxridan Mivyvebit Xazs Tu Marcxena(Marjvena=true, Marcxena=false)
*/
void PID_LineFollower_On_Until(PID* pid, bool* factor, bool rev = 1)
{
	PID_LineFollower_Start(pid, rev); // Chavrtavt Line Follower-s

	while(factor){} // Arapers Vaketebt Sanam Factor Aris True

	PID_LineFollower_Stop(); // Roca Gaxdeba False, Gamovrtavt Line Follower-s
}


/*
	PID Line Follwer-is Chartva Ragac Droit

	@param [PID*] pid							PID-is Pointer-i Romelsac Chavrtavt Ragac Droit
	@param [float] time						Dro Ramden Xnit Chavrtavt
	@param [bool] rev 						Marjvena Mxridan Mivyvebit Xazs Tu Marcxena(Marjvena=true, Marcxena=false)
*/
void PID_LineFollower_On_ForTime(PID* pid, float time, bool rev = 1)
{
	PID_LineFollower_Start(pid, rev); // Chavrtavt PID-s

	wait(time); // Vicdit Sasurveli Dro

	PID_LineFollower_Stop(); // Gamovrtavt PID-s
}


/*
	PID Line Follower-is Chartva Sanam Ultra Sonic-it Konkretul Distanciamde Ar Mivalt

	[
		Ultra Sonic-i Robotis Win Aris Dayenebuli
	]

	@param [PID*] pid 						PID-is Pointer-i Romelsac Chavrtavt Sanam Sasurvel Mandzilze Ar Mivalt
	@param [float] distance 			Mandzili Romelic Unda Achvenos Ultra Sonic-ma
	@param [bool]	rev 						Marjvena Mxridan Mivyvebit Xazs Tu Marcxena(Marjvena=true, Marcxena=false)
*/
void PID_LineFollower_On_Until_Distance(PID* pid, float distance, bool rev = 1)
{
	PID_LineFollower_Start(pid, rev); // Chavrtavt PID-s

	while(distance < getUSDistance(usonic)){} // Sanam Distancia Metia Vidre Gvinda Rom Iyos, Mivdivart Win

	// Vrtavt Ukan Wasvlis Modshi
	pid->moveSpeed *= -1;

	while(distance > getUSDistance(usonic)){} // Sanam Distancia Naklebia Vidre Gvinda Rom Iyos, Mivdivart ukan

	// Vabrunebt Chveulebriv Modshi
	pid->moveSpeed *= -1;

	PID_LineFollower_Stop(); // Gamovrtavt PID-s

	/*
		[
			Win Da Ukan Mivdivart Radgan Zustad Ar Vicit Axlandeli Distancia Sasurvelze Metia Tu Naklebi.
			Amitom Vaketebt orives, Radgan Ertmanets Xels Mainc Ar Ushlian.
		]
	*/
}


/*
	LineFollower-is Chartva Sanam Color Sensor-it Konkretul Mnishvnelobas Mivigebt

	@param [PID*] pid 						PID-is Pointer-i Romelsac Chavrtavt Sanam Sasurvel Mandzilze Ar Mivalt
	@param [float] _setpoint 			Sasurveli Checker Color Sensor-is Mnishvneloba
*/
void PID_LineFollower_On_Until_Reflected(PID* pid, float _setpoint, bool rev = 1)
{
	PID_LineFollower_Start(pid, rev); // Chavrtavt PID-s

	if(_setpoint < getColorReflected(color2))
	{
		while(_setpoint < getColorReflected(color2)){} // Vamushavebt Sanam Sasurvel Reflected Measurement-s Ar Mivigebt
	}

	else
	{
		while(_setpoint > getColorReflected(color2)){} // Vamushavebt Sanam Sasurvel Reflected Measurement-s Ar Mivigebt
	}

	PID_LineFollower_Stop(); // Gamovrtavt PID-s
}


/*
	PID Gyro-is Chartva Ragac Paqtoris Mixedvit

	@param [PID*] pid							PID-is Pointeri Romelic Gveqneba Chartuli
	@param [bool*] factor					Paqtoris Pointer-i Romelzedacaa Damokidebuli Chartuli Iqneba Tu Ara(true=Chartuli, false=Gamortuli)
*/
void PID_Gyro_On_Until(PID* pid, bool* factor)
{
	PID_Gyro_Start(pid); // Chavrtavt Gyro-s PID-s

	while(factor){} // Arapers Vaketebt Sanam Factor Aris True

	PID_Gyro_Stop(); // Roca Gaxdeba False, Gamovrtavt Line Follower-s
}


/*
	Gyro-s PID-is Chartva Ragac Droit

	@param [PID*] pid							PID-is Pointeri Romelsac Chavrtavt Ragac Droit
	@param [float] time						Dro Ramden Xnit Chavrtavt
*/
void PID_Gyro_On_ForTime(PID* pid, float time)
{
	PID_Gyro_Start(pid); // Chavrtavt PID-s

	wait(time); // Davicdit Sanam Sasurveli Dro Ar Gava

	PID_Gyro_Stop(); // Gamovrtavt PID-s
}

/*
	Gyro-s PID-s Chartva Sanam Ragac Konkretuli Kutxit Ar Shevtrialdebit

	@param [PID*] pid 						PID-is Pointer-i Romelsac Chavrtavt Sanam Sasurvel Mandzilze Ar Mivalt
	@param [float] angle		 			Kutxe Romlitac Unda Shevtrialdet
*/
void PID_Gyro_Rotate(PID* pid, float angle)
{
	float initAngle = getGyroDegrees(gyro); // Vinaxavt Sawyis Kutxes

	pid->setpoint = initAngle + angle; // Setpointad Vutitebt Sawyiss + Sasurveli Shemotrialebis Kutxes

	PID_Gyro_Start(pid); // Chavrtavt PID-s

	bool goodAngle = false; // Vutitebt Kutxis "Sikarges" Boolean-shi

	while(1)
	{
		if(goodAngle && getGyroDegrees(gyro) == initAngle + angle) // Tu Kutxe Wina Iteraciaze Kargi Iyo Da Axlac Kargia, Vamtavrebt Mushaobas
		{
			break;
		}

		goodAngle = getGyroDegrees(gyro) == initAngle + angle; // Vanaxlebt Kutxis "Sikarges"

		if(goodAngle) // Tu Kutxe Kargia, Vicdit 20 Miliwami Rom Shemdegi Iteracia Ragac Drois Shemdeg Movaxdinot Rac Gvazgvevs Inerciis Shemtxvevisgan
		{
			wait(20);
		}
	}

	PID_Gyro_Stop(); // Gamovrtavt PID-s
}


/*
	Gyro-s PID-s Chartva Sanam Ultra Sonic-it Konkretul Distanciamde Ar Mivalt

	[
		Ultra Sonic-i Robotis Win Aris Dayenebuli
	]

	@param [PID*] pid 						PID-is Pointer-i Romelsac Chavrtavt Sanam Sasurvel Mandzilze Ar Mivalt
	@param [float] distance 			Mandzili Romelic Unda Achvenos Ultra Sonic-ma
*/
void PID_Gyro_On_Until_Distance(PID* pid, float distance)
{
	PID_Gyro_Start(pid); // Chavrtavt PID-s

	while(distance > getUSDistance(usonic)){} // Sanam Distancia Metia Vidre Gvinda Rom Iyos, Mivdivart Win

	// Vrtavt Ukan Wasvlis Modshi
	pid->moveSpeed *= -1;

	while(distance < getUSDistance(usonic)){} // Sanam Distancia Naklebia Vidre Gvinda Rom Iyos, Mivdivart ukan

	// Vabrunebt Chveulebriv Modshi
	pid->moveSpeed *= -1;

	PID_Gyro_Stop(); // Gamovrtavt PID-s
}

/*
	Gyro-s PID-s Chartva Sanam Color Sensor-it Konkretul Distanciamde Ar Mivalt

	@param [PID*] pid 						PID-is Pointer-i Romelsac Chavrtavt Sanam Sasurvel Mandzilze Ar Mivalt
	@param [float] _setpoint 			Sasurveli LineFollower-is Color Sensor-is Mnishvneloba
*/
void PID_Gyro_On_Until_Reflected(PID* pid, float _setpoint)
{
	PID_Gyro_Start(pid); // Chavrtavt PID-s

	if(_setpoint < getColorReflected(color1))
	{
		while(_setpoint < getColorReflected(color1)){} // Vamushavebt Sanam Sasurvel Reflected Measurement-s Ar Mivigebt
	}

	else
	{
		while(_setpoint > getColorReflected(color1)){} // Vamushavebt Sanam Sasurvel Reflected Measurement-s Ar Mivigebt
	}

	PID_Gyro_Stop(); // Gamovrtavt PID-s
}
