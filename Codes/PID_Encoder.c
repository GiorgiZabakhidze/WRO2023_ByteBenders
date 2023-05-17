/*
	PID Line Follwer-is Chartva Ragac Droit

	@param [PID*] pid							PID-is Pointer-i Romelsac Chavrtavt Ragac Droit
	@param [float] time						Dro Ramden Xnit Chavrtavt
	@param [bool] rev 						Marjvena Mxridan Mivyvebit Xazs Tu Marcxena(Marjvena=true, Marcxena=false)
*/
void PID_Encoder_On_ForTime(PID* pid, float time)
{
	PID_Encoder_Start(pid, forTime, (int)time); // Chavrtavt PID-s
}


/*
	LineFollower-is Chartva Sanam Color Sensor-it Sasurvel Reflected-s Ar Mivigebt

	@param [PID*] pid 						PID-is Pointer-i Romelsac Chavrtavt Sanam Sasurvel Mandzilze Ar Mivalt
	@param [float] _setpoint 			Sasurveli LineFollower-is Color Sensor-is Mnishvneloba
*/
void PID_Encoder_On_Until_Reflected(PID* pid, float _setpoint)
{
	if(_setpoint >= getColorReflected(color1))
	{
		PID_Encoder_Start(pid, untilReflected_high, _setpoint);
	}
	else
	{
		PID_Encoder_Start(pid, untilReflected_low, _setpoint);
	}
}

void PID_Encoder_On_Until_Encoder(PID* pid, float _setpoint)
{
	if(_setpoint >= getMotorEncoder(wheelR))
	{
		PID_Gyro_Start(pid, untilEncoder_high, _setpoint);
	}
	else
	{
		PID_Gyro_Start(pid, untilEncoder_low, _setpoint);
	}
}
