/* Indeqsebis Shesabamisi PID:

	 0 - LineFollower
	 1 - Gyro

*/

bool task_using[3] = {false, false, false}; // Gamoyenebulia Tu Ara Indeqsis Shesabamisi Task-i

float task_rev; // Xazis Marjvnivaa Tu Marcxniv Shesabamis Indeqsze Myopi PID(Mxolod Line Follower Iyenebs)

PID *tasks[3]; // Shesabamis Indeqsze Myopi PID-s pointer-i


task PID_LineFollower() // Amushavebs PID-s Romelic Akontrolebs Borblebs Color Sensor-is Mixedvit
{
	repeat(forever) // Task-ebi Arian Mudmivar Chaciklulebi.
	{
		while(task_using[0]) // Mushaobs Tu Globaluri Chartulia Am PID-stvis
		{
			// Vanaxlebt PID-s Output-s
			PID_Update(tasks[0], tasks[0]->setpoint, getColorReflected(color1));

			// Vurtavt Shesabamis Motorebze
			setMotorSpeed(wheelR, tasks[0]->moveSpeed - tasks[0]->out * task_rev);
			setMotorSpeed(wheelL, tasks[0]->moveSpeed + tasks[0]->out * task_rev);
		}
	}
}


task PID_gyro() // Amushavebs PID-s Romelic Akontrolebs Borblebs Gyro-s Mixedvit
{
	repeat(forever)
	{
		while(task_using[1]) // Mushaobs Tu Globaluri Chartulia Am PID-stvis
		{
			PID_Update(tasks[1], tasks[1]->setpoint, getGyroDegrees(gyro));

			setMotorSpeed(wheelR, tasks[1]->moveSpeed - tasks[1]->out);
			setMotorSpeed(wheelL, tasks[1]->moveSpeed + tasks[1]->out);
		}
	}
}
