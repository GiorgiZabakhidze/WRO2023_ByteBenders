void Initializate()
{
	resetMotorEncoder(claw);

	resetMotorEncoder(hand);

	resetGyro(gyro);


	PID_init(&pid_lineFollower, 0.23, 0.000034, 0.12, 0.0004, 60, -60, 30, 40);

}
