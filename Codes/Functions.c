/*
	// ROBOTI UNDA IYOS GACHEREBULI AM PUNQSIIC GAMOYENEBAMDE //

	Abrunebs Color Checker-i Sensoris Mnishvnelobas Upro Zustad

	return Sensoris Mnishvneloba
*/
int ColorCheck()
{
	bool currentStatus = checkStatus;

	while(currentStatus == checkStatus){}

	float cntGreen = 0;
	float checkAmount = 10;
	float requiredPercentage = 0.2;

	for(int i = 0; i < checkAmount; i++)
	{
		while(currentStatus == checkStatus){}

		if(checkedColor == 3)
		{
			cntGreen++;
		}

		currentStatus = checkStatus;
	}

	bool ans = ((cntGreen / checkAmount) >= requiredPercentage);

	if(ans)
	{
		playSound(soundBeepBeep);
		return 3;
	}

	playSound(soundBlip);
	return 2;
}

void setHandUp(int encoderVal)
{
	handUp(encoderVal);

	while(!inRange(getMotorEncoder(hand), -encoderVal, Hand_normal.acceptableRange)){}
}

void simpleMoveMm(float Mm, int speed = 20)
{
	float encoderVal = MmToEncoder(Mm);

	float targetR = getMotorTarget(wheelR) + encoderVal;
	float targetL = getMotorTarget(wheelL) - encoderVal;

	bool doneR = false, doneL = false;

	setMotorSpeed(wheelR, 30);
	setMotorSpeed(wheelL, 30);

	while(!doneR || !doneL)
	{
		if(!doneL)
			doneL = inRange(getMotorEncoder(wheelL), targetL, speed);

		if(!doneR)
			doneR = inRange(getMotorEncoder(wheelR), targetR, speed);

		if(doneL)
		{
			setMotorSpeed(wheelL, 0);
		}
		if(doneR)
		{
			setMotorSpeed(wheelR, 0);
		}

	}
	playSound(soundBlip);
}

void Gyro_moveMm(PID* pid, float Mm, float speed = 0)
{
	pid->setpoint = getGyroDegrees(gyro);

	if(speed == 0)
	{
		if(Mm > 0)
		{
			pid->moveSpeed = abs(pid->moveSpeed);
		}
		else
		{
			pid->moveSpeed = -abs(pid->moveSpeed);
		}
	}
	else
	{
		if(Mm > 0)
		{
			pid->moveSpeed = abs(speed);
		}
		else
		{
			pid->moveSpeed = -abs(speed);
		}
	}

	wait(10);

	PID_Gyro_On_Until_Encoder(pid, getMotorEncoder(wheelL) - MmToEncoder(Mm));

	while(task_usage[1].use != none){}
}

void Gyro_moveForTime(PID* pid, float time, float speed = 0)
{
	pid->setpoint = getGyroDegrees(gyro);

	if(speed != 0)
		pid->moveSpeed = speed;

	wait(10);

	PID_Gyro_On_ForTime(pid, time);
}

void Gyro_moveUntilReflected(PID* pid, float reflection, float speed = 0)
{
	pid->setpoint = getGyroDegrees(gyro);

	if(speed != 0)
		pid->moveSpeed = speed;

	wait(10);

	PID_Gyro_On_Until_Reflected(pid, reflection);
}

void Encoder_moveMm(PID* pid, float Mm, float speed = 0)
{
	pid->setpoint = getGyroDegrees(gyro);

	if(speed == 0)
	{
		if(Mm > 0)
		{
			pid->moveSpeed = abs(pid->moveSpeed);
		}
		else
		{
			pid->moveSpeed = -abs(pid->moveSpeed);
		}
	}
	else
	{
		if(Mm > 0)
		{
			pid->moveSpeed = abs(speed);
		}
		else
		{
			pid->moveSpeed = -abs(speed);
		}
	}

	wait(10);

	PID_Gyro_On_Until_Encoder(pid, getMotorEncoder(wheelL) - MmToEncoder(Mm));

	while(task_usage[2].use != none){}
}

void Encoder_moveForTime(PID* pid, float time, float speed = 0)
{
	pid->setpoint = getMotorEncoder(wheelR) + getMotorEncoder(wheelL);

	if(speed != 0)
		pid->moveSpeed = speed;

	wait(10);

	PID_Encoder_On_ForTime(pid, time);
}

void Encoder_moveUntilReflected(PID* pid, float reflection, float speed = 0)
{
	pid->setpoint = getMotorEncoder(wheelR) + getMotorEncoder(wheelL);

	if(speed != 0)
		pid->moveSpeed = speed;

	wait(10);

	PID_Encoder_On_Until_Reflected(pid, reflection);
}
