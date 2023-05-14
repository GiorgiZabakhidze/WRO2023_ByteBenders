void Initializate()
{
	for(int i = 0; i < 5; i++)
	{
		task_usage[i].use = none;
	}
	startTask(PID_LineFollower);
	startTask(PID_gyro);
	startTask(PID_gyro_oneSided);
	startTask(PID_Hand);


	resetMotorEncoder(hand);
	resetMotorEncoder(claw);

	resetGyro(gyro);

	sleep(1000);

}
