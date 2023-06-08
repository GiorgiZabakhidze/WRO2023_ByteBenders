void goToTheSmallShip()
{
	LineFollower_slow_l.lineCorrectionTime = 500;

	PID_FollowLine_Until_Reflected(LineFollower_slow_l, cBlack + 1);

	LineFollower_slow_l.lineCorrectionTime = 1500;

	Gyro_rotate.side = true;

	PID_Gyro_Rotate(Gyro_rotate, -36);

	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 36);

	LineFollower_slow_r.setpoint = 35;

	LineFollower_slow_r.lineCorrectionTime = 700;

	PID_FollowLine_Until_Reflected(LineFollower_slow_r, cBlack + 5);

	Encoder_moveMm(Encoder_move, -50);
}

void loadTheSmallShip()
{
	Encoder_move.moveSpeed = 15;
	grabHeight = 70;

	int curr = getGyroDegrees(gyro);

	wait(10);

	setMotorSpeed(wheelL, 0);

	setMotorSpeed(wheelR, 10);

	while(getGyroDegrees(gyro) > curr - 11){}

	setMotorSpeed(wheelR, 0);

	Encoder_moveMm(Encoder_move, 20);

	Block_PlaceOnTheShip();

	clawOpened(true);

	Block_takeFirstBlockInCage(Encoder_move);

	Encoder_moveMm(Encoder_move, 170);

	curr = getGyroDegrees(gyro);

	wait(10);

	setMotorSpeed(wheelL, 10);

	setMotorSpeed(wheelR, 0);

	while(getGyroDegrees(gyro) < curr + 11){}

	setMotorSpeed(wheelL, 0);

	setHandUp(-36);
	setMotorTarget(claw, -190, 15);

	wait(1000);
	setHandUp(-15);

	Encoder_move.moveSpeed = 10;

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

	while(getGyroDegrees(gyro) < curr + 175){}

	setMotorSpeed(wheelL, 0);

	Encoder_moveUntilReflected(Encoder_move, cWhite - 10, 30);

	Encoder_moveUntilReflected(Encoder_move, cBlack + 1);

	Encoder_moveUntilReflected(Encoder_move, cWhite - 10);

	Encoder_moveUntilReflected(Encoder_move, cBlue);

	curr = getGyroDegrees(gyro);

	wait(10);

	setMotorSpeed(wheelL, 25);

	setMotorSpeed(wheelR, 0);

	while(getGyroDegrees(gyro) < curr + 90){}

	setMotorSpeed(wheelL, 0);

	LineFollower_normal_l.lineCorrectionTime = 1000;

	PID_FollowLine_Until_Reflected(LineFollower_normal_l, cBlack + 1);

	PID_LineFollower_On_Until_Encoder(LineFollower_normal_l, getMotorEncoder(wheelL) - MmToEncoder(200));

	Encoder_moveMm(Encoder_move, -10);

	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, -89);
}


void DoTheJob_4()
{
	goToTheSmallShip();

	loadTheSmallShip();

	placeTheShip();
}
