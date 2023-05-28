void getAskedColors()
{
	//Gyro_mover.setpoint = getGyroDegrees(gyro);

	//wait(10);

	//PID_Gyro_On_Until_Encoder(Gyro_mover, getMotorEncoder(wheelR) + MmToEncoder(260));

	//while(task_usage[1].use != none){}

	Gyro_moveMm(Gyro_mover, 260);

	colorsAsked[0] = ColorCheck();


	//Gyro_mover.setpoint = getGyroDegrees(gyro);

	//wait(10);

	//PID_Gyro_On_Until_Encoder(Gyro_mover, getMotorEncoder(wheelR) + MmToEncoder(45));

	//while(task_usage[1].use != none){}

	Gyro_moveMm(Gyro_mover, 45);

	colorsAsked[1] = ColorCheck();
}

void pushTheShip()
{
	Gyro_mover.setpoint = getGyroDegrees(gyro);

	wait(100);

	PID_Gyro_On_Until_Encoder(Gyro_mover_fast, getMotorEncoder(wheelR) + MmToEncoder(105));

	while(task_usage[1].use != none){}
}

void parallelCorrection()
{
	Gyro_mover.setpoint = getGyroDegrees(gyro);

	Gyro_mover.moveSpeed = -20;

	wait(10);

	PID_Gyro_On_Until_Encoder(Gyro_mover, getMotorEncoder(wheelR) - MmToEncoder(150));

	while(task_usage[1].use != none){}

	Gyro_rotate.oneSided = true;
	Gyro_rotate.side = true;

	PID_Gyro_Rotate(Gyro_rotate, -55);

	while(task_usage[2].use != none){}

	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 55);

	while(task_usage[2].use != none){}

	Gyro_mover.setpoint = getGyroDegrees(gyro);

	Gyro_mover.moveSpeed = 20;

	wait(10);

	PID_Gyro_On_Until_Encoder(Gyro_mover, getMotorEncoder(wheelR) + MmToEncoder(20));
}

void getOnTheLine()
{
	playSound(soundBlip);

	setHandUp(-65);

	clawOpened(false);

	wait(30);

	Gyro_mover.setpoint = getGyroDegrees(gyro);

	Gyro_mover.moveSpeed = -20;

	wait(10);

	PID_Gyro_On_Until_Encoder(Gyro_mover, getMotorEncoder(wheelR) - MmToEncoder(50));

	while(task_usage[1].use != none){}

	Gyro_rotate.side = true;

	setHandUp(-60);

	PID_Gyro_Rotate(Gyro_rotate, 90);

	while(task_usage[2].use != none){}
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

void DoTheJob_1()
{
	getAskedColors();

	pushTheShip();

	parallelCorrection();

	getOnTheLine();
}
