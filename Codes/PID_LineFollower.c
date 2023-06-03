/*
	PID Line Follwer-is Chartva Ragac Droit

	@param [PID*] pid							PID-is Pointer-i Romelsac Chavrtavt Ragac Droit
	@param [float] time						Dro Ramden Xnit Chavrtavt
	@param [bool] rev 						Marjvena Mxridan Mivyvebit Xazs Tu Marcxena(Marjvena=true, Marcxena=false)
*/
void PID_LineFollower_On_ForTime(PID* pid, float time, bool parallel = false)
{
	PID_LineFollower_Start(pid, forTime, (int)time); // Chavrtavt PID-s

	if(!parallel)
	{
		while(task_usage[0].use != none){}
	}
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
void PID_LineFollower_On_Until_Distance(PID* pid, float distance, bool parallel = false)
{
	if(distance < getUSDistance(usonic))
	{
		PID_LineFollower_Start(pid, untilDistance_far, distance); // Chavrtavt PID-s
	}
	else
	{
		PID_LineFollower_Start(pid, untilDistance_close, distance); // Chavrtavt PID-s
	}

	if(!parallel)
	{
		while(task_usage[0].use != none){}
	}
}


/*
	LineFollower-is Chartva Sanam Color Sensor-it Sasurvel Reflected-s Ar Mivigebt

	@param [PID*] pid 						PID-is Pointer-i Romelsac Chavrtavt Sanam Sasurvel Mandzilze Ar Mivalt
	@param [float] _setpoint 			Sasurveli LineFollower-is Color Sensor-is Mnishvneloba
*/
void PID_LineFollower_On_Until_Reflected(PID* pid, float _setpoint, bool parallel = false)
{
	if(_setpoint >= getColorReflected(color1))
	{
		PID_LineFollower_Start(pid, untilReflected_high, _setpoint);
	}
	else
	{
		PID_LineFollower_Start(pid, untilReflected_low, _setpoint);
	}

	if(!parallel)
	{
		while(task_usage[0].use != none){}
	}
}

void PID_LineFollower_On_Until_Encoder(PID* pid, float _setpoint, bool parallel = false)
{
	if(_setpoint >= getMotorEncoder(wheelL))
	{
		PID_LineFollower_Start(pid, untilEncoder_high, _setpoint);
	}

	else
	{
		PID_LineFollower_Start(pid, untilEncoder_low, _setpoint);
	}

	if(!parallel)
	{
		while(task_usage[0].use != none){}
	}
}
