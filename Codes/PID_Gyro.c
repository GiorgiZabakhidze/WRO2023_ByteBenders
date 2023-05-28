/*
	Gyro-s PID-is Chartva Ragac Droit

	@param [PID*] pid							PID-is Pointeri Romelsac Chavrtavt Ragac Droit
	@param [float] time						Dro Ramden Xnit Chavrtavt
*/
void PID_Gyro_On_ForTime(PID* pid, float time, bool parallel = false)
{
	if(pid->oneSided)
	{
		PID_Gyro_OneSided_Start(pid, forTime, time);

		if(!parallel)
		{
			while(task_usage[2].use != none){}
		}
	}
	else
	{
		PID_Gyro_Start(pid, forTime, time); // Chavrtavt PID-s

		if(!parallel)
		{
			while(task_usage[1].use != none){}
		}
	}
}

/*
	Gyro-s PID-s Chartva Sanam Ragac Konkretuli Kutxit Ar Shevtrialdebit

	@param [PID*] pid 						PID-is Pointer-i Romelsac Chavrtavt Sanam Sasurvel Mandzilze Ar Mivalt
	@param [float] angle		 			Kutxe Romlitac Unda Shevtrialdet
*/
void PID_Gyro_Rotate(PID* pid, float angle, bool parallel = false)
{
	float initAngle = getGyroDegrees(gyro); // Vinaxavt Sawyis Kutxes

	pid->setpoint = initAngle + angle; // Setpointad Vutitebt Sawyiss + Sasurveli Shemotrialebis Kutxes

	if(pid->oneSided)
	{
		PID_Gyro_OneSided_Start(pid, on_untilDone, 0);

		if(!parallel)
		{
			while(task_usage[2].use != none){}
		}
	}
	else
	{
		PID_Gyro_Start(pid, on_untilDone, 0); // Chavrtavt PID-s

		if(!parallel)
		{
			while(task_usage[1].use != none){}
		}
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
void PID_Gyro_On_Until_Distance(PID* pid, float distance, bool oneSided, bool parallel = false)
{
	if(oneSided)
	{
		if(distance < getUSDistance(usonic))
		{
			PID_Gyro_OneSided_Start(pid, untilDistance_far, distance); // Chavrtavt PID-s
		}
		else
		{
			PID_Gyro_OneSided_Start(pid, untilDistance_close, distance); // Chavrtavt PID-s
		}

		if(!parallel)
		{
			while(task_usage[2].use != none){}
		}
	}
	else
	{
		if(distance < getUSDistance(usonic))
		{
			PID_Gyro_Start(pid, untilDistance_far, distance); // Chavrtavt PID-s
		}
		else
		{
			PID_Gyro_Start(pid, untilDistance_close, distance); // Chavrtavt PID-s
		}

		if(!parallel)
		{
			while(task_usage[1].use != none){}
		}
	}
}

/*
	Gyro-s PID-s Chartva Sanam Color Sensor-it Sasurvel Reflected-s Ar Mivigebt

	@param [PID*] pid 						PID-is Pointer-i Romelsac Chavrtavt Sanam Sasurvel Mandzilze Ar Mivalt
	@param [float] _setpoint 			Sasurveli LineFollower-is Color Sensor-is Mnishvneloba
*/
void PID_Gyro_On_Until_Reflected(PID* pid, float _setpoint, bool parallel = false)
{
	if(pid->oneSided)
	{
		if(_setpoint >= getColorReflected(color1))
		{
			PID_Gyro_OneSided_Start(pid, untilReflected_high, _setpoint);
		}
		else
		{
			PID_Gyro_OneSided_Start(pid, untilReflected_low, _setpoint);
		}

		if(!parallel)
		{
			while(task_usage[2].use != none){}
		}
	}
	else
	{
		if(_setpoint >= getColorReflected(color1))
		{
			PID_Gyro_Start(pid, untilReflected_high, _setpoint);
		}
		else
		{
			PID_Gyro_Start(pid, untilReflected_low, _setpoint);
		}

		if(!parallel)
		{
			while(task_usage[1].use != none){}
		}
	}
}

void PID_Gyro_On_Until_Encoder(PID* pid, float _setpoint, bool parallel = false)
{
	if(pid->oneSided)
	{
		if(_setpoint >= getMotorEncoder(wheelR))
		{
			PID_Gyro_OneSided_Start(pid, untilEncoder_high, _setpoint);
		}
		else
		{
			PID_Gyro_OneSided_Start(pid, untilEncoder_low, _setpoint);
		}

		if(!parallel)
		{
			while(task_usage[2].use != none){}
		}
	}
	else
	{
		if(_setpoint >= getMotorEncoder(wheelR))
		{
			PID_Gyro_Start(pid, untilEncoder_high, _setpoint);
		}
		else
		{
			PID_Gyro_Start(pid, untilEncoder_low, _setpoint);
		}

		if(!parallel)
		{
			while(task_usage[1].use != none){}
		}
	}
}
