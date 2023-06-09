void getAskedColors()
{
	Encoder_moveMm(Encoder_move, 80);

	LineFollower_normal_l.setpoint = 60;

	PID_LineFollower_On_Until_Encoder(LineFollower_normal_l, getMotorEncoder(wheelL) - MmToEncoder(210));

	playSound(soundBlip);

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
	handUp(-65);

	Encoder_moveForTime(Encoder_move_fast, 800, 55);

	Encoder_moveMm(Encoder_move, -10, -30);

	setMotorSpeed(claw, 50);

	wait(500);
}

void getOnTheLine()
{
	Gyro_move.moveSpeed = -30;

	PID_Gyro_On_Until_Reflected(Gyro_move, cBlack);

	Encoder_moveMm(Encoder_move, -35);

	Gyro_rotate.oneSided = true;
	Gyro_rotate.side = false;

	int curr = getGyroDegrees(gyro);

	wait(10);

	setMotorSpeed(wheelL, 60);

	while(getGyroDegrees(gyro) < curr + 45){}

	while(getColorReflected(color1) < cWhite - 5){}

	while(getColorReflected(color1) > cWhite - 10){}

	setMotorSpeed(wheelL, 0);
}

void putTheShip()
{
	clawOpened(false, 300);
	handUp(-20);

	playSound(soundLowBuzz);

	PID_FollowLine_Until_Reflected(LineFollower_sonic_l, cBlack + 1);

	playSound(soundBlip);

	PID_LineFollower_On_Until_Encoder(LineFollower_fast_l, getMotorEncoder(wheelL) - MmToEncoder(530));

	setHandUp(-65);
	clawOpened(true, 500);

	Gyro_rotate.side = true;

	Gyro_rotate.Kp = 2;

	Gyro_rotate.acceptableRange = 1;

	PID_Gyro_Rotate(Gyro_rotate, -87);

	Gyro_rotate.Kp = 3;

	Encoder_move.moveSpeed = 30;

	Encoder_move.setpoint = getMotorEncoder(wheelR) + getMotorEncoder(wheelL);

	wait(10);

	PID_Encoder_On_ForTime(Encoder_move, 500);

	clawOpened(false, 200);

	handUp(-20);

	wait(200);

	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, -90);

	Encoder_moveMm(Encoder_move, -90);

	Gyro_rotate.side = false;

	Gyro_rotate.Kp = 3;

	PID_Gyro_Rotate(Gyro_rotate, -88);

	//Gyro_rotate.side = true;

	//PID_Gyro_Rotate(Gyro_rotate, 105);
}

void DoTheJob_1()
{
	getAskedColors();

	pushTheShip();

	getOnTheLine();

	putTheShip();
}
