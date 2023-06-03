void goToBoxes()
{
	//Gyro_mover.moveSpeed = -20;

	//PID_Gyro_On_Until_Encoder(Gyro_mover, getMotorEncoder(wheelR) - MmToEncoder(400));

	//while(task_usage[1].use != none){}

	//Gyro_mover.oneSided = true;
	//Gyro_mover.side = false;

	//PID_Gyro_Rotate(Gyro_mover, 90);

	//while(task_usage[2].use != none){}

	//PID_LineFollower_On_ForTime(LineFollower_normal_r, 3000);

	//while(task_usage[0].use != none){}

	//PID_Encoder_On_Until_Reflected(LineFollower_normal_r, 10);

	while(task_usage[0].use != none){}

	PID_Gyro_On_Until_Encoder(Gyro_move, getMotorEncoder(wheelL) + 150);
}

void getBlockColors()
{
	for(int i = 3; i >= 0; i--)
	{
		int color = ColorCheck();

		if(color == colorsAsked[0])
		{
			robotBlocks[i] = colorsAsked[0];

			colorsAsked[0] = 0;
		}
		else if(color == colorsAsked[1])
		{
			robotBlocks[i] = colorsAsked[1];

			colorsAsked[1] = 0;
		}
		else
		{
			return;
		}
	}
}

void DoTheJob_3()
{
	goToBoxes();
}
