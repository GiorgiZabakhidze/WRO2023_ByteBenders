/* Indeqsebis Shesabamisi PID:

	 0 - LineFollower
	 1 - Gyro

*/
bool task_using[3] = {false, false, false}; // Gamoyenebulia Tu Ara Indeqsis Shesabamisi Task-i

float task_setpoint[3]; // Shesamabis Indeqsze Myopi PID-s setpoint-i

float task_rev[1]; // Xazis Marjvnivaa Tu Marcxniv Shesabamis Indeqsze Myopi PID(Mxolod Line Follower Iyenebs)

PID *tasks[3]; // Shesabamis Indeqsze Myopi PID-s pointer-i


// Amushavebs PID-s Romelic Akontrolebs Borblebs Color Sensor-is Mixedvit
task PID_LineFollower()
{
	// Task-ebi Arian Mudmivar Chaciklulebi.
	repeat(forever)
	{
		// Vanaxlebt PID-s Output-s
		PID_Update(tasks[0], task_setpoint[0], getColorReflected(color1));

		// Vurtavt Shesabamis Motorebze
		setMotorSpeed(wheelR, tasks[0]->moveSpeed + tasks[0]->out * task_rev[0]);
		setMotorSpeed(wheelL, tasks[0]->moveSpeed - tasks[0]->out * task_rev[0]);

		// "Vsleepavt" Im Mudmivi Droit Rac PID-s Aqvt Sensorebis Gazomvebs Shoris.

			// Gasuli Dro
			float t = 0;

			// Dawyebis Dro
			float start_time = time1(T1);

			// Sanam Gasuli Dro Naklebia T-s Mudmivaze Manamde Ubralod Gasul Dros Vanaxlebt
			while(t < tasks[0]->T)
			{
				t = timer_count(start_time, time1(T1));
			}
	}
}


// Amushavebs PID-s Romelic Akontrolebs Borblebs Gyro-s Mixedvit
task PID_gyro()
{
	repeat(forever)
	{
		while(task_using[1])
		{
			PID_Update(tasks[1], task_setpoint[1], getGyroDegrees(gyro));

			setMotorSpeed(wheelR, tasks[1]->moveSpeed + tasks[1]->out);
			setMotorSpeed(wheelL, tasks[1]->moveSpeed - tasks[1]->out);
		}

		// "Vsleepavt" Im Mudmivi Droit Rac PID-s Aqvt Sensorebis Gazomvebs Shoris.

			// Gasuli Dro
			float t = 0;

			// Dawyebis Dro
			float start_time = time1(T1);

			// Sanam Gasuli Dro Naklebia T-s Mudmivaze Manamde Ubralod Gasul Dros Vanaxlebt
			while(t < tasks[1]->T)
			{
				t = timer_count(start_time, time1(T1));
			}
	}
}
