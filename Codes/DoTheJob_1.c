void getAskedColors()
{
	Gyro_moveMm(Gyro_move, 290);

	colorsAsked[0] = ColorCheck();

	Gyro_moveMm(Gyro_move, 40);

	colorsAsked[1] = ColorCheck();

	stopTask(Cimcimi);
}

void pushTheShip()
{
	Gyro_moveMm(Gyro_move_fast, 150);

	setHandUp(-50);

	clawOpened(true);

	//Gyro_moveMm(Gyro_move_fast, -30);

	//Gyro_rotate.oneSided = true;
	//Gyro_rotate.side = true;

	//PID_Gyro_Rotate(Gyro_move_fast, 40);

	//Gyro_rotate.side = false;

	//wait(1000);

	//PID_Gyro_Rotate(Gyro_move_fast, -40);
}

void getOnTheLine()
{
	Gyro_move.moveSpeed = -30;

	PID_Gyro_On_Until_Reflected(Gyro_move, cBlack);

	wait(100);

	PID_Gyro_On_Until_Reflected(Gyro_move, (cBlack + cWhite)/2 + 3);

	Gyro_rotate.oneSided = true;
	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 90);

	//Gyro_rotate.oneSided = true;

	//Gyro_rotate.side = true;

	//PID_Gyro_Rotate(Gyro_rotate, -29);

	//Gyro_rotate.side = false;

	//PID_Gyro_Rotate(Gyro_rotate, 28);
}

void putTheShip()
{
	PID_LineFollower_On_ForTime(LineFollower_normal_l, 1000, false);

	playSound(soundLowBuzz);

	wait(5);

	PID_FollowLine_Until_Reflected(LineFollower_normal_l, cBlack + 1);

	playSound(soundBlip);

	wait(5);

	PID_LineFollower_On_ForTime(LineFollower_normal_l, 2300, false);

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
