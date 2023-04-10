/* Indeqsebis Shesabamisi PID:

	 0 - LineFollower
	 1 - Gyro

*/

bool task_using[3] = {false, false, false}; // Gamoyenebulia Tu Ara Indeqsis Shesabamisi Task-i

float task_setpoint[3]; // Shesamabis Indeqsze Myopi PID-s setpoint-i

float task_rev[1]; // Xazis Marjvnivaa Tu Marcxniv Shesabamis Indeqsze Myopi PID(Mxolod Line Follower Iyenebs)

PID *tasks[3]; // Shesabamis Indeqsze Myopi PID-s pointer-i


task PID_LineFollower() // Amushavebs PID-s Romelic Akontrolebs Borblebs Color Sensor-is Mixedvit
{
	repeat(forever) // Task-ebi Arian Mudmivar Chaciklulebi.
	{
		while(task_using[0]) // Mushaobs Tu Globaluri Chartulia Am PID-stvis
		{
			// Vanaxlebt PID-s Output-s
			PID_Update(tasks[0], task_setpoint[0], getColorReflected(color1));

			// Vurtavt Shesabamis Motorebze
			setMotorSpeed(wheelR, tasks[0]->moveSpeed - tasks[0]->out * task_rev[0]);
			setMotorSpeed(wheelL, tasks[0]->moveSpeed + tasks[0]->out * task_rev[0]);

			// Vicdit Axal Update-amde PID-s Updat-ebs Shoris CONST Droit
			wait(tasks[0]->T);
		}
	}
}


task PID_gyro() // Amushavebs PID-s Romelic Akontrolebs Borblebs Gyro-s Mixedvit
{
	repeat(forever)
	{
		while(task_using[1]) // Mushaobs Tu Globaluri Chartulia Am PID-stvis
		{
			PID_Update(tasks[1], task_setpoint[1], getGyroDegrees(gyro));

			setMotorSpeed(wheelR, tasks[1]->moveSpeed - tasks[1]->out);
			setMotorSpeed(wheelL, tasks[1]->moveSpeed + tasks[1]->out);

			wait(tasks[1]->T); // Vicdit Axal Update-amde PID-s Updat-ebs Shoris CONST Droit
		}
	}
}
