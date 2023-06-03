enum pidType{LineFollower, Gyro, Gyro_OneSided, Hand, Encoder};
enum useType{none, on_always, on_untilDone, forTime,
						untilReflected_high, untilReflected_low,
						untilEncoder_high, untilEncoder_low,
						untilDegree_high, untilDegree_low,
						untilDistance_far, untilDistance_close};
struct usage
{
	useType use;
	pidType pid_type;
	int _setpoint;
	int motorN;
}usage;
/* Indeqsebis Shesabamisi PID:

	 0 - LineFollower
	 1 - Gyro

*/

PID* tasks[5]; // Shesabamis Indeqsze Myopi PID-s pointer-i

usage task_usage[5]; // Ra Tipis Gamoyeneba Aqvt PID-s

usage task_prevUsage[5]; // Wina Iteraciis Usage

PID* previouslyUsedPID;


void calculateFactor(int i, int &startTime, bool &factor)
{
	if(task_usage[i].use != none)
		{
			factor = true;

			if(task_prevUsage[i].use == none)
			{
				startTime = time1(T1);
			}
		}

		task_prevUsage[i] = task_usage[i];

		if(factor)
		{
			switch(task_usage[i].use)
			{
			case none:
				factor = false;
				break;

			case on_untilDone:
				switch(task_usage[i].pid_type)
				{
				case LineFollower:
					factor = !inRange(getColorReflected(color1), tasks[i]->setpoint, tasks[i]->acceptableRange);
					break;
				case Gyro:
					factor = !inRange(getGyroDegrees(gyro), tasks[i]->setpoint, tasks[i]->acceptableRange);
					break;
				case Gyro_OneSided:
					factor = !inRange(getGyroDegrees(gyro), tasks[i]->setpoint, tasks[i]->acceptableRange);
					break;
				case Hand:
					factor = !inRange(getMotorEncoder(hand), tasks[i]->setpoint, tasks[i]->acceptableRange);
					break;
				case Encoder:
					factor = !inRange(getMotorEncoder(wheelR) + getMotorEncoder(wheelL), tasks[i]->setpoint, tasks[i]->acceptableRange);
					break;
				}
				break;


			case forTime:
				factor = (bool)(timer_count(startTime, time1(T1)) < task_usage[i]._setpoint);
				break;

			case untilReflected_high:
				factor = (bool)(getColorReflected(color1) < task_usage[i]._setpoint);
				break;

			case untilReflected_low:
				factor = (bool)(getColorReflected(color1) > task_usage[i]._setpoint);
				break;

			case untilEncoder_high:
				if(task_usage[i].motorN == 1)
					factor = (bool)(getMotorEncoder(motorA) < task_usage[i]._setpoint);
				else if(task_usage[i].motorN == 2)
					factor = (bool)(getMotorEncoder(motorB) < task_usage[i]._setpoint);
				else if(task_usage[i].motorN == 3)
					factor = (bool)(getMotorEncoder(motorC) < task_usage[i]._setpoint);
				else if(task_usage[i].motorN == 4)
					factor = (bool)(getMotorEncoder(motorD) < task_usage[i]._setpoint);
				break;

			case untilEncoder_low:
				if(task_usage[i].motorN == 1)
					factor = (bool)(getMotorEncoder(motorA) > task_usage[i]._setpoint);
				else if(task_usage[i].motorN == 2)
					factor = (bool)(getMotorEncoder(motorB) > task_usage[i]._setpoint);
				else if(task_usage[i].motorN == 3)
					factor = (bool)(getMotorEncoder(motorC) > task_usage[i]._setpoint);
				else if(task_usage[i].motorN == 4)
					factor = (bool)(getMotorEncoder(motorD) > task_usage[i]._setpoint);
				break;

			case untilDegree_high:
				factor = (bool)(getGyroDegrees(gyro) < task_usage[i]._setpoint);
				break;

			case untilDegree_low:
				factor = (bool)(getGyroDegrees(gyro) > task_usage[i]._setpoint);
				break;

				// ultra sonic win uyenia robots
			case untilDistance_far:
				factor = (bool)(getUSDistance(usonic) > task_usage[i]._setpoint);
				break;

			case untilDistance_close:
				factor = (bool)(getUSDistance(usonic) < task_usage[i]._setpoint);
				break;
			}
		}
}

void setUsage(int i, useType use, int _setpoint, pidType pid_type)
{
	task_usage[i]._setpoint = _setpoint;

	task_usage[i].pid_type = pid_type;

	task_usage[i].use = use;
}
