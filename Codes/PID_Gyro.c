/*
	Gyro-s PID-is Chartva Ragac Droit

	@param [PID*] pid							PID-is Pointeri Romelsac Chavrtavt Ragac Droit
	@param [float] time						Dro Ramden Xnit Chavrtavt
*/
void PID_Gyro_On_ForTime(PID* pid, float time, bool oneSided = false)
{
	if(oneSided)
	{
		PID_Gyro_oneSided_Start(pid)
	}
	else
	{
		PID_Gyro_Start(pid); // Chavrtavt PID-s
	}

	wait(time); // Davicdit Sanam Sasurveli Dro Ar Gava

	if(oneSided)
	{
		PID_Gyro_oneSided_Stop()
	}
	else
	{
		PID_Gyro_Stop(); // Gamovrtavt PID-s
	}
}

/*
	Gyro-s PID-s Chartva Sanam Ragac Konkretuli Kutxit Ar Shevtrialdebit

	@param [PID*] pid 						PID-is Pointer-i Romelsac Chavrtavt Sanam Sasurvel Mandzilze Ar Mivalt
	@param [float] angle		 			Kutxe Romlitac Unda Shevtrialdet
*/
void PID_Gyro_Rotate(PID* pid, float angle, bool oneSided = false)
{
	float initAngle = getGyroDegrees(gyro); // Vinaxavt Sawyis Kutxes

	pid->setpoint = initAngle + angle; // Setpointad Vutitebt Sawyiss + Sasurveli Shemotrialebis Kutxes

	if(oneSided)
	{
		PID_Gyro_oneSided_Start(pid)
	}
	else
	{
		PID_Gyro_Start(pid); // Chavrtavt PID-s
	}

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

	if(oneSided)
	{
		PID_Gyro_oneSided_Stop()
	}
	else
	{
		PID_Gyro_Stop(); // Gamovrtavt PID-s
	}
}


/*
	Gyro-s PID-s Chartva Sanam Ultra Sonic-it Konkretul Distanciamde Ar Mivalt

	[
		Ultra Sonic-i Robotis Win Aris Dayenebuli
	]

	@param [PID*] pid 						PID-is Pointer-i Romelsac Chavrtavt Sanam Sasurvel Mandzilze Ar Mivalt
	@param [float] distance 			Mandzili Romelic Unda Achvenos Ultra Sonic-ma
*/
void PID_Gyro_On_Until_Distance(PID* pid, float distance, bool oneSided = false)
{
	if(oneSided)
	{
		PID_Gyro_oneSided_Start(pid)
	}
	else
	{
		PID_Gyro_Start(pid); // Chavrtavt PID-s
	}

	while(distance > getUSDistance(usonic)){} // Sanam Distancia Metia Vidre Gvinda Rom Iyos, Mivdivart Win

	// Vrtavt Ukan Wasvlis Modshi
	pid->moveSpeed *= -1;

	while(distance < getUSDistance(usonic)){} // Sanam Distancia Naklebia Vidre Gvinda Rom Iyos, Mivdivart ukan

	// Vabrunebt Chveulebriv Modshi
	pid->moveSpeed *= -1;

	if(oneSided)
	{
		PID_Gyro_oneSided_Stop()
	}
	else
	{
		PID_Gyro_Stop(); // Gamovrtavt PID-s
	}
}

/*
	Gyro-s PID-s Chartva Sanam Color Sensor-it Sasurvel Reflected-s Ar Mivigebt

	@param [PID*] pid 						PID-is Pointer-i Romelsac Chavrtavt Sanam Sasurvel Mandzilze Ar Mivalt
	@param [float] _setpoint 			Sasurveli LineFollower-is Color Sensor-is Mnishvneloba
*/
void PID_Gyro_On_Until_Reflected(PID* pid, float _setpoint, bool oneSided = false)
{
	if(oneSided)
	{
		PID_Gyro_oneSided_Start(pid)
	}
	else
	{
		PID_Gyro_Start(pid); // Chavrtavt PID-s
	}

	if(_setpoint < getColorReflected(color1))
	{
		while(_setpoint < getColorReflected(color1)){} // Vamushavebt Sanam Sasurvel Reflected Measurement-s Ar Mivigebt
	}

	else
	{
		while(_setpoint > getColorReflected(color1)){} // Vamushavebt Sanam Sasurvel Reflected Measurement-s Ar Mivigebt
	}

	if(oneSided)
	{
		PID_Gyro_oneSided_Stop()
	}
	else
	{
		PID_Gyro_Stop(); // Gamovrtavt PID-s
	}
}
