task Cimcimi()
{
	while(1)
	{
	 	wait(50);

		getColorAmbient(color2); // Gadavrtavt Ambient Mode-ze

		wait(50);

		getColorName(color2);

		wait(50);

	 	checkedColor = getColorName(color2);

	 	checkStatus = !checkStatus;
	}
}

task resetMotors()
{
	setMotorSpeed(claw, 15);
	setMotorSpeed(hand, -30);

	sleep(1000);

	setMotorSpeed(hand, 0);

	resetMotorEncoder(motorA);
	resetMotorEncoder(motorB);
	resetMotorEncoder(motorC);
	resetMotorEncoder(motorD);

	setMotorSpeed(claw, -15);

	clearTimer(T1);
}
