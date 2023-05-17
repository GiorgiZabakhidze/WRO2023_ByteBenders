void Initializate()
{
	startTask(Cimcimi);
	PID_init(&Hand_normal, 1, 0.09, 0.024, 0.000666666, 80, -80, 0, 0);

	setMotorSpeed(hand, -30);

	sleep(300);

	setMotorSpeed(hand, 0);

	sleep(100);

	resetMotorEncoder(motorA);
	resetMotorEncoder(motorB);
	resetMotorEncoder(motorC);
	resetMotorEncoder(motorD);

	resetGyro(gyro);

	sleep(1000);

	clearTimer(T1);

	for(int i = 0; i < 5; i++)
	{
		task_usage[i].use = none;
		task_prevUsage[i].use = none;
	}
	startTask(PID_LineFollower);
	startTask(PID_gyro);
	startTask(PID_gyro_oneSided);
	startTask(PID_Hand);

	Hand_normal.setpoint = 0;
	PID_Hand_Start(on_always, 0);
}
