void goToTheBigShip()
{
	Encoder_moveMm(Encoder_move, -30);

	Gyro_rotate.side = false

	PID_Gyro_Rotate(Gyro_rotate, -90);

	Gyro_rotate.side = true;

	PID_Gyro_Rotate(Gyro_rotate, -179);

	setHandUp(-35);
	clawOpened(true);
	wait(300);
	setHandUp(-20);
}
void DoTheJob_6()
{
	goToTheBigShip();
}
