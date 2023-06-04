void PID_FollowLine_Until_Reflected(PID* pid, float reflection)
{
	PID_LineFollower_On_ForTime(pid, pid->lineCorrectionTime);

	playSound(soundLowBuzz);

	PID_LineFollower_On_Until_Reflected(pid, reflection);
}

void PID_FollowLine_AndTurn(PID* pid_lineFollower, PID* gyro_rotate, PID* gyro_move, float reflection, float turn_angle, int mode)
{
	PID_FollowLine_Until_Reflected(pid_lineFollower, reflection);

	playSound(soundBlip);

	gyro_move->setpoint = getGyroDegrees(gyro);

	if(mode == 1)
	{
		PID_Gyro_On_Until_Encoder(Gyro_move, getMotorEncoder(wheelL) - MmToEncoder(22.5));
	}
	else
	{
		PID_Gyro_On_Until_Encoder(Gyro_move, getMotorEncoder(wheelL) - MmToEncoder(26.5));
	}
	while(task_usage[1].use != none){}

	playSound(soundBlip);

	PID_Gyro_Rotate(gyro_rotate, turn_angle);

	while(task_usage[1].use != none){}
}

void Block_Grab()
{
	setHandUp(-65);

	clawOpened(false);

	playSound(soundBlip);
}

void Block_PickUp()
{
	Block_Grab();

	setHandUp(-10);
}

void Block_PlaceDown()
{
	setHandUp(-60);

	clawOpened(true);

	handUp(-10);
}

void Block_PlaceOnTheShip()
{
	setHandUp(-50);

	clawOpened(true);

	handUp(-10);
}

int takeFirstBlockInCage(PID* Encoder_mover)
{
	float MmAfterFirstBlock = 80;

	float MmBetweenBlocks = 32;

	int firstBlock;

	for(int i = 1; i < 4; i++)
	{
		if(robotBlocks[i] != 0)
		{
			firstBlock = i;

			robotBlocks[i] = 0;

			break;
		}
	}

	Encoder_mover->moveSpeed = -abs(Encoder_mover->moveSpeed);

	Encoder_mover->setpoint = getMotorEncoder(wheelR) + getMotorEncoder(wheelL);

	float curr = getMotorEncoder(wheelL);

	wait(10);

	float target = curr + MmToEncoder(MmAfterFirstBlock) + MmToEncoder((firstBlock - 1) * MmBetweenBlocks);

	displayBigTextLine(1, "%d", target);

	displayBigTextLine(3, "%d", curr);

	PID_Encoder_On_Until_Encoder(Encoder_mover, target);

	Block_PickUp();

	return target - curr;
}

void parallelMovement(float dis)
{
	float r = 16;
	float angle = acos( 1 - abs(dis) / r );
	float deltaForward = r * sin(angle);

	Gyro_move.setpoint = getGyroDegrees(gyro);

	Gyro_move.moveSpeed = -20;

	wait(10);

	PID_Gyro_On_Until_Encoder(Gyro_move, getMotorEncoder(wheelL) + MmToEncoder(deltaForward));

	while(task_usage[1].use != none){}

	Gyro_rotate.oneSided = true;
	Gyro_rotate.side = (bool)(dis < 0);

	PID_Gyro_Rotate(Gyro_rotate, angle);

	while(task_usage[2].use != none){}

	Gyro_rotate.side = (bool)(dis > 0);

	PID_Gyro_Rotate(Gyro_rotate, -angle);

	while(task_usage[2].use != none){}
}
