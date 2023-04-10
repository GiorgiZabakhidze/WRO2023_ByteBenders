// Vaketebt Chaciklul Tasks Rom Xelis Makontrolebel Motors Mudmivad Qondes Is Encoder Value Rac Gvinda

int handSpeed = 30; // Xelis Modzraobis Sichqare

int handTarget; // Encoderis Value Rac Gvinda Xelis Makontrolebel Motors Qondes

task setHand() // Taski Romelic Mudmivad Chaciklulia Da Aniwebs Motors Targets
{

	while(true)
	{

		// Tu Motoris Axlandeli Encoderi Ar Aris Is Rac Gvinda Rom Iyos, Da Arc Targeti Ar Aris Rac Gvinda Rom Iyos, Mashin Targets Vutolebt handTarget-s
		if(getMotorEncoder(hand) != handTarget && getMotorTarget(hand) != handTarget)
		{
				setMotorTarget(hand, handTarget, handSpeed);
		}

		wait(10); // Vicdit 10 Miliwami Radgan Tyuilad Ar Imushaos Punqciam Mudmivad

	}

}

/*
	Xeli-s Gamodzraveba Romlitac Zemot-Qvemot Iweva Claw

	@param [bool] setPoint 					Xeli-s Mamodzravebeli Motor-is Sasurveli Encoder Mnishvneloba (True=Aweuli, False=Chamoweuli)
*/
void moveHand(bool setPoint)
{
	if(setPoint) // Tu Setpoint Aris True, HandTarget-s Vaniwebt Aweuli Mdgomareobis Shesabamis Encoderis Mnishvnelobas
	{
		handTarget = 0;
	}
	else // Tu Setpoint Aris false, HandTarget-s Vaniwebt Chamoweuli Mdgomareobis Shesabamis Encoderis Mnishvnelobas
	{
		handTarget = 360;
	}

	// Varesetebt Task-s
	stopTask(setHand);

	startTask(setHand);
}


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
