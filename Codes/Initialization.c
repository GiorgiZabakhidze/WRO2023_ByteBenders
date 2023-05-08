void Initializate()
{
	startTask(PID_LineFollower);
	startTask(PID_gyro);
	startTask(PID_Hand);
	startTask(PID_Claw);


	resetMotorEncoder(hand);
	resetMotorEncoder(claw);

	resetGyro(gyro);

	sleep(1000);

}
