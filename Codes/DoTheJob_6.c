void goToTheBigShip()
{
	robotBlocks[3] = goodBlocks[0];
	robotBlocks[2] = goodBlocks[1];

	grabHeight = 67;

	Encoder_moveMm(Encoder_move, -10);

	int init = getGyroDegrees(gyro);

	wait(10);

	setMotorSpeed(wheelL, -25);

	setMotorSpeed(wheelR, 25);

	while (getGyroDegrees(gyro) > init - 170) {}

	setMotorSpeed(wheelL, 0);
	setMotorSpeed(wheelR, 0);

	LineFollower_slow_l.lineCorrectionTime = 2000;

	LineFollower_slow_l.setpoint = (cBlack + cWhite) / 2 - 7;

	PID_FollowLine_Until_Reflected(LineFollower_slow_l, cWhite - 10);

	LineFollower_slow_l.setpoint = (cBlack + cWhite) / 2 - 2;

	handUp(-30);

	Gyro_rotate.side = true;

	PID_Gyro_Rotate(Gyro_rotate, -92);

	wait(100);

	endResetingHand();

	wait(100);

	Encoder_move.moveSpeed = 20;

	Encoder_moveMm(Encoder_move, 15);

	gripStrength = 10;

	handUp(-47);

	wait(500);

	Encoder_move.moveSpeed = 30;
}

void loadTheBigShip()
{
	setMotorTarget(claw, -170, 30);

	wait(300);

	clawOpened(true, 300);

	startResetingHand();

	gripStrength = 60;

	if(colorsAsked[0] == 2 && colorsAsked[1] == 2)
		MmDepth = 200;
	else
		MmDepth = 190;

	wait(500);

	playSound(soundBeepBeep);

	endResetingHand();

	wait(100);

	int dist = Block_betterTakeFirstBlockInCage(Encoder_move);

	handUp(-30);

	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 11);

	wait(100);

	Encoder_move.moveSpeed = 20;

	Encoder_moveMm(Encoder_move, 135);

	handUp(-47);

	wait(600);

	gripStrength = 15;

	Encoder_move.moveSpeed = 30;

	setMotorTarget(claw, -180, 15);

	wait(500);

	setHandUp(-30);

	gripStrength = 50;

	setMotorTarget(claw, -160, 15);

	if(colorsAsked[0] == 2 && colorsAsked[1] == 2)
		MmDepth = 205;
	else
		MmDepth = 190;

	dist = Block_betterTakeFirstBlockInCage(Encoder_move, 700);

	MmDepth = 165;

	clawOpened(false, 400);

	handUp(-25);

	wait(300);

	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 11);

	wait(100);

	Encoder_move.moveSpeed = 20;

	Encoder_moveMm(Encoder_move, 160);

	//Gyro_rotate.side = true;

	//PID_Gyro_Rotate(Gyro_rotate, -5);

	wait(100);

	Encoder_move.moveSpeed = 30;

	handUp(-55);
	wait(500);

	gripStrength = 10;

	setMotorTarget(claw, -180, 30);

	wait(500);

	handUp(0);
}
void DoTheJob_6()
{
	goToTheBigShip();

	loadTheBigShip();
}
