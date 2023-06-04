void getAskedColors()
{
	//Gyro_moveMm(Gyro_move, 290);

	//Gyro_moveMm(Gyro_move, 40);

	Encoder_moveMm(Encoder_move, 70);

	LineFollower_normal_l.setpoint = 60;

	PID_LineFollower_On_Until_Encoder(LineFollower_normal_l, getMotorEncoder(wheelL) - MmToEncoder(210));

	colorsAsked[0] = ColorCheck();

	displayBigTextLine(1, "%d", colorsAsked[0]);

	PID_LineFollower_On_Until_Encoder(LineFollower_normal_l, getMotorEncoder(wheelL) - MmToEncoder(45));

	colorsAsked[1] = ColorCheck();

	displayBigTextLine(3, "%d", colorsAsked[1]);

	PID_LineFollower_On_Until_Reflected(LineFollower_normal_l, cBlack + 1);

	stopTask(Cimcimi);
}


void pushTheShip()
{
	Gyro_moveMm(Gyro_move, -30);

	Gyro_rotate.Kp = 1.5;

	Gyro_rotate.side = true;

	PID_Gyro_Rotate(Gyro_rotate, -20);

	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 20);

	Gyro_rotate.Kp = 3;

	Encoder_moveMm(Encoder_move_fast, 130);

	setHandUp(-60);
	clawOpened(true);

	wait(500);
}

void getOnTheLine()
{
	Gyro_move.moveSpeed = -30;

	PID_Gyro_On_Until_Reflected(Gyro_move, cBlack);

	Encoder_moveMm(Encoder_move, -25);

	Gyro_rotate.oneSided = true;
	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 90);
}

void putTheShip()
{
	PID_LineFollower_On_ForTime(LineFollower_normal_l, 1000, false);

	playSound(soundLowBuzz);

	wait(5);

	PID_FollowLine_Until_Reflected(LineFollower_normal_l, cBlack + 1);

	playSound(soundBlip);

	wait(5);

	PID_LineFollower_On_Until_Encoder(LineFollower_normal_l, getMotorEncoder(wheelL) - MmToEncoder(550));

	Gyro_rotate.side = true;

	Gyro_rotate.acceptableRange = 1;

	PID_Gyro_Rotate(Gyro_rotate, -87);

	Gyro_move.moveSpeed = 30;

	Gyro_move.setpoint = getGyroDegrees(gyro);

	wait(10);

	PID_Gyro_On_ForTime(Gyro_move, 500);

	clawOpened(false);

	setHandUp(-10);

	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, -20);

	Gyro_rotate.side = true;

	PID_Gyro_Rotate(Gyro_rotate, 20);

	Gyro_move.moveSpeed = -30;

	PID_Gyro_On_Until_Reflected(Gyro_move, cWhite - 10);

	PID_Gyro_On_Until_Reflected(Gyro_move, cBlack + 1);
}

void DoTheJob_1()
{
	getAskedColors();

	pushTheShip();

	getOnTheLine();

	putTheShip();
}
