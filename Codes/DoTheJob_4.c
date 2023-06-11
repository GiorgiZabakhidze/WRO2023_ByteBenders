void goToTheSmallShip()
{
	LineFollower_normal_l.lineCorrectionTime = 750;

	PID_FollowLine_Until_Reflected(LineFollower_normal_l, cBlack + 1);

	LineFollower_normal_l.lineCorrectionTime = 1500;

	Gyro_rotate.side = true;

	PID_Gyro_Rotate(Gyro_rotate, -36);

	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 36);

	LineFollower_slow_r.setpoint = 35;

	LineFollower_slow_r.lineCorrectionTime = 1000;

	PID_FollowLine_Until_Reflected(LineFollower_slow_r, cBlack + 5);

	Encoder_moveMm(Encoder_move, -50);
}

void loadTheSmallShip()
{
	Encoder_move.moveSpeed = 20;
	grabHeight = 64;
	gripStrength = 50;

	int curr = getGyroDegrees(gyro);

	wait(10);

	setMotorSpeed(wheelL, 0);

	setMotorSpeed(wheelR, 15);

	while(getGyroDegrees(gyro) > curr - 13){}

	setMotorSpeed(wheelR, 0);

	Encoder_moveMm(Encoder_move, 20);

	Block_PlaceOnTheShip(600);

	Encoder_move.moveSpeed = 30;

	MmDepth = 215;

	Block_betterTakeFirstBlockInCage(Encoder_move, 800);

	MmDepth = 160;

	Encoder_move.moveSpeed = 20;

	Encoder_moveMm(Encoder_move, 185);

	curr = getGyroDegrees(gyro);

	wait(10);

	setMotorSpeed(wheelL, 15);

	setMotorSpeed(wheelR, 0);

	while(getGyroDegrees(gyro) < curr + 14){}

	setMotorSpeed(wheelL, 0);

	handUp(-44);
	wait(400);
	setMotorTarget(claw, -190, 15);

	wait(400);
	handUp(-15);
	wait(400);

	Encoder_move.moveSpeed = 20;

	Encoder_moveMm(Encoder_move, 30);

	Encoder_move.moveSpeed = 30;

	Encoder_moveMm(Encoder_move, -20);
}

void placeTheShip()
{
	int curr = getGyroDegrees(gyro);

	wait(10);

	setMotorSpeed(wheelL, 25);

	setMotorSpeed(wheelR, 0);

	while(getGyroDegrees(gyro) < curr + 89){}

	setMotorSpeed(wheelL, 0);

	playSound(soundLowBuzz);

	Encoder_moveMm(Encoder_move, 130, 30);

	setMotorSpeed(wheelL, 25);

	while(getGyroDegrees(gyro) < curr + 175){}

	setMotorSpeed(wheelL, 0);

	Encoder_moveUntilReflected(Encoder_move, cWhite - 10, 30);

	Encoder_moveUntilReflected(Encoder_move, cBlack + 1);

	Encoder_moveUntilReflected(Encoder_move, cWhite - 10);

	Encoder_moveUntilReflected(Encoder_move, cBlue);

	setMotorSpeed(wheelL, 25);

	setMotorSpeed(wheelR, 0);

	while(getColorReflected(color1) < cWhite - 5){}

	while(getColorReflected(color1) < (cBlack + cWhite) / 2 + 20){}

	setMotorSpeed(wheelL, 0);

	LineFollower_fast_l.lineCorrectionTime = 1000;

	startResetingHand();

	PID_FollowLine_Until_Reflected(LineFollower_fast_l, cBlack + 1);

	endResetingHand();

	PID_LineFollower_On_Until_Encoder(LineFollower_fast_l, getMotorEncoder(wheelL) - MmToEncoder(200));

	Encoder_moveMm(Encoder_move_fast, -20);

	startResetingHand();

	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, -89);

	gripStrength = 15;
}


void DoTheJob_4()
{
	goToTheSmallShip();

	loadTheSmallShip();

	placeTheShip();
}
