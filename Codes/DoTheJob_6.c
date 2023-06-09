void goToTheBigShip()
{
	robotBlocks[3] = 3;
	robotBlocks[2] = 3;

	grabHeight = 68;

	Encoder_moveMm(Encoder_move, -10);

	int init = getGyroDegrees(gyro);

	wait(10);

	setMotorSpeed(wheelL, -25);

	setMotorSpeed(wheelR, 25);

	while(getGyroDegrees(gyro) > init - 170){}

	setMotorSpeed(wheelL, 0);
	setMotorSpeed(wheelR, 0);

	LineFollower_slow_l.lineCorrectionTime = 1300;

	LineFollower_slow_l.setpoint = 35;

	PID_FollowLine_Until_Reflected(LineFollower_slow_l, cWhite - 10);

	LineFollower_slow_l.setpoint = 35;

	handUp(-42);

	Gyro_rotate.side = true;

	PID_Gyro_Rotate(Gyro_rotate, -92);

	//wait(500);

	Encoder_move.moveSpeed = 20;

	Encoder_moveMm(Encoder_move, 10);

	//wait(500);

	Encoder_move.moveSpeed = 30;
}

void loadTheBigShip()
{
	clawOpened(true, 400);

	setHandUp(-30);

	Block_takeFirstBlockInCage(Encoder_move);

	//wait(500);

	handUp(-36);

	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 7);

	//wait(500);

	Encoder_move.moveSpeed = 20;

	Encoder_moveMm(Encoder_move, 140);

	//wait(500);

	Encoder_move.moveSpeed = 30;

	setMotorTarget(claw, -180, 15);

	wait(300);

	Block_takeFirstBlockInCage(Encoder_move);

	handUp(-35);

	//wait(500);

	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 30);

	//wait(500);

	Gyro_rotate.side = true;

	PID_Gyro_Rotate(Gyro_rotate, -25);

	//wait(500);

	Encoder_move.moveSpeed = 20;

	Encoder_moveMm(Encoder_move, 140);

	//wait(500);

	Encoder_move.moveSpeed = 30;

	setMotorTarget(claw, -170, 20);

	wait(300);

	handUp(0);
}
void DoTheJob_6()
{
	goToTheBigShip();

	loadTheBigShip();
}
