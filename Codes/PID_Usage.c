enum pidType{LineFollower, Gyro, Gyro_OneSided, Hand};
enum useType{none, on_always, on_untilDone, forTime,
						untilReflected_high, untilReflected_low,
						untilEncoder_high, untilEncoder_low,
						untilDegree_high, untilDegree_low,
						untilDistance_far, untilDistance_close};
struct usage
{
	useType use;
	pidType pid_type;
	float time;
	float reflection;
	float distance;
	float encoder;
	float degree;
	int motorN;
}
/* Indeqsebis Shesabamisi PID:

	 0 - LineFollower
	 1 - Gyro

*/

float task_rev = 1; // Xazis Marjvnivaa Tu Marcxniv Shesabamis Indeqsze Myopi PID(Mxolod Line Follower Iyenebs)

PID *tasks[5]; // Shesabamis Indeqsze Myopi PID-s pointer-i

usage task_usage[5]; // Ra Tipis Gamoyeneba Aqvt PID-s

usage task_prevUsage[5]; // Wina Iteraciis Usage

PID *previouslyUsedPID;


void calculateFactor(int i, int &startTime, bool &factor)
{
	if(task_prevUsage[i].use == none && task_usage[i].use != none)
		{
			factor = true;

			startTime = time1(T1);
		}

		task_prevUsage[i] = task_usage[i];

		if(factor)
		{
			switch(task_usage[i].use)
			{
				case none:
					factor = false;

				case on_untilDone:
					switch(task_usage[i].pid_type)
					{
						case LineFollower:
							factor = inRange(getColorReflected(color1), tasks[i]->setpoint, tasks[i]->acceptableRange);

						case Gyro:
							factor = inRange(getGyroDegrees(gyro), tasks[i]->setpoint, tasks[i]->acceptableRange);

						case Gyro_OneSided:
							factor = inRange(getGyroDegrees(gyro), tasks[i]->setpoint, tasks[i]->acceptableRange);

						case Hand:
							factor = inRange(getMotorEncoder(hand), tasks[i]->setpoint, tasks[i]->acceptableRange);
					}

				case forTime:
					factor = (bool)(timer_count(startTime, time1(T1)) < task_usage[0].time);

				case untilReflected_high:
					factor = (bool)(getColorReflected(color1) < task_usage[i].reflection);

				case untilReflected_low:
					factor = (bool)(getColorReflected(color1) > task_usage[i].reflection);

				case untilEncoder_high:
					if(task_usage.motorN == 1)
						factor = (bool)(getMotorEncoder(motorA) < task_usage[i].encoder);
					if(task_usage.motorN == 2)
						factor = (bool)(getMotorEncoder(motorB) < task_usage[i].encoder);
					if(task_usage.motorN == 3)
						factor = (bool)(getMotorEncoder(motorC) < task_usage[i].encoder);
					if(task_usage.motorN == 4)
						factor = (bool)(getMotorEncoder(motorD) < task_usage[i].encoder);

				case untilEncoder_low:
					if(task_usage.motorN == 1)
						factor = (bool)(getMotorEncoder(motorA) > task_usage[i].encoder);
					if(task_usage.motorN == 2)
						factor = (bool)(getMotorEncoder(motorB) > task_usage[i].encoder);
					if(task_usage.motorN == 3)
						factor = (bool)(getMotorEncoder(motorC) > task_usage[i].encoder);
					if(task_usage.motorN == 4)
						factor = (bool)(getMotorEncoder(motorD) > task_usage[i].encoder);

				case untilDegree_high:
					factor = (bool)(getGyroDegrees(gyro) < task_usage[i].degree);

				case untilDegree_low:
					factor = (bool)(getGyroDegrees(gyro) > task_usage[i].degree);

				// ultra sonic win uyenia robots
				case untilDistance_far:
					factor = (bool)(getUSDistance(usonic) > task_usage[i].distance);

				case untilDistance_close:
					factor = (bool)(getUSDistance(usonic) < task_usage[i].distance);
			}
		}
}

void setUsage(int i, useType use, int coefficient, pidType pid_type)
{
	switch (use)
	{
		case forTime:
			task_usage[i].time = coefficient;

		case untilReflected_high:
			task_usage[i].reflection = coefficient;

		case untilReflected_low:
			task_usage[i].reflection = coefficient;

		case untilEncoder_high:
			task_usage[i].encoder = coefficient;

		case untilEncoder_low:
			task_usage[i].encoder = coefficient;
	}

	task_usage[i].pid_type = pid_type;
	task_usage[i].use = use;
}
