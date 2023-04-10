/*
	PID LineFollower-is Chartva Ragac Paqtoris Mixedvit

	@param [PID*] pid							PID-is Pointeri Romelic Gveqneba Chartuli
	@param [bool*] factor					Paqtoris Pointer-i Romelzedacaa Damokidebuli Chartuli Iqneba Tu Ara(true=Chartuli, false=Gamortuli)
	@param [float] setpoint				Sasurveli Sensor-is Mnishvneloba
	@param [bool] rev 						Marjvena Mxridan Mivyvebit Xazs Tu Marcxena(Marjvena=true, Marcxena=false)
*/
void PID_LineFollower_On_Until(PID* pid, bool* factor, float setpoint, bool rev)
{
	PID_LineFollower_Start(pid, rev, setpoint); // Chavrtavt Line Follower-s

	while(factor){} // Arapers Vaketebt Sanam Factor Aris True

	PID_LineFollower_Stop(); // Roca Gaxdeba False, Gamovrtavt Line Follower-s
}


/*
	PID Line Follwer-is Chartva Ragac Droit

	@param [PID*] pid							PID-is Pointer-i Romelsac Chavrtavt Ragac Droit
	@param [float] time						Dro Ramden Xnit Chavrtavt
	@param [float] setpoint				Sasurveli Color Sensor-is Mnishvneloba
	@param [bool] rev 						Marjvena Mxridan Mivyvebit Xazs Tu Marcxena(Marjvena=true, Marcxena=false)
*/
void PID_LineFollower_On_ForTime(PID* pid, float time, float setpoint, bool rev)
{
	PID_LineFollower_Start(pid, setpoint, rev); // Chavrtavt PID-s

	wait(time); // Vicdit Sasurveli Dro

	PID_LineFollower_Stop(); // Gamovrtavt PID-s
}


/*
	PID Line Follower-is Chartva Sanam Ultra Sonic-it Konkretul Distanciamde Ar Mivalt

	@param [PID*] pid 						PID-is Pointer-i Romelsac Chavrtavt Sanam Sasurvel Mandzilze Ar Mivalt
	@param [float] distance 			Mandzili Romelic Unda Achvenos Ultra Sonic-ma
	@param [float] setpoint				Sasurveli Color Sensor-is Mnishvneloba
	@param [bool]	rev 						Marjvena Mxridan Mivyvebit Xazs Tu Marcxena(Marjvena=true, Marcxena=false)
*/
void PID_LineFollower_On_Until_Distance(PID* pid, float distance, float setpoint, bool rev)
{
	PID_LineFollower_Start(pid, setpoint, rev); // Chavrtavt PID-s

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
	PID Gyro-is Chartva Ragac Paqtoris Mixedvit

	@param [PID*] pid							PID-is Pointeri Romelic Gveqneba Chartuli
	@param [bool*] factor					Paqtoris Pointer-i Romelzedacaa Damokidebuli Chartuli Iqneba Tu Ara(true=Chartuli, false=Gamortuli)
	@param [float] setpoint				Sasurveli Sensor-is Mnishvneloba
	@param [bool] rev 						Marjvena Mxridan Mivyvebit Xazs Tu Marcxena(Marjvena=true, Marcxena=false)
*/
void PID_Gyro_On_Until(PID* pid, bool* factor, float setpoint)
{
	PID_Gyro_Start(pid, setpoint); // Chavrtavt Gyro-s PID-s

	while(factor){} // Arapers Vaketebt Sanam Factor Aris True

	PID_Gyro_Stop(); // Roca Gaxdeba False, Gamovrtavt Line Follower-s
}


/*
	Gyro-s PID-is Chartva Ragac Droit

	@param [PID*] pid							PID-is Pointeri Romelsac Chavrtavt Ragac Droit
	@param [float] time						Dro Ramden Xnit Chavrtavt
	@param [float] setpoint				Sasurveli Sensor-is Mnishvneloba
	@param [bool] rev 						Marjvena Mxridan Mivyvebit Xazs Tu Marcxena(Marjvena=true, Marcxena=false)
*/
void PID_Gyro_On_ForTime(PID* pid, float time, float setpoint)
{
	PID_Gyro_Start(pid, setpoint); // Chavrtavt PID-s

	wait(time); // Davicdit Sanam Sasurveli Dro Ar Gava

	PID_Gyro_Stop(); // Gamovrtavt PID-s
}


/*
	Gyro-s PID-s Chartva Sanam Ultra Sonic-it Konkretul Distanciamde Ar Mivalt

	@param [PID*] pid 						PID-is Pointer-i Romelsac Chavrtavt Sanam Sasurvel Mandzilze Ar Mivalt
	@param [float] distance 			Mandzili Romelic Unda Achvenos Ultra Sonic-ma
	@param [float] setpoint				Sasurveli Gyro-s Mnishvneloba
*/
void PID_Gyro_On_Until_Distance(PID* pid, float distance, float setpoint)
{
	PID_Gyro_Start(pid, setpoint); // Chavrtavt PID-s

	while(distance > getUSDistance(usonic)){} // Sanam Distancia Metia Vidre Gvinda Rom Iyos, Mivdivart Win

	// Vrtavt Ukan Wasvlis Modshi
	pid->moveSpeed *= -1;

	while(distance < getUSDistance(usonic)){} // Sanam Distancia Naklebia Vidre Gvinda Rom Iyos, Mivdivart ukan

	// Vabrunebt Chveulebriv Modshi
	pid->moveSpeed *= -1;

	PID_Gyro_Stop(); // Gamovrtavt PID-s
}

/*
	Gyro-s PID-s Chartva Sanam Ultra Sonic-it Konkretul Distanciamde Ar Mivalt

	@param [PID*] pid 						PID-is Pointer-i Romelsac Chavrtavt Sanam Sasurvel Mandzilze Ar Mivalt
	@param [float] _setpoint 			Sasurveli LineFollower-is Color Sensor-is Mnishvneloba
	@param [float] setpoint				Sasurveli Gyro-s Mnishvneloba=
*/
void PID_Gyro_On_Until_Reflected(PID* pid, float _setpoint, float setpoint)
{
	PID_Gyro_Start(pid, setpoint); // Chavrtavt PID-s

	while(_setpoint != getColorReflected(color1)){} // Vamushavebt Sanam Sasurvel Reflected Measurement-s Ar Mivigebt

	PID_Gyro_Start(pid, setpoint); // Gamovrtavt PID-s
}
