void getGoodBlocks()
{
	gripStrength = 50;

	grabHeight = 63;

	setMotorTarget(claw, -170, 15);

	PID_LineFollower_On_Until_Encoder(LineFollower_normal_r, getMotorEncoder(wheelL) - MmToEncoder(365));

	Block_PickUp(500);

	handUp(-15);

	Gyro_rotate.side = true;

	Encoder_moveMm(Encoder_move, 60);

	Gyro_rotate.Kp = 3.5;

	PID_Gyro_Rotate(Gyro_rotate, 268);

	Gyro_rotate.Kp = 3;

	Encoder_moveMm(Encoder_move, 600, 40);

	Encoder_move.moveSpeed = 30;
}

void goToTheParking()
{
	Gyro_rotate.side = true;

	PID_Gyro_Rotate(Gyro_rotate, -87);

	Encoder_moveUntilReflected(Encoder_move, cWhite - 5, 40);

	Encoder_moveUntilReflected(Encoder_move, cBlack + 2);

	Encoder_moveUntilReflected(Encoder_move, cWhite - 5, 30);

	Gyro_rotate.side = true;

	PID_Gyro_Rotate(Gyro_rotate, -89);

	//

	//LineFollower_sonic_l.Kp = 0.85;

	LineFollower_sonic_l.lineCorrectionTime = 2500;

	PID_FollowLine_Until_Reflected(LineFollower_sonic_l, cWhite);

	LineFollower_sonic_l.Kp = 0.8;

	LineFollower_sonic_l.lineCorrectionTime = 1500;

	//

	//LineFollower_fast_l.lineCorrectionTime = 3000;

	//PID_FollowLine_Until_Reflected(LineFollower_fast_l, cWhite);

	//LineFollower_fast_l.lineCorrectionTime = 1500;

	//

	Encoder_moveMm(Encoder_move, 50);

	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 90);
}

void DoTheJob_5()
{
	getGoodBlocks();

	goToTheParking();
}
