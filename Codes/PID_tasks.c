/* Indeqsebis Shesabamisi PID:

	 0 - LineFollower
	 1 - Gyro

*/

bool task_using[5] = {false, false, false, false, false}; // Gamoyenebulia Tu Ara Indeqsis Shesabamisi Task-i

float task_rev; // Xazis Marjvnivaa Tu Marcxniv Shesabamis Indeqsze Myopi PID(Mxolod Line Follower Iyenebs)

PID *tasks[5]; // Shesabamis Indeqsze Myopi PID-s pointer-i


task PID_LineFollower() // Amushavebs PID-s Romelic Akontrolebs Borblebs Color Sensor-is Mixedvit
{
	repeat(forever) // Task-ebi Arian Mudmivar Chaciklulebi.
	{
		bool odd = true;
		while(task_using[0]) // Mushaobs Tu Globaluri Chartulia Am PID-stvis
		{
			// Vanaxlebt PID-s Output-s
			PID_Update(tasks[0], tasks[0]->setpoint, getColorReflected(color1));

			if(odd)
			{
				// Vurtavt Shesabamis Motorebze
				setMotorSpeed(wheelR, tasks[0]->moveSpeed - tasks[0]->out * task_rev);
				setMotorSpeed(wheelL, tasks[0]->moveSpeed + tasks[0]->out * task_rev);
			}
			else
			{
				// Vurtavt Shesabamis Motorebze
				setMotorSpeed(wheelL, tasks[0]->moveSpeed + tasks[0]->out * task_rev);
				setMotorSpeed(wheelR, tasks[0]->moveSpeed - tasks[0]->out * task_rev);
			}
			odd = !odd;
			if(!task_using[0])
			{
				stopWheels();
			}
		}
	}
}


task PID_gyro() // Amushavebs PID-s Romelic Akontrolebs Borblebs Gyro-s Mixedvit
{
	repeat(forever)
	{
		bool odd = true;
		while(task_using[1]) // Mushaobs Tu Globaluri Chartulia Am PID-stvis
		{
			PID_Update(tasks[1], tasks[1]->setpoint, getGyroDegrees(gyro));

			if(odd)
			{
				setMotorSpeed(wheelR, tasks[1]->moveSpeed - tasks[1]->out);
				setMotorSpeed(wheelL, tasks[1]->moveSpeed + tasks[1]->out);
			}
			else
			{
				setMotorSpeed(wheelL, tasks[1]->moveSpeed + tasks[1]->out);
				setMotorSpeed(wheelR, tasks[1]->moveSpeed - tasks[1]->out);
			}
			odd = !odd;
			if(!task_using[1])
			{
				stopWheels();
			}
		}
	}
}

task PID_gyro_oneSided()
{
	repeat(forever)
	{
		while(task_using[2])
		{
			PID_Update(tasks[2], tasks[2]->setpoint, getGyroDegrees(gyro));

			if(tasks[2]->side)
			{
				setMotorSpeed(wheelR, tasks[2]->moveSpeed + tasks[2]->out);
			}
			else
			{
				setMotorSpeed(wheelL, tasks[2]->moveSpeed + tasks[2]->out);
			}
			if(!task_using[2])
			{
				stopWheels();
			}
		}
	}
}

task PID_Hand()
{
	repeat(forever)
	{
		while(task_using[3])
		{
			PID_Update(tasks[3], tasks[3]->setpoint, getMotorEncoder(hand));

			setMotorSpeed(hand, tasks[3]->out);

	//displayBigTextLine(1, "%f", getMotorEncoder(hand));
	//displayBigTextLine(3, "%f", tasks[3]->out);
		}
	}
}
task PID_Claw()
{
	repeat(forever)
	{
		while(task_using[4])
		{
			PID_Update(tasks[4], tasks[4]->setpoint, getMotorEncoder(claw));

			setMotorSpeed(claw, tasks[4]->moveSpeed + tasks[4]->out);
		}
	//displayBigTextLine(1, "%f", getMotorEncoder(claw));
	}
}
