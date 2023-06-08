int grabHeight = 80;
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

void Block_Grab(int time = 1300)
{
	setHandUp(-grabHeight);

	clawOpened(false, time);
}

void Block_PickUp(int time = 1300)
{
	Block_Grab(time);

	setHandUp(-20);
}

void Block_PlaceDown(int time = 1300)
{
	setHandUp(-65);

	clawOpened(true, time);

	handUp(-20);
}

void Block_PlaceOnTheShip(int time = 1300)
{
	setHandUp(-40);

	clawOpened(true, time);

	handUp(-20);
}

int Block_takeFirstBlockInCage(PID* Encoder_mover)
{
	float MmAfterFirstBlock = 90;

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

	robotBlocks[firstBlock] = 0;

	Encoder_mover->moveSpeed = -abs(Encoder_mover->moveSpeed);

	Encoder_mover->setpoint = getMotorEncoder(wheelR) + getMotorEncoder(wheelL);

	float curr = getMotorEncoder(wheelL);

	wait(10);

	float target = curr + MmToEncoder(MmAfterFirstBlock) + MmToEncoder((firstBlock - 1) * MmBetweenBlocks);

	PID_Encoder_On_Until_Encoder(Encoder_mover, target);

	Block_PickUp();

	return target - curr;
}

void parallelMovement(float dis)
{
	float r = 183;
	float angle = 57.2958 * acos( 1 - abs(dis) / r );

	Gyro_move.oneSided = false;

	Gyro_move.setpoint = getGyroDegrees(gyro);

	int k = abs(dis) / dis;

	Gyro_move.moveSpeed = -30 * k;

	wait(10);

	Gyro_rotate.oneSided = true;
	Gyro_rotate.side = (bool)(dis < 0);

	PID_Gyro_Rotate(Gyro_rotate, angle);

	Gyro_rotate.side = (bool)(dis > 0);

	PID_Gyro_Rotate(Gyro_rotate, -angle);
}
