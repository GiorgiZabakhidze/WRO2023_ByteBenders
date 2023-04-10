/*
	Nebismieri PID-s Gamoyeneba Romelic Akontrolebs Borblebs Color Sensorit.

	@param [PID*] pid  					PID-s Pointer-i Romelis Gamoyenebac Gvinda
	@param [bool] rev   				Marjvnidan Udgeba Gzas Tu Marcxnidan
	@param [float] setpoint 		Color Senosor-is Sasurveli Mnishvneloba
*/
void PID_LineFollower_Start(PID* pid, float setpoint, bool rev)
{
	// Vaniwebt Globalur Cvladebs Shesabamis Mnishvnelobebs
	tasks[0] = pid;

	// Vcvlit Globalur Setpoints Am Tipis PID-stvis
	task_setpoint[0] = setpoint;

	// Rev Gadmogvaqvs Bool-idan Int-shi
	if(rev)
		task_rev[0] = 1;
	else
		task_rev[0] = -1;

	// Viwyebt Task-s
	startTask(PID_LineFollower);
}


/*
	Nebismieri PID-s Gamoyenebis Shechereba Romelic Akontrolebs Borblebs Color Sensorit.

	@param [PID*] pid 			PID-s Pointer-i Romlis Mushaobis Gacherebac Gvinda
*/
void PID_LineFollower_Stop()
{
	// Ubralod Vacherebt Task-s
	stopTask(PID_LineFollower);
}


/*
	Nebismieri PID-s Gamoyeneba Romelic Akontrolebs Borblebs Gyro-ze Dayrdnobit.

	@param [PID*] pid  					PID-s Pointer-i Romelis Gamoyenebac Gvinda
	@param [bool] rev   				Marjvnidan Udgeba Gzas Tu Marcxnidan
	@param [float] setpoint 		Gyro-s Sasurveli Mnishvneloba
*/
void PID_Gyro_Start(PID* pid, float setpoint)
{
	// Vaniwebt Globalur Cvladebs Shesabamis Mnishvnelobebs
	tasks[1] = pid;

	// Vcvlit Globalur Setpoints Am Tipis PID-stvis
	task_setpoint[1] = setpoint;

	// Viwyebt Task-s
	startTask(PID_Gyro);
}


/*
	Nebismieri PID-s Gamoyenebis Shechereba Romelic Akontrolebs Borblebs Gyro-ze Dayrdnobit.

	@param [PID*] pid 			PID-s Pointer-i Romlis Mushaobis Gacherebac Gvinda
*/
void PID_Gyro_Stop()
{
	// Ubralod Vacherebt Task-s
	stopTask(PID_Gyro);
}
