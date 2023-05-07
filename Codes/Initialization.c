void Initializate()
{
	startTask(PID_LineFollower);
	startTask(PID_gyro);
	startTask(PID_Hand);
	startTask(PID_Claw);



	//setMotorSpeed(hand, -5);
	//sleep(500);
	//setMotorTarget(hand, getMotorTarget(hand) - 10, -1);
	//sleep(500);

	//resetGyro(gyro);


}
