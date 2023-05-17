void PID_FollowLine_Until_Reflected(PID* pid, float reflection, bool rev = true)
{
	PID_LineFollower_On_ForTime(pid, pid->lineCorrectionTime, rev);

	while(task_usage[0].use != none){}

	PID_LineFollower_On_Until_Reflected(pid, reflection, rev);
}

void PID_FollowLine_AndTurn(PID* pid_lineFollower, PID* gyro_rotate, PID* gyro_move, float reflection, float turn_angle, bool rev, int mode)
{
	PID_FollowLine_Until_Reflected(pid_lineFollower, reflection, rev);

	while(task_usage[0].use != none){}

	int w = getMotorEncoder(wheelR) + MmToEncoder(45);

	playSound(soundBlip);

	setMotorTarget(wheelL, w, 30);
	setMotorTarget(wheelR, w, 30);

	while(getMotorEncoder(wheelR) < w)
	{
		setMotorTarget(wheelL, w, 30);
		setMotorTarget(wheelR, w, 30);
		//playSound(soundBlip);
	}
	//PID_Gyro_On_Until_Encoder(gyro_move, getMotorEncoder(wheelL) + MmToEncoder(69));

	PID_Gyro_Rotate(gyro_rotate, 90);
}
