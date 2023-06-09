void getGoodBlocks()
{
	gripStrength = 40;

	grabHeight = 69;

	setMotorTarget(claw, -170, 15);

	PID_LineFollower_On_Until_Encoder(LineFollower_normal_r, getMotorEncoder(wheelL) - MmToEncoder(370));

	Block_PickUp(500);

	Gyro_rotate.side = true;

	Encoder_moveMm(Encoder_move, 60);

	PID_Gyro_Rotate(Gyro_rotate, 268);

	Encoder_moveMm(Encoder_move, 600);
}

void goToTheParking()
{
	Gyro_rotate.side = true;

	PID_Gyro_Rotate(Gyro_rotate, -87);

	//Encoder_moveForTime(Encoder_move, 700, -50);

	Encoder_moveUntilReflected(Encoder_move, cWhite - 5, 40);

	Encoder_moveUntilReflected(Encoder_move, cBlack + 2);

	Encoder_moveUntilReflected(Encoder_move, cWhite - 5, 30);

	Gyro_rotate.side = true;

	PID_Gyro_Rotate(Gyro_rotate, -89);

	LineFollower_fast_l.lineCorrectionTime = 3000;

	PID_FollowLine_Until_Reflected(LineFollower_fast_l, cWhite);

	LineFollower_fast_l.lineCorrectionTime = 1500;

	Encoder_moveMm(Encoder_move, 50);

	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 90);
}

void DoTheJob_5()
{
	getGoodBlocks();

	goToTheParking();
}
