void getOnTheBlue()
{
	Gyro_rotate.oneSided = true;
	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 90);

	Gyro_move.moveSpeed = 30;

	Gyro_move.setpoint = getGyroDegrees(gyro);

	wait(10);

	Gyro_moveMm(Gyro_move, 80);

	PID_Gyro_Rotate(Gyro_rotate, 91);

	Gyro_move.setpoint = getGyroDegrees(gyro);

	Gyro_move.moveSpeed = -40;

	wait(10);

	PID_Gyro_On_ForTime(Gyro_move, 2500);

}

void getTheBox()
{
	Gyro_moveMm(Gyro_move, 115);

	PID_Gyro_Rotate(Gyro_rotate, 87);

	setHandUp(-10);

	clawOpened(true);

	Gyro_move.moveSpeed = 10;

	Gyro_moveMm(Gyro_move, 50);

	setHandUp(-42);

	clawOpened(false);

	wait(1000);

	setHandUp(-10);

	Gyro_moveMm(Gyro_move, -50);

	PID_Gyro_Rotate(Gyro_rotate, -86);

	PID_LineFollower_On_Until_Encoder(LineFollower_normal_r, getMotorEncoder(wheelL) - MmToEncoder(450));

	Gyro_rotate.side = true;

	wait(1000);

	PID_Gyro_Rotate(Gyro_rotate, -35);

	wait(1000);

	Gyro_rotate.side = false;

	PID_Gyro_Rotate(Gyro_rotate, 35);

	setHandUp(-30);

	Gyro_move.setpoint = getGyroDegrees(gyro);

	Gyro_move.moveSpeed = 30;

	wait(10);

	PID_Gyro_On_ForTime(Gyro_move, 500);

	clawOpened(true);
}


void DoTheJob_2()
{
	getOnTheBlue();

	getTheBox();
}
