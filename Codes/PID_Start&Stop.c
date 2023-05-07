/*
	Nebismieri PID-s Gamoyeneba Romelic Akontrolebs Borblebs Color Sensorit.

	@param [PID*] pid  					PID-s Pointer-i Romelis Gamoyenebac Gvinda
	@param [bool] rev   				Marjvnidan Udgeba Gzas Tu Marcxnidan
	@param [float] setpoint 		Color Senosor-is Sasurveli Mnishvneloba
*/
void PID_LineFollower_Start(PID* pid, bool rev)
{
	// Vanulebt PID-s Cvladebs
	PID_resetVariables(pid);

	// Vaniwebt Globalur Cvladebs Shesabamis Mnishvnelobebs
	tasks[0] = pid;

	// Rev Gadmogvaqvs Bool-idan Int-shi
	if(rev)
		task_rev = 1;
	else
		task_rev = -1;

	task_using[0] = true;
}


/*
	Nebismieri PID-s Gamoyenebis Shechereba Romelic Akontrolebs Borblebs Color Sensorit.

	@param [PID*] pid 			PID-s Pointer-i Romlis Mushaobis Gacherebac Gvinda
*/
void PID_LineFollower_Stop()
{
	// Ubralod Vacherebt Task-s
	task_using[1] = false;
}


/*
	Nebismieri PID-s Gamoyeneba Romelic Akontrolebs Borblebs Gyro-ze Dayrdnobit.

	@param [PID*] pid  					PID-s Pointer-i Romelis Gamoyenebac Gvinda
	@param [float] setpoint 		Gyro-s Sasurveli Mnishvneloba
*/
void PID_Gyro_Start(PID* pid)
{
	// Vanulebt PID-s Cvladebs
	PID_resetVariables(pid);

	// Vaniwebt Globalur Cvladebs Shesabamis Mnishvnelobebs
	tasks[1] = pid;

	// Viwyebt Task-s
	task_using[1] = true;
}


/*
	Nebismieri PID-s Gamoyenebis Shechereba Romelic Akontrolebs Borblebs Gyro-ze Dayrdnobit.

	@param [PID*] pid 			PID-s Pointer-i Romlis Mushaobis Gacherebac Gvinda
*/
void PID_Gyro_Stop()
{
	// Ubralod Vacherebt Task-s
	task_using[1] = false;
}


/*
	Nebismieri PID-s Gamoyeneba Romelic Akontrolebs Borblebs Gyro-ze Dayrdnobit.

	@param [PID*] pid  					PID-s Pointer-i Romelis Gamoyenebac Gvinda
	@param [float] setpoint 		Gyro-s Sasurveli Mnishvneloba
*/
void PID_Gyro_oneSided_Start(PID* pid)
{
	// Vanulebt PID-s Cvladebs
	PID_resetVariables(pid);

	// Vaniwebt Globalur Cvladebs Shesabamis Mnishvnelobebs
	tasks[2] = pid;

	// Viwyebt Task-s
	task_using[2] = true;
}


/*
	Nebismieri PID-s Gamoyenebis Shechereba Romelic Akontrolebs Borblebs Gyro-ze Dayrdnobit.

	@param [PID*] pid 			PID-s Pointer-i Romlis Mushaobis Gacherebac Gvinda
*/
void PID_Gyro_oneSided_Stop()
{
	// Ubralod Vacherebt Task-s
	task_using[2] = false;
}


/*
	Nebismieri PID-s Gamoyeneba Romelic Akontrolebs Xels Misi Motor-is Encoder-ze Dayrdnobit.

	@param [PID*] pid  					PID-s Pointer-i Romelis Gamoyenebac Gvinda
	@param [float] setpoint 		Encoder-is Sasurveli Mnishvneloba
*/
void PID_Hand_Start(PID* pid)
{
	// Vanulebt PID-s Cvladebs
	PID_resetVariables(pid);

	// Vaniwebt Globalur Cvladebs Shesabamis Mnishvnelobebs
	tasks[3] = pid;

	// Viwyebt Task-s
	task_using[3] = true;
}


/*
	Nebismieri PID-s Gamoyenebis Shechereba Romelic Akontrolebs Xels Misi Motor-is Encoder-ze Dayrdnobit.

	@param [PID*] pid 			PID-s Pointer-i Romlis Mushaobis Gacherebac Gvinda
*/
void PID_Hand_Stop()
{
	// Ubralod Vacherebt Task-s
	task_using[3] = false;
}


/*
	Nebismieri PID-s Gamoyeneba Romelic Akontrolebs Claw-s Misi Motor-is Encoder-ze Dayrdnobit.

	@param [PID*] pid  					PID-s Pointer-i Romelis Gamoyenebac Gvinda
	@param [float] setpoint 		Encoder-is Sasurveli Mnishvneloba
*/
void PID_Claw_Start(PID* pid)
{
	// Vanulebt PID-s Cvladebs
	PID_resetVariables(pid);

	// Vaniwebt Globalur Cvladebs Shesabamis Mnishvnelobebs
	tasks[4] = pid;

	// Viwyebt Task-s
	task_using[4] = true;
}


/*
	Nebismieri PID-s Gamoyenebis Shechereba Romelic Akontrolebs Claw-s Misi Motor-is Encoder-ze Dayrdnobit.

	@param [PID*] pid 			PID-s Pointer-i Romlis Mushaobis Gacherebac Gvinda
*/
void PID_Claw_Stop()
{
	// Ubralod Vacherebt Task-s
	task_using[4] = false;
}
