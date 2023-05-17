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

	playSound(soundBlip);

	gyro_move->setpoint = getGyroDegrees(gyro);

	wait(2000);

	if(mode == 1)
	{
		PID_Gyro_On_Until_Encoder(gyro_move, getMotorEncoder(wheelR) + MmToEncoder(22.5));
	}
	else
	{
		PID_Gyro_On_Until_Encoder(gyro_move, getMotorEncoder(wheelR) + MmToEncoder(26.5));
	}
	while(task_usage[1].use != none){}

	playSound(soundBlip);

	wait(2000);

	PID_Gyro_Rotate(gyro_rotate, turn_angle);

	while(task_usage[1].use != none){}
}

void Block_Grab()
{
	int init = getMotorEncoder(hand);
	moveHand(-50);

	while(!inRange(getMotorEncoder(hand), init + 50, 2)){}

	moveClaw(false);

	playSound(soundBlip);
}

void Block_PickUp()
{
	Block_Grab();

	moveHand(50);

	int init = getMotorEncoder(hand);

	while(!inRange(getMotorEncoder(hand), init - 50, 2)){}

}

void Block_MoveDown()
{
	int init = getMotorEncoder(hand);

	moveHand(-30);

	while(!inRange(getMotorEncoder(hand), init + 30, 2)){}

	moveClaw(true);

	moveHand(30);
}
