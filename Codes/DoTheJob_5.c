void getGoodBlocks()
{
	gripStrength = 50;

	grabHeight = 65;

	setMotorTarget(claw, -170, 15);

	PID_LineFollower_On_Until_Encoder(LineFollower_normal_r, getMotorEncoder(wheelL) - MmToEncoder(370));

	Block_PickUp();

	Gyro_rotate.side = true

	Encoder_moveMm(Encoder_move, 60);

	PID_Gyro_Rotate(Gyro_rotate, 270);

	Encoder_moveMm(Encoder_move, 550);
}

void goToTheParking()
{
	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, -90);

	PID_FollowLine_Until_Reflected(LineFollower_normal_r, cBlack + 1);

	Encoder_moveMm(Encoder_move, 20);

	Gyro_rotate.side = true;

	PID_Gyro_Rotate(Gyro_rotate, -89);

	LineFollower_ship_l.lineCorrectionTime = 3000;

	PID_FollowLine_Until_Reflected(LineFollower_ship_l, cWhite);

	LineFollower_ship_l.lineCorrectionTime = 1500;

	Encoder_moveMm(Encoder_move, 30);

	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 90);
}

void DoTheJob_5()
{
	getGoodBlocks();

	goToTheParking();
}
