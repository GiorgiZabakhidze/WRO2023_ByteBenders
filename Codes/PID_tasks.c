task PID_LineFollower() // Amushavebs PID-s Romelic Akontrolebs Borblebs Color Sensor-is Mixedvit
{
	bool odd = true;
	int startTime = 0;
	bool factor = false;
	int successStart = 0;
	repeat(forever) // Task-ebi Arian Mudmivar Chaciklulebi.
	{
		calculateFactor(0, startTime, factor);

		if(factor)
		{
			successStart = time1(T1);
		}

		int doneFor = timer_count(successStart, time1(T1));

		if(factor && !(task_usage[0].use == on_untilDone && doneFor >= 20)) // Mushaobs Tu Factor Aris Chartuli
		{
			// Vanaxlebt PID-s Output-s
			PID_Update(tasks[0], tasks[0]->setpoint, getColorReflected(color1));

			//if(odd)
			//{
				// Vurtavt Shesabamis Motorebze
				setMotorSpeed(wheelR, tasks[0]->moveSpeed - tasks[0]->out * tasks[0]->rev);
				setMotorSpeed(wheelL, tasks[0]->moveSpeed + tasks[0]->out * tasks[0]->rev);
			//}
			//else
			//{
			//	// Vurtavt Shesabamis Motorebze
			//	setMotorSpeed(wheelL, tasks[0]->moveSpeed + tasks[0]->out * task_rev);
			//	setMotorSpeed(wheelR, tasks[0]->moveSpeed - tasks[0]->out * task_rev);
			//}
			odd = !odd;

			if(task_usage[0] == none)
			{
				stopWheels();
			}
		}
		else if(task_prevUsage[0] != none)
		{
			task_usage[0].use = none;
			stopWheels();
			odd = true;
		}
	}
}


task PID_gyro() // Amushavebs PID-s Romelic Akontrolebs Borblebs Gyro-s Mixedvit
{
	bool odd = true;
	int startTime = 0;
	bool factor = false;
	int successStart = 0;
	repeat(forever) // Task-ebi Arian Mudmivar Chaciklulebi.
	{
		calculateFactor(1, startTime, factor);

		if(factor)
		{
			successStart = time1(T1);
		}

		int doneFor = timer_count(successStart, time1(T1));


		if(factor && !(task_usage[1].use == on_untilDone && doneFor >= 20)) // Mushaobs Tu Factor Aris Chartuli
		{
			PID_Update(tasks[1], tasks[1]->setpoint, getGyroDegrees(gyro));
			//if(odd)
			//{
			float addition = 0;

			if(timer_count(startTime, time1(T1)) < tasks[1]->additionTime)
				addition = tasks[1]->moveSpeed * tasks[1]->additionMultiplier;

				setMotorSpeed(wheelR, tasks[1]->moveSpeed - tasks[1]->out + addition);
				setMotorSpeed(wheelL, tasks[1]->moveSpeed + tasks[1]->out);
			//}
			//else
			//{
			//	setMotorSpeed(wheelL, tasks[1]->moveSpeed + tasks[1]->out);
			//	setMotorSpeed(wheelR, tasks[1]->moveSpeed - tasks[1]->out);
			//}
			odd = !odd;

			if(task_usage[1] == none)
			{
				stopWheels();
			}
		}
		else if(task_prevUsage[1] != none)
		{
			task_usage[1].use = none;
			stopWheels();
			odd = true;
		}
	}
}

task PID_gyro_oneSided()
{
	int startTime = 0;
	bool factor = false;
	int successStart = 0;
	repeat(forever) // Task-ebi Arian Mudmivar Chaciklulebi.
	{
		calculateFactor(2, startTime, factor);

		if(factor)
		{
			successStart = time1(T1);
		}

		int doneFor = timer_count(successStart, time1(T1));


		if(factor && !(task_usage[2].use == on_untilDone && doneFor >= 20)) // Mushaobs Tu Factor Aris Chartuli
		{
			PID_Update(tasks[2], tasks[2]->setpoint, getGyroDegrees(gyro));

			if(tasks[2]->oneSided)
			{
				if(tasks[2]->side)
				{
					setMotorSpeed(wheelR, tasks[2]->moveSpeed - tasks[2]->out);
				}
				else
				{
					setMotorSpeed(wheelL, tasks[2]->moveSpeed + tasks[2]->out);
				}
			}
			else
			{
				if(tasks[2]->side)
				{
					setMotorSpeed(wheelR, tasks[2]->moveSpeed + tasks[2]->out);
				}
				else
				{
					setMotorSpeed(wheelL, tasks[2]->moveSpeed - tasks[2]->out);
				}
			}
			if(task_usage[2] == none)
			{
				stopWheels();
			}
		}
		else if(task_prevUsage[2] != none)
		{
			task_usage[2] = none;
			stopWheels();
		}
	}
}

task PID_Hand()
{
	repeat(forever) // Task-ebi Arian Mudmivar Chaciklulebi.
	{
		PID_Update(Hand_normal, Hand_normal.setpoint, getMotorEncoder(hand));

		setMotorSpeed(hand, Hand_normal.out);
	}
}
task PID_Encoder()
{
	bool odd = true;
	int startTime = 0;
	bool factor = false;
	int successStart = 0;
	repeat(forever) // Task-ebi Arian Mudmivar Chaciklulebi.
	{
		calculateFactor(4, startTime, factor);

		if(factor)
		{
			successStart = time1(T1);
		}

		int doneFor = timer_count(successStart, time1(T1));

		if(factor && !(task_usage[4].use == on_untilDone && doneFor >= 20)) // Mushaobs Tu Factor Aris Chartuli
		{
			// Vanaxlebt PID-s Output-s
			PID_Update(tasks[4], tasks[4]->setpoint, getMotorEncoder(wheelR) - getMotorEncoder(wheelL));

			//if(odd)
			//{
				// Vurtavt Shesabamis Motorebze
				setMotorSpeed(wheelR, tasks[4]->moveSpeed - tasks[4]->out);
				setMotorSpeed(wheelL, tasks[4]->moveSpeed + tasks[4]->out);
			//}
			//else
			//{
			//	// Vurtavt Shesabamis Motorebze
			//	setMotorSpeed(wheelL, tasks[4]->moveSpeed + tasks[4]->out);
			//	setMotorSpeed(wheelR, tasks[4]->moveSpeed - tasks[4]->out);
			//}
			odd = !odd;

			if(task_usage[4] == none)
			{
				stopWheels();
			}
		}
		else if(task_prevUsage[4] != none)
		{
			task_usage[4].use = none;
			stopWheels();
			odd = true;
		}
	}
}
