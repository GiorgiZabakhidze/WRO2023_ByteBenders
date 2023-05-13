/*
	// ROBOTI UNDA IYOS GACHEREBULI AM PUNQSIIC GAMOYENEBAMDE //

	Abrunebs Color Checker-i Sensoris Mnishvnelobas Upro Zustad

	return Sensoris Mnishvneloba
*/
int Color_GetColorAmbient()
{
	wait(50); // Vicdit 50 Miliwami Rom Roboti Uewvelad Gacherebuli Iyos

	getColorReflected(color2); // Gadavrtavt Reflected Mode-ze

	getColorName(color2); // Davabrunebt Ukan Color Mode-ze

	wait(20); // Vicdit 20 Miliwami Rom Kargad Gaswordes Sensor-i

	return getColorName(color2); // Vabrunebt Tavidan Gazomil Shedegs
}

void moveByBit(int mode)
{
	if(mode > 0)
	{
		setMotorSpeed(wheelL, 20);
		setMotorSpeed(wheelR, 20);
		wait(mode * 150);
		setMotorSpeed(wheelL, 0);
		setMotorSpeed(wheelR, 0);
	}

}
