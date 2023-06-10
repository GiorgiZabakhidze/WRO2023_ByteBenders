void goToBoxes()
{
	Encoder_moveMm(Encoder_move, -220, 30);

	Gyro_rotate.oneSided = true;
	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 180);

	startResetingHand();

	Encoder_moveUntilReflected(Encoder_move, cDarkBlue + 10, -30);

	setMotorSpeed(wheelL, 0);
	setMotorSpeed(wheelR, 40);

	while(getColorReflected(color1) > cDarkBlue + 2){}

	while(getColorReflected(color1) < cWhite - 5){}

	//while(getColorReflected(color1) > (cBlack + cWhite) / 2 + 25){}

	setMotorSpeed(wheelR, 0);

	LineFollower_fast_r.lineCorrectionTime = 2000;

	PID_FollowLine_Until_Reflected(LineFollower_fast_r, cBlack);

	endResetingHand();

	PID_LineFollower_On_Until_Encoder(LineFollower_normal_r, getMotorEncoder(wheelL) - MmToEncoder(395));

	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 89);

	Encoder_moveMm(Encoder_move, 160);

	PID_Gyro_Rotate(Gyro_rotate, 90);

	Encoder_moveMm(Encoder_move, 30);

	Encoder_moveUntilReflected(Encoder_move, cWhite - 2);

	Encoder_moveUntilReflected(Encoder_move, cBlack + 1);

	Encoder_moveMm(Encoder_move, -5);

	Encoder_move.moveSpeed = 30;
}

void getBlockColors()
{
	startTask(Cimcimi);

	int blue = 2;
	int green = 2;

	int badColor = 1;

	int col1 = colorsAsked[0], col2 = colorsAsked[1];

	for(int i = 2; i >= 0; i--)
	{
		if(i == 0 && blue == 0)
		{
			blockColors[3] = 3;
			blockColors[0] = 3;

			break;
		}
		if(i == 0 && green == 0)
		{
			blockColors[3] = 2;
			blockColors[0] = 2;

			break;
		}

		blockColors[i] = ColorCheck();

		if(blockColors[i] == 2)
			blue--;
		else
			green--;

		if(blockColors[i] == 3)
			playSound(soundUpwardTones);
		else
			playSound(soundDownwardTones);

		//displayBigTextLine(11, "%d", blue);
		//displayBigTextLine(13, "%d", green);

		displayBigTextLine(2*i + 1, "%d", blockColors[i]);

		if(i == 2)
			PID_Encoder_On_Until_Encoder(Encoder_move, getMotorEncoder(wheelL) - MmToEncoder(72));
		else if(i == 1)
			PID_Encoder_On_Until_Encoder(Encoder_move, getMotorEncoder(wheelL) - MmToEncoder(70));
	}

	if(blue == 1)
			blockColors[3] = 2;
	else if(green == 1)
			blockColors[3] = 3;

	int goodBlock = 1;
	for(int i = 3; i >= 0; i--)
	{
		if(blockColors[i] == col1)
		{
			col1 = 0;
			goodBlocks[goodblock] = blockColors[i];
			goodblock--;
		}
		else if(blockColors[i] == col2)
		{
			col2 = 0;
			goodBlocks[goodblock] = blockColors[i];
			goodblock--;
		}
		else
		{
			badCol[badColor] = i;

			badBlocks[0] = blockColors[i];
			badColor--;
		}
	}

	robotBlocks[3] = badBlocks[0];

	displayBigTextLine(13, "%d", badBlocks[0]);

	stopTask(Cimcimi);

}

void getTheBadBlock()
{
	grabHeight = 65;

	setMotorTarget(claw, -140, 15);

	Encoder_moveMm(Encoder_move, 220);

	PID_Gyro_Rotate(Gyro_rotate, 89);

	Encoder_moveForTime(Encoder_move, 1100, -40);

	Encoder_moveMm(Encoder_move, 230);

	Gyro_rotate.side = true;

	PID_Gyro_Rotate(Gyro_rotate, 89);

	int constant = 80;
	int disBetweenBlocks = 80;
	gripStrength = 50;

	Encoder_move.setpoint = getMotorEncoder(wheelR) + getMotorEncoder(wheelL);

	wait(10);

	if(badCol[0] != 0)
	{
		Encoder_moveMm(Encoder_move, constant + badCol[0] * disBetweenBlocks + 15);

		wait(10);

		Block_PickUp(700);

		Encoder_move.moveSpeed = -30;
		PID_Encoder_On_Until_Encoder(Encoder_move, getMotorEncoder(wheelL) - MmToEncoder(-badCol[0] * disBetweenBlocks - constant - 5));

		wait(10);

		setHandUp(-65);
		setMotorTarget(claw, -140, 15);
		wait(400);
		setHandUp(-20);
	}

	Encoder_move.moveSpeed = 30;

	wait(10);

	PID_Encoder_On_Until_Encoder(Encoder_move, getMotorEncoder(wheelL) - MmToEncoder(badCol[1] * disBetweenBlocks + constant));

	Block_PickUp(700);

	playSound(soundLowBuzz);

	Encoder_move.moveSpeed = 30;

	PID_Encoder_On_Until_Encoder(Encoder_move, getMotorEncoder(wheelL) - MmToEncoder((5 - badCol[1]) * disBetweenBlocks + 30));

	wait(10);

	Encoder_move.moveSpeed = -30;
	PID_Encoder_On_Until_Encoder(Encoder_move, getMotorEncoder(wheelL) - MmToEncoder(-265));

	wait(10);

	setHandUp(-65);
	setMotorTarget(claw, -140, 15);
	wait(400);
	setHandUp(-20);

	Encoder_move.moveSpeed = 30;
	PID_Encoder_On_Until_Encoder(Encoder_move, getMotorEncoder(wheelL) - MmToEncoder(90));

	wait(10);

	Block_PickUp(700);

	Gyro_rotate.side = true;

	PID_Gyro_Rotate(Gyro_rotate, -45);

	setMotorSpeed(wheelL, 0);
	setMotorSpeed(wheelR, 40);

	while(getColorReflected(color1) < cWhite - 5){}

	while(getColorReflected(color1) > cBlack + 2){}

	while(getColorReflected(color1) > cWhite - 20){}

	setMotorSpeed(wheelR, 0);
}


void DoTheJob_3()
{
	goToBoxes();

	getBlockColors();

	getTheBadBlock();
}
