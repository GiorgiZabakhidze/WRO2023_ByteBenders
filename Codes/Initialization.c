void Initializate()
{
	PID_init(&Hand_normal, 1.3, 0.09, 0.03, 0.000666666, 80, -80, 0, 0);
	PID_init(&LineFollower_normal_r, 0.41, 0.0005, 0.0013, 0.000666666, 80, -80, 45, 30);
	PID_init(&LineFollower_normal_l, 0.39, 0.00005, 0.0003, 0.000666666, 80, -80, 65, 30);
	PID_init(&Gyro_rotate, 1.5, 0.001, 0., 0.000666666, 80, -80, 0, 0);
	PID_init(&Gyro_mover, 2, 0.3, 0.001, 0.000666666, 80, -80, 0, 20);
	PID_init(&Gyro_mover_fast, 10, 0.2, 0.005, 0.000666666, 80, -80, 0, 55);
	PID_init(&Claw_normal, 3, 0.0, 0.0, 0.00043, 80, -80, 0, 0);
	PID_init(&Encoder_normal, 5, 0.2, 2, 0.000666666, 80, -80, 0, 20);

	LineFollower_normal_r.lineCorrectionTime = 1500;
	LineFollower_normal_l.lineCorrectionTime = 1500;

	Gyro_rotate.acceptableRange = 1;

	Gyro_rotate.additionTime = 9990;
	Gyro_rotate.additionMultiplier = 0.5;

	Gyro_mover.additionTime = 250;
	Gyro_mover.additionMultiplier = 0.3;

	Gyro_mover_fast.additionTime = 700;
	Gyro_mover_fast.additionMultiplier = 0.5;

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

	startTask(Cimcimi);
	startTask(PID_LineFollower);
	startTask(PID_gyro);
	startTask(PID_gyro_oneSided);
	startTask(PID_Hand);

	Hand_normal.setpoint = 0;
	//PID_Hand_Start(on_always, -10);
}
