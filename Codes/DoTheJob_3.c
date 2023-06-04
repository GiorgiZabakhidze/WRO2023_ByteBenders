void goToBoxes()
{
	Gyro_moveMm(Gyro_move, -220, 30);

	Gyro_rotate.oneSided = true;
	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 180);

	Gyro_moveUntilReflected(Gyro_move, cWhite - 40);

	Gyro_rotate.side = true;

	PID_Gyro_Rotate(Gyro_rotate, -85);

	PID_LineFollower_On_ForTime(LineFollower_normal_r, 2000);

	wait(5);

	PID_FollowLine_Until_Reflected(LineFollower_normal_r, cBlack);

	Encoder_moveMm(Encoder_move, 390);

	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 90);

	Encoder_moveMm(Encoder_move, 165);

	PID_Gyro_Rotate(Gyro_rotate, 90);

	Encoder_moveMm(Encoder_move, 76);

}

void getBlockColors()
{
	startTask(Cimcimi);

	int blue = 2;
	int green = 2;

	int badColor = 1;

	int col1 = colorsAsked[0], col2 = colorsAsked[1];

	for(int i = 3; i >= 0; i--)
	{
		if(i > 0)
		{
			blockColors[i] = ColorCheck();
		}
		else
		{
			if(blue == 1)
				blockColors[0] = 2;
			else
				blockColors[0] = 3;
		}

		if(blockColors[i] == 2)
			blue--;
		else
			green--;

		if(blockColors[i] == col1)
		{
			col1 = 0;
		}
		else if(blockColors[i] == col2)
		{
			col2 = 0;
		}
		else
		{
			if(badColor < 0)
			{
				displayBigTextLine(1, "oh noo");
				while(1)
				{
					playSound(soundDownwardTones);
				}
			}
			badCol[badColor] = i;
			badColor--;
		}

		displayBigTextLine(2*i+1, "%d", blockColors[i]);

		if(i > 0)
			Encoder_moveMm(Encoder_move, 69);
	}

}

void getTheBadBlock()
{
	setMotorTarget(claw, -160, 15);

	Encoder_moveMm(Encoder_move, 220);

	PID_Gyro_Rotate(Gyro_rotate, 89);

	Encoder_moveForTime(Encoder_move, 1300, -30);

	Encoder_moveMm(Encoder_move, 223);

	Gyro_rotate.side = true;

	PID_Gyro_Rotate(Gyro_rotate, 90);

	wait(10);

	Encoder_moveMm(Encoder_move, 105);

	//Encoder_moveMm(Encoder_move, badCol[0] * 70);
	PID_Encoder_On_Until_Encoder(Encoder_move, getMotorEncoder(wheelL) - MmToEncoder(badCol[0] * 70));

	wait(10);

	Block_PickUp();

	//Encoder_moveMm(Encoder_move, -badCol[0] * 70 - 105);
	PID_Encoder_On_Until_Encoder(Encoder_move, getMotorEncoder(wheelL) - MmToEncoder(-badCol[0] * 70 - 105));

	wait(10);

	setHandUp(-60);
	setMotorTarget(claw, -160, 15);
	wait(400);
	handUp(-10);

	//Encoder_moveMm(Encoder_move, 105);
	PID_Encoder_On_Until_Encoder(Encoder_move, getMotorEncoder(wheelL) - MmToEncoder(105));

	wait(10);

	//Encoder_moveMm(Encoder_move, badCol[1] * 70);
	PID_Encoder_On_Until_Encoder(Encoder_move, getMotorEncoder(wheelL) - MmToEncoder(badCol[1] * 70));

	wait(10);

	Block_PickUp();

	//Encoder_moveMm(Encoder_move, (5 - badCol[1]) * 70);
	PID_Encoder_On_Until_Encoder(Encoder_move, getMotorEncoder(wheelL) - MmToEncoder((5 - badCol[1]) * 70));

	wait(100);

	//Encoder_moveMm(Encoder_move, -250);
	PID_Encoder_On_Until_Encoder(Encoder_move, getMotorEncoder(wheelL) - MmToEncoder(-250));

	wait(100);

	setHandUp(-60);
	setMotorTarget(claw, -160, 15);
	wait(400);
	handUp(-10);

	//Encoder_moveMm(Encoder_move, 95);
	PID_Encoder_On_Until_Encoder(Encoder_move, getMotorEncoder(wheelL) - MmToEncoder(95));

	wait(10);

	Block_PickUp();

	//PID_Gyro_Rotate(Gyro_rotate, -90);
	PID_Encoder_On_Until_Encoder(Encoder_move, getMotorEncoder(wheelL) - MmToEncoder(-90));
}

void


void DoTheJob_3()
{
	goToBoxes();

	getBlockColors();

	getTheBadBlock();
}
