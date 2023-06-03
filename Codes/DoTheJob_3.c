void goToBoxes()
{
	Gyro_moveMm(Gyro_move, -150, 30);

	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 180);

	Gyro_moveUntilReflected(Gyro_move, cWhite);

	Gyro_moveUntilReflected(Gyro_move, cBlack);

	Gyro_rotate.side = true;

	PID_Gyro_Rotate(Gyro_rotate, -90);

	PID_LineFollower_On_ForTime(LineFollower_normal_r, 3000);

	PID_FollowLine_Until_Reflected(LineFollower_normal_r, cBlack);

	PID_LineFollower_On_ForTime(LineFollower_normal_r, 700);

	Gyro_rotate.oneSided = false;

	PID_Gyro_Rotate(Gyro_rotate, 90);

	Gyro_moveUntilReflected(Gyro_move, cBlack);

	Gyro_rotate.oneSided = true;
	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 90);
}

void getBlockColors()
{
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
			badCol[badColor] = i;
			badColor--;

			playSound(soundLowBuzz);

			wait(500);
		}

		if(i > 0)
			Gyro_moveMm(Gyro_move, 75);
	}

}

void getTheBadBlock()
{
	Gyro_moveMm(Gyro_move, badCol[0] * 75);

	Block_PickUp();

	Gyro_moveMm(Gyro_move, -badCol[0] * 75);
}

void DoTheJob_3()
{
	goToBoxes();

	getBlockColors();
}
