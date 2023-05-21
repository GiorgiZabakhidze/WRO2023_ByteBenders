void getAskedColors()
{
	Gyro_mover.setpoint = getGyroDegrees(gyro);

	wait(10);

	PID_Gyro_On_Until_Encoder(Gyro_mover, getMotorEncoder(wheelR) + MmToEncoder(260));

	while(task_usage[1].use != none){}

	colorsAsked[0] = ColorCheck();


	Gyro_mover.setpoint = getGyroDegrees(gyro);

	wait(10);

	PID_Gyro_On_Until_Encoder(Gyro_mover, getMotorEncoder(wheelR) + MmToEncoder(45));

	while(task_usage[1].use != none){}

	colorsAsked[1] = ColorCheck();
}

void getBlockColors()
{
	for(int i = 3; i >= 0; i--)
	{
		int color = ColorCheck();

		if(color == colorsAsked[0])
		{
			robotBlocks[0] = colorsAsked[0];

			colorsAsked[0] = 0;
		}
		else if(color == colorsAsked[1])
		{
			robotBlocks[0] = colorsAsked[1];

			colorsAsked[1] = 0;
		}
		else
		{
			return;
		}
	}
}

void DoTheJob_1()
{
	getAskedColors();
}
