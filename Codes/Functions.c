/*
	// ROBOTI UNDA IYOS GACHEREBULI AM PUNQSIIC GAMOYENEBAMDE //

	Abrunebs Color Checker-i Sensoris Mnishvnelobas Upro Zustad

	return Sensoris Mnishvneloba
*/
int ColorCheck()
{
	bool currentStatus = checkStatus;

	wait(200);

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

void Gyro_moveMm(PID* pid, float Mm)
{
	Gyro_mover.setpoint = getGyroDegrees(gyro);

	int sign;

	if(Mm > 0)
	{
		sign = 1;

		Gyro_mover.moveSpeed = abs(Gyro_mover.moveSpeed);
	}
	else
	{
		sign = -1;

		Gyro_mover.moveSpeed = -abs(Gyro_mover.moveSpeed);
	}

	wait(10);

	PID_Gyro_On_Until_Encoder(Gyro_mover, getMotorEncoder(wheelR) + sign * MmToEncoder(Mm));

	while(task_usage[1].use != none){}
}

void setHandUp(int encoderVal)
{
	handUp(encoderVal);

	while(!inRange(getMotorEncoder(hand), -encoderVal, 2)){}
}
