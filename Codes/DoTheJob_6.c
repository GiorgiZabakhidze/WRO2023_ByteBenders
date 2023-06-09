void goToTheBigShip()
{
	robotBlocks[3] = 3;
	robotBlocks[2] = 3;

	grabHeight = 65;

	Encoder_moveMm(Encoder_move, -10);

	int init = getGyroDegrees(gyro);

	wait(10);

	setMotorSpeed(wheelL, -25);

	setMotorSpeed(wheelR, 25);

	while(getGyroDegrees(gyro) > init - 170){}

	setMotorSpeed(wheelL, 0);
	setMotorSpeed(wheelR, 0);

	LineFollower_normal_l.lineCorrectionTime = 1000;

	LineFollower_normal_l.setpoint = 35;

	PID_FollowLine_Until_Reflected(LineFollower_normal_l, cWhite - 10);

	LineFollower_normal_l.setpoint = 35;

	handUp(-40);

	Gyro_rotate.side = true;

	PID_Gyro_Rotate(Gyro_rotate, -91);

	wait(200);

	Encoder_move.moveSpeed = 20;

	Encoder_moveMm(Encoder_move, 10);

	setHandUp(-43);

	wait(200);

	Encoder_move.moveSpeed = 30;
}

void loadTheBigShip()
{
	clawOpened(true, 400);

	setHandUp(-25);

	Block_takeFirstBlockInCage(Encoder_move);

	wait(200);

	handUp(-39);

	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 8);

	wait(200);

	Encoder_move.moveSpeed = 20;

	Encoder_moveMm(Encoder_move, 140);

	wait(200);

	Encoder_move.moveSpeed = 30;

	setMotorTarget(claw, -180, 15);

	wait(300);

	int addition = 0;

	if(colorsAsked[1] == 2 && colorsAsked[0] == 2)
		addition = 8;

	Block_takeFirstBlockInCage(Encoder_move, 32 + addition);

	clawOpened(false, 400);

	handUp(-41);

	wait(200);

	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 12);

	wait(200);

	Encoder_move.moveSpeed = 20;

	Encoder_moveMm(Encoder_move, 150 + addition);

	wait(200);

	Encoder_move.moveSpeed = 30;

	setHandUp(-46);

	setMotorTarget(claw, -170, 20);

	wait(300);

	handUp(0);
}
void DoTheJob_6()
{
	goToTheBigShip();

	loadTheBigShip();
}
