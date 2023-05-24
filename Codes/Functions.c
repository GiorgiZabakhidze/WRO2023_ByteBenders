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
	float requiredPercentage = 0.3;

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

void setHandUp(int encoderVal)
{
	int init = getMotorEncoder(hand);

	handUp(encoderVal);

	while(!inRange(getMotorEncoder(hand), init - encoderVal, 2)){}
}
