void getAskedColors()
{
	Encoder_moveMm(Encoder_move, 70);

	LineFollower_normal_l.setpoint = 60;

	PID_LineFollower_On_Until_Encoder(LineFollower_normal_l, getMotorEncoder(wheelL) - MmToEncoder(210));

	colorsAsked[0] = ColorCheck();

	displayBigTextLine(1, "%d", colorsAsked[0]);

	LineFollower_normal_r.moveSpeed = 10;

	PID_LineFollower_On_Until_Encoder(LineFollower_normal_l, getMotorEncoder(wheelL) - MmToEncoder(45));

	LineFollower_normal_r.moveSpeed = 30;

	colorsAsked[1] = ColorCheck();

	displayBigTextLine(3, "%d", colorsAsked[1]);

	stopTask(Cimcimi);
}


void pushTheShip()
{
	//Encoder_moveMm(Encoder_move, 30);

	//Encoder_moveMm(Encoder_move, -50);

	//Gyro_rotate.Kp = 1.5;

	//Gyro_rotate.oneSided = true;
	//Gyro_rotate.side = false;

	//PID_Gyro_Rotate(Gyro_rotate, -15);

	//Gyro_rotate.side = true;

	//PID_Gyro_Rotate(Gyro_rotate, 16);

	//Gyro_rotate.Kp = 3;

	Encoder_moveForTime(Encoder_move_fast, 800, 55);

	setHandUp(-60);
	setMotorSpeed(claw, 50);

	wait(1250);

	Encoder_moveMm(Encoder_move, -10, -30);

	wait(100);
}

void getOnTheLine()
{
	Gyro_move.moveSpeed = -30;

	PID_Gyro_On_Until_Reflected(Gyro_move, cBlack);

	Encoder_moveMm(Encoder_move, -35);

	Gyro_rotate.oneSided = true;
	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 45);

	setMotorSpeed(wheelL, 30);

	while(getColorReflected(color1) < cWhite - 5){}

	while(getColorReflected(color1) > cWhite - 10){}

	setMotorSpeed(wheelL, 0);
}

void putTheShip()
{
	clawOpened(false);
	handUp(-20);

	PID_LineFollower_On_ForTime(LineFollower_ship_l, 1750, false);

	playSound(soundLowBuzz);

	wait(5);

	PID_FollowLine_Until_Reflected(LineFollower_ship_l, cBlack + 1);

	playSound(soundBlip);

	wait(5);

	PID_LineFollower_On_Until_Encoder(LineFollower_ship_l, getMotorEncoder(wheelL) - MmToEncoder(520));

	setHandUp(-65);
	clawOpened(true);

	Gyro_rotate.side = true;

	Gyro_rotate.acceptableRange = 1;

	PID_Gyro_Rotate(Gyro_rotate, -87);

	Encoder_move.moveSpeed = 30;

	Encoder_move.setpoint = getMotorEncoder(wheelR) + getMotorEncoder(wheelL);

	wait(10);

	PID_Encoder_On_ForTime(Encoder_move, 500);

	clawOpened(false);

	setHandUp(-20);

	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, -15);

	Gyro_rotate.side = true;

	PID_Gyro_Rotate(Gyro_rotate, 105);
}

void DoTheJob_1()
{
	getAskedColors();

	pushTheShip();

	getOnTheLine();

	putTheShip();
}
