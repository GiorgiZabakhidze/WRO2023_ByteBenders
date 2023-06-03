/*
	PID Line Follwer-is Chartva Ragac Droit

	@param [PID*] pid							PID-is Pointer-i Romelsac Chavrtavt Ragac Droit
	@param [float] time						Dro Ramden Xnit Chavrtavt
	@param [bool] rev 						Marjvena Mxridan Mivyvebit Xazs Tu Marcxena(Marjvena=true, Marcxena=false)
*/
void PID_Encoder_On_ForTime(PID* pid, float time, bool parallel = false)
{
	PID_Encoder_Start(pid, forTime, (int)time); // Chavrtavt PID-s

	if(!parallel)
	{
		while(task_usage[2].use != none){}
	}
}


/*
	LineFollower-is Chartva Sanam Color Sensor-it Sasurvel Reflected-s Ar Mivigebt

	@param [PID*] pid 						PID-is Pointer-i Romelsac Chavrtavt Sanam Sasurvel Mandzilze Ar Mivalt
	@param [float] _setpoint 			Sasurveli LineFollower-is Color Sensor-is Mnishvneloba
*/
void PID_Encoder_On_Until_Reflected(PID* pid, float _setpoint, bool parallel = false)
{
	if(_setpoint >= getColorReflected(color1))
	{
		PID_Encoder_Start(pid, untilReflected_high, _setpoint);
	}
	else
	{
		PID_Encoder_Start(pid, untilReflected_low, _setpoint);
	}

	if(!parallel)
	{
		while(task_usage[2].use != none){}
	}
}

void PID_Encoder_On_Until_Encoder(PID* pid, float _setpoint, bool parallel = false)
{
	if(_setpoint >= -getMotorEncoder(wheelL))
	{
		PID_Gyro_Start(pid, untilEncoder_high, _setpoint);
	}
	else
	{
		PID_Gyro_Start(pid, untilEncoder_low, _setpoint);
	}

	if(!parallel)
	{
		while(task_usage[2].use != none){}
	}
}

void PID_Encoder_Rotate(PID* pid, float deg, bool parallel = false)
{
	float initDelta = getMotorEncoder(wheelR) + getMotorEncoder(wheelL);

	float target = initDelta + DegToDeltaEncoder(deg);

	pid->setpoint = target;

	PID_Encoder_Start(pid, on_untilDone, target);

	if(!parallel)
	{
		while(task_usage[2].use != none){}
	}
}
