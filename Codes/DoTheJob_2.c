void getOnTheParking()
{
	//LineFollower_slow_r.lineCorrectionTime = 750;

	//PID_FollowLine_Until_Reflected(LineFollower_slow_r, cBlack + 1);

	//Encoder_moveUntilReflected(Encoder_move, cWhite, 30);

	//Gyro_rotate.oneSided = true;
	//Gyro_rotate.side = false;

	//PID_Gyro_Rotate(Gyro_rotate, 92);

	Encoder_moveForTime(Encoder_move, 1500, -40);
}

void getTheRedBox()
{
	handUp(-20);
	setMotorSpeed(claw, 15);

	Encoder_moveMm(Encoder_move, 115);

	PID_Gyro_Rotate(Gyro_rotate, 87);

	Encoder_move.moveSpeed = 10;

	Encoder_moveMm(Encoder_move, 30);

	Encoder_move.moveSpeed = 30;

	Gyro_move.moveSpeed = 10;

	setHandUp(-49);

	setMotorSpeed(claw, -40);

	wait(1000);

	setHandUp(-20);
}

void hangTheBox()
{
	Encoder_moveUntilReflected(Encoder_move, cWhite - 5, -30);

	Encoder_moveMm(Encoder_move, -130);

	Gyro_rotate.side = true;

	PID_Gyro_Rotate(Gyro_rotate, -86);

	//gripStrength = 15;

	//handUp(-80);

	PID_LineFollower_On_Until_Encoder(LineFollower_fast_r, getMotorEncoder(wheelL) - MmToEncoder(280));

	setHandUp(-39);

	Gyro_rotate.side = true;

	PID_Gyro_Rotate(Gyro_rotate, -37);

	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 37);

	Encoder_moveForTime(Encoder_move, 500, 30);

	clawOpened(true, 200);
}


void DoTheJob_2()
{
	getOnTheParking();

	getTheRedBox();

	hangTheBox();
 }
