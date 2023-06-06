void getOnTheParking()
{
	LineFollower_normal_r.lineCorrectionTime = 300;

	PID_FollowLine_Until_Reflected(LineFollower_normal_r, cBlack + 1);

	Encoder_moveMm(Encoder_move, 80);

	Gyro_rotate.oneSided = true;
	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 90);

	Encoder_moveForTime(Encoder_move, 2500, -40);

}

void getTheBox()
{
	handUp(-20);

	Encoder_moveMm(Encoder_move, 115);

	PID_Gyro_Rotate(Gyro_rotate, 87);

	Encoder_move.moveSpeed = 20;

	Encoder_moveMm(Encoder_move, 50);

	Encoder_move.moveSpeed = 30;

	clawOpened(true);

	Gyro_move.moveSpeed = 10;

	setHandUp(-45);

	wait(300);

	setMotorSpeed(claw, -40);

	wait(1000);

	setHandUp(-20);
}

void hangTheBox()
{
	Encoder_moveUntilReflected(Encoder_move, cWhite - 5, -30);

	Encoder_moveMm(Encoder_move, -140);

	Gyro_rotate.side = true;

	PID_Gyro_Rotate(Gyro_rotate, -86);

	handUp(-31);

	PID_LineFollower_On_Until_Encoder(LineFollower_normal_r, getMotorEncoder(wheelL) - MmToEncoder(300));

	Gyro_rotate.side = true;

	PID_Gyro_Rotate(Gyro_rotate, -36);

	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 36);

	Encoder_moveForTime(Encoder_move, 500, 30);

	clawOpened(true);
}


void DoTheJob_2()
{
	getOnTheParking();

	getTheBox();

	hangTheBox();
 }
