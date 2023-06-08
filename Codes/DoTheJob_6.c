void goToTheBigShip()
{
	robotBlocks[3] = 3;
	robotBlocks[2] = 3;

	grabHeight = 67;

	Encoder_moveMm(Encoder_move, -10);

	//Gyro_rotate.oneSided = false;
	//Gyro_rotate.side = false;
	//Gyro_rotate.Kp = 0.75;

	//PID_Gyro_Rotate(Gyro_rotate, -175);

	int init = getGyroDegrees(gyro);

	setMotorSpeed(wheelL, -15);

	setMotorSpeed(wheelR, 15);

	while(getGyroDegrees(gyro) > init - 170){}

	setMotorSpeed(wheelL, 0);
	setMotorSpeed(wheelR, 0);

	LineFollower_slow_l.lineCorrectionTime = 750;

	LineFollower_slow_l.setpoint = 35;

	PID_FollowLine_Until_Reflected(LineFollower_slow_l, cWhite - 10);

	LineFollower_slow_l.setpoint = 35;

	handUp(-37);

	Gyro_rotate.side = true;

	PID_Gyro_Rotate(Gyro_rotate, -88);

	Encoder_move.moveSpeed = 10;

	Encoder_moveMm(Encoder_move, 40);

	Encoder_move.moveSpeed = 40;
}

void loadTheBigShip()
{
	setMotorTarget(claw, -170, 15);

	wait(400);

	handUp(-45);

	wait(400);

	setHandUp(-30);

	Block_takeFirstBlockInCage(Encoder_move);

	handUp(-35);

	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 5);

	Encoder_move.moveSpeed = 10;

	Encoder_moveMm(Encoder_move, 130);

	Encoder_move.moveSpeed = 30;

	setMotorTarget(claw, -180, 15);

	wait(300);

	Block_takeFirstBlockInCage(Encoder_move);

	handUp(-32);

	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 10);

	Encoder_move.moveSpeed = 10;

	Encoder_moveMm(Encoder_move, 165);

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
