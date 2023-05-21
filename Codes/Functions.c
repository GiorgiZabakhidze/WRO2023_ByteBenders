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

void simpleMoveMm(float Mm)
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
			doneL = inRange(getMotorEncoder(wheelL), targetL, 20);

		if(!doneR)
			doneR = inRange(getMotorEncoder(wheelR), targetR, 20);

		if(doneL)
		{
			setMotorSpeed(wheelL, 0);
		}
		if(doneR)
		{
			setMotorSpeed(wheelR, 0);
		}

		displayBigTextLine(1, "%d", targetL);
		displayBigTextLine(3, "%d", getMotorEncoder(wheelL));
		displayBigTextLine(5, "%d", targetR);
		displayBigTextLine(7, "%d", getMotorEncoder(wheelR));
	}
	playSound(soundBlip);
}

void setHandUp(int encoderVal)
{
	int init = getMotorEncoder(hand);

	handUp(50);

	while(!inRange(getMotorEncoder(hand), init - 50, 2)){}
}
