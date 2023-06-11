void getAskedColors()
{
	Encoder_moveMm(Encoder_move, 80);

	LineFollower_fast_l.setpoint = 60;

	PID_LineFollower_On_Until_Encoder(LineFollower_fast_l, getMotorEncoder(wheelL) - MmToEncoder(210));

	playSound(soundBlip);

	colorsAsked[0] = ColorCheck();

	displayBigTextLine(1, "%d", colorsAsked[0]);

	LineFollower_fast_r.moveSpeed = 35;

	PID_LineFollower_On_Until_Encoder(LineFollower_fast_l, getMotorEncoder(wheelL) - MmToEncoder(45));

	LineFollower_fast_r.moveSpeed = 45;

	colorsAsked[1] = ColorCheck();

	displayBigTextLine(3, "%d", colorsAsked[1]);

	stopTask(Cimcimi);
}


void pushTheShip()
{
	handUp(-65);

	Encoder_moveForTime(Encoder_move_fast, 600, 55);

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

	setMotorSpeed(wheelL, 80);

	while(getGyroDegrees(gyro) < curr + 45){}

	while(getColorReflected(color1) < cWhite - 1){}

	while(getColorReflected(color1) > cWhite - 5){}

	setMotorSpeed(wheelL, 0);
}

void putTheShip()
{
	clawOpened(false, 300);

	//startResetingHand();

	handUp(-20);

	playSound(soundLowBuzz);

	PID_FollowLine_Until_Reflected(LineFollower_sonic_l, cBlack + 1);

	//endResetingHand();

	playSound(soundBlip);

	PID_LineFollower_On_Until_Encoder(LineFollower_fast_l, getMotorEncoder(wheelL) - MmToEncoder(530));

	setHandUp(-70);
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

	PID_Gyro_Rotate(Gyro_rotate, -89);
}

void DoTheJob_1()
{
	getAskedColors();

	pushTheShip();

	getOnTheLine();

	putTheShip();
}
