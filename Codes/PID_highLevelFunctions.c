void PID_FollowLine_Until_Reflected(PID* pid_lineFollower_slow, PID* pid_gyro, float reflection = 40, bool rev = 1)
{
	PID_LineFollower_On_ForTime(pid_lineFollower_slow, lineCorrectionTime, rev);

	PID_Gyro_On_Until_Reflected(pid_gyro, reflection);
}

void PID_FollowLine_AndTurn(PID* pid_lineFollower_slow, PID* pid_gyro, float reflection = 40, float turn_angle = 90, bool rev = 1)
{
	PID_FollowLine_Until_Reflected(pid_lineFollower_slow, pid_gyro, reflection, rev);

	PID_Gyro_Rotate(pid_gyro, turn_angle);
}
