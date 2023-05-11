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


///*
//	LineFollower-is Chartva Sanam Color Sensor-it Konkretul Mnishvnelobas Mivigebt

//	@param [PID*] pid 						PID-is Pointer-i Romelsac Chavrtavt Sanam Sasurvel Mandzilze Ar Mivalt
//	@param [float] _setpoint 			Sasurveli Checker Color Sensor-is Mnishvneloba
//*/
//void PID_LineFollower_On_Until_Reflected(PID* pid, float _setpoint, bool rev)
//{
//	PID_LineFollower_Start(pid, rev); // Chavrtavt PID-s

//	if(_setpoint < getColorReflected(color2))
//	{
//		while(_setpoint < getColorReflected(color2)){} // Vamushavebt Sanam Sasurvel Reflected Measurement-s Ar Mivigebt
//	}

//	else
//	{
//		while(_setpoint > getColorReflected(color2)){} // Vamushavebt Sanam Sasurvel Reflected Measurement-s Ar Mivigebt
//	}

//	PID_LineFollower_Stop(); // Gamovrtavt PID-s
//}


/*
	LineFollower-is Chartva Sanam Color Sensor-it Sasurvel Reflected-s Ar Mivigebt

	@param [PID*] pid 						PID-is Pointer-i Romelsac Chavrtavt Sanam Sasurvel Mandzilze Ar Mivalt
	@param [float] _setpoint 			Sasurveli LineFollower-is Color Sensor-is Mnishvneloba
*/
void PID_LineFollower_On_Until_Reflected(PID* pid, float _setpoint, bool rev)
{
	PID_LineFollower_Start(pid, rev); // Chavrtavt PID-s

	if(_setpoint < getColorReflected(color1))
	{
		while(_setpoint < getColorReflected(color1)){} // Vamushavebt Sanam Sasurvel Reflected Measurement-s Ar Mivigebt
	}

	else
	{
		while(_setpoint > getColorReflected(color1)){} // Vamushavebt Sanam Sasurvel Reflected Measurement-s Ar Mivigebt
	}

	PID_LineFollower_Stop(); // Gamovrtavt PID-s
}
