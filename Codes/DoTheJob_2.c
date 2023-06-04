void getOnTheBlue()
{
	Gyro_rotate.oneSided = true;
	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 90);

	Gyro_moveMm(Gyro_move, 75);

	PID_Gyro_Rotate(Gyro_rotate, 89);

	Encoder_moveForTime(Encoder_move, 2500, -40);

}

void getTheBox()
{
	Gyro_moveMm(Gyro_move, 115);

	PID_Gyro_Rotate(Gyro_rotate, 87);

	setHandUp(-10);

	clawOpened(true);

	Gyro_move.moveSpeed = 10;

	Encoder_moveMm(Encoder_move, 15);

	setHandUp(-40);

	//clawOpened(false);

	setMotorSpeed(claw, -15);

	wait(1000);

	setHandUp(-25);
}

void hangTheBox()
{
	PID_Gyro_Rotate(Gyro_rotate, -86);

	PID_LineFollower_On_Until_Encoder(LineFollower_normal_r, getMotorEncoder(wheelL) - MmToEncoder(455));

	Gyro_rotate.side = true;

	PID_Gyro_Rotate(Gyro_rotate, -35);

	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 35);

	Gyro_moveForTime(Gyro_move, 500, 30);

	clawOpened(true);
}


void DoTheJob_2()
{
	getOnTheBlue();

	getTheBox();

	hangTheBox();
}
