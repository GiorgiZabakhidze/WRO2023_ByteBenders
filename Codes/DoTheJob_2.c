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
	startResetingHand();
	setMotorTarget(claw, -110, 15);

	Encoder_moveMm(Encoder_move, 105);

	PID_Gyro_Rotate(Gyro_rotate, 87);

	Encoder_move.moveSpeed = 10;

	Encoder_moveMm(Encoder_move, 30);

	wait(100);

	endResetingHand();

	Encoder_move.moveSpeed = 30;

	Gyro_move.moveSpeed = 10;

	wait(100);

	setHandUp(-48);

	setMotorSpeed(claw, -40);

	wait(900);

	setHandUp(-20);
}

void hangTheBox()
{
	Encoder_moveUntilReflected(Encoder_move, cWhite - 5, -30);

	Encoder_moveMm(Encoder_move, -130);

	Gyro_rotate.side = true;

	PID_Gyro_Rotate(Gyro_rotate, -86);

	gripStrength = 10;

	setHandUp(-80);

	Hand_normal.setpoint = 40;

	startResetingHand();

	PID_LineFollower_On_Until_Encoder(LineFollower_fast_r, getMotorEncoder(wheelL) - MmToEncoder(265));

	wait(300);

	endResetingHand();

	wait(300);

	setHandUp(-50);

	Gyro_rotate.side = true;

	PID_Gyro_Rotate(Gyro_rotate, -39);

	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 39);

	Encoder_moveForTime(Encoder_move, 700, 25);

	clawOpened(true, 300);
}


void DoTheJob_2()
{
	getOnTheParking();

	getTheRedBox();

	hangTheBox();
}
