/*
	PID Line Follwer-is Chartva Ragac Droit

	@param [PID*] pid							PID-is Pointer-i Romelsac Chavrtavt Ragac Droit
	@param [float] time						Dro Ramden Xnit Chavrtavt
	@param [bool] rev 						Marjvena Mxridan Mivyvebit Xazs Tu Marcxena(Marjvena=true, Marcxena=false)
*/
void PID_LineFollower_On_ForTime(PID* pid, float time, bool rev = true)
{
	PID_LineFollower_Start(pid, forTime, (int)time, rev); // Chavrtavt PID-s
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
void PID_LineFollower_On_Until_Distance(PID* pid, float distance, bool rev = true)
{
	if(distance < getUSDistance(usonic))
	{
		PID_LineFollower_Start(pid, untilDistance_far, distance, rev); // Chavrtavt PID-s
	}
	else
	{
		PID_LineFollower_Start(pid, untilDistance_close, distance, rev); // Chavrtavt PID-s
	}

}


/*
	LineFollower-is Chartva Sanam Color Sensor-it Sasurvel Reflected-s Ar Mivigebt

	@param [PID*] pid 						PID-is Pointer-i Romelsac Chavrtavt Sanam Sasurvel Mandzilze Ar Mivalt
	@param [float] _setpoint 			Sasurveli LineFollower-is Color Sensor-is Mnishvneloba
*/
void PID_LineFollower_On_Until_Reflected(PID* pid, float _setpoint, bool rev = true)
{
	if(_setpoint >= getColorReflected(color1))
	{
		PID_LineFollower_Start(pid, untilReflected_high, _setpoint, rev);
	}
	else
	{
		PID_LineFollower_Start(pid, untilReflected_low, _setpoint, rev);
	}
}
