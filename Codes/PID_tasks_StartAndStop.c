/*
	Nebismieri PID-s Gamoyeneba Romelic Akontrolebs Borblebs Color Sensorit.

	@param [PID*] pid  					PID-s Pointer-i Romelis Gamoyenebac Gvinda
	@param [bool] rev   				Marjvnidan Udgeba Gzas Tu Marcxnidan
	@param [float] setpoint 		Color Senosor-is Sasurveli Mnishvneloba
*/
void PID_LineFollower_Start(PID* pid, bool rev)
{
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
	@param [bool] rev   				Marjvnidan Udgeba Gzas Tu Marcxnidan
	@param [float] setpoint 		Gyro-s Sasurveli Mnishvneloba
*/
void PID_Gyro_Start(PID* pid)
{
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
