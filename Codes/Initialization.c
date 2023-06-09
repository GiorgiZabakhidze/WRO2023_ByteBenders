void Initializate()
{
	float middle = (cBlack + cWhite) / 2;
	PID_init(&Encoder_move, 2.5, 0, 0.0, 0.000666666, 80, -80, 0, 30);
	PID_init(&Hand_normal, 10, 1.5, 0.8, 0.000666666, 80, -80, 0, 0);
	PID_init(&LineFollower_normal_r, 0.19, 0.009, 0.0042, 0.000666666, 80, -80, middle - 2, 30);
	PID_init(&LineFollower_normal_l, 0.2, 0.009, 0.0042, 0.000666666, 80, -80, middle - 2, 30);
	PID_init(&LineFollower_sonic_r, 0.87, 0.003, 0.0035, 0.000666666, 100, -100, middle, 70);
	PID_init(&LineFollower_sonic_l, 0.8, 0.003, 0.0033, 0.000666666, 100, -100, middle - 3, 70);
	PID_init(&LineFollower_fast_r, 0.27, 0.003, 0.006, 0.000666666, 80, -80, middle + 3, 45);
	PID_init(&LineFollower_fast_l, 0.28, 0.003, 0.01, 0.000666666, 80, -80, middle, 45);
	PID_init(&LineFollower_ship_l, 0.24, 0.012, 0.006, 0.000666666, 80, -80, middle - 2, 30);
	PID_init(&LineFollower_slow_l, 0.19, 0.008, 0.004, 0.000666666, 80, -80, middle - 2, 15);
	PID_init(&LineFollower_slow_r, 0.19, 0.008, 0.004, 0.000666666, 80, -80, middle - 2, 15);
	PID_init(&Gyro_rotate, 3, 0.002, 0., 0.000666666, 80, -80, 0, 0);
	PID_init(&Gyro_move_fast, 10, 0.2, 0.005, 0.000666666, 80, -80, 0, 45);
	PID_init(&Gyro_move, 4, 0.01, 0.00, 0.000666666, 80, -80, 0, 30);
	PID_init(&Encoder_move_fast, 3.5, 0.05, 0.025, 0.000666666, 80, -80, 0, 60);
	PID_init(&Encoder_rotate, 1, 0, 0, 0.000666666, 80, -80, 0, 0);

	LineFollower_slow_l.lineCorrectionTime = 1500;
	LineFollower_slow_l.rev = -1;

	LineFollower_ship_l.lineCorrectionTime = 1500;
	LineFollower_ship_l.rev = -1;

	LineFollower_slow_r.lineCorrectionTime = 1500;
	LineFollower_slow_r.rev = 1;

	LineFollower_normal_r.lineCorrectionTime = 1500;
	LineFollower_normal_r.rev = 1;

	LineFollower_normal_l.lineCorrectionTime = 1500;
	LineFollower_normal_l.rev = -1;

	LineFollower_fast_r.lineCorrectionTime = 1500;
	LineFollower_fast_r.rev = 1;

	LineFollower_fast_l.lineCorrectionTime = 1500;
	LineFollower_fast_l.rev = -1;

	LineFollower_sonic_r.lineCorrectionTime = 1500;
	LineFollower_sonic_r.rev = 1;

	LineFollower_sonic_l.lineCorrectionTime = 1500;
	LineFollower_sonic_l.rev = -1;

	Gyro_rotate.acceptableRange = 1;

	Gyro_rotate.additionTime = 9990;
	Gyro_rotate.additionMultiplier = 0;

	Gyro_move.additionTime = 1000;
	Gyro_move.additionMultiplier = 0;

	Gyro_move_fast.additionTime = 700;
	Gyro_move_fast.additionMultiplier = 0;

	Hand_normal.setpoint = 0;
	Hand_normal.acceptableRange = 5;

	resetGyro(gyro);
	setMotorSpeed(claw, 15);
	setMotorSpeed(hand, -30);

	wait(1000);

	setMotorSpeed(hand, 0);

	resetMotorEncoder(motorA);
	resetMotorEncoder(motorB);
	resetMotorEncoder(motorC);
	resetMotorEncoder(motorD);

	setMotorSpeed(claw, -15);

	clearTimer(T1);

	for(int i = 0; i < 5; i++)
	{
		task_usage[i].use = none;
		task_prevUsage[i].use = none;
	}

	startTask(Cimcimi);
	startTask(PID_LineFollower);
	startTask(PID_gyro);
	startTask(PID_Hand);
	startTask(PID_Encoder);
}
