/*
	PID Line Follwer-is Chartva Ragac Droit

	@param [PID*] pid							PID-is Pointeri Romelsac Chavrtavt Ragac Droit
	@param [float] time						Dro Ramden Xnit Chavrtavt
	@param [float] setpoint				Sasurveli Sensor-is Mnishvneloba
	@param [bool] rev 						Marjvena Mxridan Mivyvebit Xazs Tu Marcxena(Marjvena=true, Marcxena=false)
*/
void PID_LineFollower_On_ForTime(PID* pid, float time, float setpoint=45, bool rev=1)
{
	// Viwyebt Line Follower-s
	PID_LineFollower_Start(pid, rev, setpoint);

	// Vqmnit Cvlads Gasuli Drois Shesanaxad
	float t = 0;

	// Vqmnit Cvlads Rom gavidot Rodis Daviwet Line Follower-is Mushaoba
	float start_time = time1(T1);

	// Mushaobs Sanam Gasuli Dro Naklebia Sasurvel Droze
	while(t < time)
	{
		// Vanaxlebt Gasul Dros
		t = timer_count(start_time, time1(T1));
	}

	// Vacherebt Line Follower-s
	PID_LineFollower_Stop(pid);
}


/*
	PID Line Follwer-is Chartva Ragac Paqtoris Mixedvit

	@param [PID*] pid							PID-is Pointeri Romelic Gveqneba Chartuli
	@param [bool*] factor					Paqtoris Pointer-i Romelzedacaa Damokidebuli Chartuli Iqneba Tu Ara(true=Chartuli, false=Gamortuli)
	@param [float] setpoint				Sasurveli Sensor-is Mnishvneloba
	@param [bool] rev 						Marjvena Mxridan Mivyvebit Xazs Tu Marcxena(Marjvena=true, Marcxena=false)
*/
void PID_LineFollower_On_Until(PID* pid, bool* factor, float setpoint=45, bool rev=1)
{
	// Viwyebt Line Follower-s
	PID_LineFollower_Start(pid, rev, setpoint);

	// Sanam Paqtori Aris True, Manamde Arapers Ar Vaketebt
	while((*factor)){}

	// Roca Paqtori Gaxdeba False, Gamovrtavt Line Follower-s
	PID_LineFollower_Stop(pid);
}


/*
	PID Gyro-s PID-s Chartva Ragac Droit

	@param [PID*] pid							PID-is Pointeri Romelsac Chavrtavt Ragac Droit
	@param [float] time						Dro Ramden Xnit Chavrtavt
	@param [float] setpoint				Gyro-s Mnishvneloba
*/
void PID_Gyro_On_ForTime(PID* pid, float time, float setpoint=0)
{
	PID_Gyro_Start(pid, setpoint);

	float t = 0;

	float start_time = time1(T1);

	while(t < time)
	{
		t = timer_count(start_time, time1(T1));
	}

	PID_Gyro_Stop(pid);
}


/*
	PID Line Follwer-is Chartva Ragac Paqtoris Mixedvit

	@param [PID*] pid							PID-is Pointeri Romelic Gveqneba Chartuli
	@param [bool*] factor					Paqtoris Pointer-i Romelzedacaa Damokidebuli Chartuli Iqneba Tu Ara(true=Chartuli, false=Gamortuli)
	@param [float] setpoint				Sasurveli Sensor-is Mnishvneloba
	@param [bool] rev 						Marjvena Mxridan Mivyvebit Xazs Tu Marcxena(Marjvena=true, Marcxena=false)
*/
void PID_Gyro_On_Until(PID* pid, bool* factor, float setpoint=0)
{
	PID_Gyro_Start(pid, setpoint);

	while((*factor)){}

	PID_Gyro_Stop(pid);
}
