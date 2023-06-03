/*
	Nebismieri PID-s Gamoyeneba Romelic Akontrolebs Borblebs Color Sensorit.

	@param [PID*] pid  					PID-s Pointer-i Romelis Gamoyenebac Gvinda
	@param [bool] rev   				Marjvnidan Udgeba Gzas Tu Marcxnidan
	@param [float] setpoint 		Color Senosor-is Sasurveli Mnishvneloba
*/
void PID_LineFollower_Start(PID* pid, useType use, float coefficient)
{
	// Vanulebt PID-s Cvladebs Tu Aqamde Sxva PID-s Viyenebdit An Ar Viyenebdit Arapers
	if(previouslyUsedPID == NULL || previouslyUsedPID != pid)
	{
		PID_resetVariables(pid);
	}

	previouslyUsedPID = pid;

	// Vaniwebt Globalur Cvladebs Shesabamis Mnishvnelobebs
	tasks[0] = pid;

	task_usage[0].motorN = 3;

	setUsage(0, use, coefficient, LineFollower);
}


/*
	Nebismieri PID-s Gamoyeneba Romelic Akontrolebs Borblebs Gyro-ze Dayrdnobit.

	@param [PID*] pid  					PID-s Pointer-i Romelis Gamoyenebac Gvinda
	@param [float] setpoint 		Gyro-s Sasurveli Mnishvneloba
*/
void PID_Gyro_Start(PID* pid, useType use, float coefficient)
{
	// Vanulebt PID-s Cvladebs Tu Aqamde Sxva PID-s Viyenebdit An Ar Viyenebdit Arapers
	if(previouslyUsedPID == NULL || previouslyUsedPID != pid)
	{
		PID_resetVariables(pid);
	}

	previouslyUsedPID = pid;

	// Vaniwebt Globalur Cvladebs Shesabamis Mnishvnelobebs
	tasks[1] = pid;

	task_usage[1].motorN = 3;

	setUsage(1, use, coefficient, Gyro);
}

void PID_Encoder_Start(PID* pid, useType use, float _setpoint)
{
	// Vanulebt PID-s Cvladebs Tu Aqamde Sxva PID-s Viyenebdit An Ar Viyenebdit Arapers
	if(previouslyUsedPID == NULL || previouslyUsedPID != pid)
	{
		PID_resetVariables(pid);
	}

	previouslyUsedPID = pid;

	// Vaniwebt Globalur Cvladebs Shesabamis Mnishvnelobebs
	tasks[2] = pid;

	task_usage[2].motorN = 3;

	setUsage(2, use, _setpoint, Encoder);
}
