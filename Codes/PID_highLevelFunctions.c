void PID_FollowLine_Until_Reflected(PID* pid, PID* pid_gyro, float reflection = 40, bool rev = 1)
{
	PID_LineFollower_On_ForTime(pid, pid->lineCorrectionTime, rev);

	PID_Gyro_On_Until_Reflected(pid_gyro, reflection);
}

void PID_FollowLine_AndTurn(PID* pid_lineFollower_slow, PID* pid_gyro, float reflection = 40, float turn_angle = 90, bool rev = 1)
{
	PID_FollowLine_Until_Reflected(pid_lineFollower_slow, pid_gyro, reflection, rev);

	PID_Gyro_Rotate(pid_gyro, turn_angle);
}
void PID_FollowLine_AndTurn1(PID* pid_lineFollower, PID* pid_gyro, float reflection = 40, float turn_angle = 90, bool rev = 1)
{
	PID_LineFollower_On_Until_Reflected(pid_lineFollower, reflection, rev);

	PID_Gyro_Rotate(pid_gyro, turn_angle);
}
