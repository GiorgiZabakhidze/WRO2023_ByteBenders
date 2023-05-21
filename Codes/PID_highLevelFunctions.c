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
	setHandUp(-50);

	clawOpened(false);

	playSound(soundBlip);
}

void Block_PickUp()
{
	Block_Grab();

	setHandUp(50);
}

void Block_PlaceDown()
{
	setHandUp(-50);

	clawOpened(true);

	handUp(50);
}

void Block_PlaceOnTheShip()
{
	setHandUp(-30);

	clawOpened(true);

	handUp(30);
}

void takeFirstBlockInCage(PID* gyro_mover)
{
	float MmAfterFirstBlock;

	float MmBetweenBlocks;

	int firstBlock = -1;

	for(int i = 0; i < 4; i++)
	{
		if(robotBlocks[0] != 0)
		{
			firstBlock = i;

			robotBlocks[0] = 0;
		}
	}

	gyro_mover->setpoint = getGyroDegrees(gyro);

	float curr = getMotorEncoder(wheelR);

	float target = curr + MmAfterFirstBlock + (firstBlock - 1) * MmBetweenBlocks;

	PID_Gyro_On_Until_Encoder(Gyro_mover, target);

	while(task_usage[1].use != none){}
}
