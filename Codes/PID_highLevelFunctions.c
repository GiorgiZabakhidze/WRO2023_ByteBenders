void PID_FollowLine_Until_Reflected(PID* pid, float reflection = 40, bool rev = true)
{
	PID_LineFollower_On_ForTime(pid, pid->lineCorrectionTime, rev);

	while(task_usage[0].use != none){}

	PID_LineFollower_On_Until_Reflected(pid, reflection, rev);
}

void PID_FollowLine_AndTurn(PID* pid_lineFollower, PID* pid_gyro, float reflection, float turn_angle, bool rev, int mode)
{
	PID_FollowLine_Until_Reflected(pid_lineFollower, reflection, rev);

	while(task_usage[0].use != none){}

	moveByBit(mode);

	PID_Gyro_Rotate(pid_gyro, turn_angle);
}
