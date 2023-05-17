/*
	// ROBOTI UNDA IYOS GACHEREBULI AM PUNQSIIC GAMOYENEBAMDE //

	Abrunebs Color Checker-i Sensoris Mnishvnelobas Upro Zustad

	return Sensoris Mnishvneloba
*/
int Color_GetColorAmbient()
{
	wait(200); // Vicdit 50 Miliwami Rom Roboti Uewvelad Gacherebuli Iyos

	getColorReflected(color2); // Gadavrtavt Reflected Mode-ze

	getColorName(color2); // Davabrunebt Ukan Color Mode-ze

	wait(100); // Vicdit 20 Miliwami Rom Kargad Gaswordes Sensor-i

	return getColorName(color2); // Vabrunebt Tavidan Gazomil Shedegs
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
