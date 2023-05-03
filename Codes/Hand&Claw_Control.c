// Vaketebt Chaciklul Tasks Rom Xelis Makontrolebel Motors Mudmivad Qondes Is Encoder Value Rac Gvinda

int handSpeed = 5; // Xelis Modzraobis Sichqare
int clawSpeed = 5; // Claw-s Modzraobis Sichqare

int handTarget = 0; // Encoderis Mnishvneloba Rac Gvinda Xelis Makontrolebel Motors Qondes
int clawTarget = 0; // Encoderis Mnishvneloba Rac Gvinda Claw-s Makontrolebel Motors Qondes

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

	@param [bool] setPoint 					Xeli-s Mamodzravebeli Motor-is Sasurveli Encoder Mnishvneloba (True=Aweva, False=Daweva)
*/
void moveHand(bool setPoint)
{
	if(setPoint) // Tu Setpoint Aris True, HandTarget-s Vaniwebt Aweuli Mdgomareobis Shesabamis Encoderis Mnishvnelobas
	{
		handTarget = getMotorEncoder(hand) - 280;
	}
	else // Tu Setpoint Aris false, HandTarget-s Vaniwebt Chamoweuli Mdgomareobis Shesabamis Encoderis Mnishvnelobas
	{
		handTarget = getMotorEncoder(hand) + 280;
	}

	// Varesetebt Task-s
		stopTask(setHand);

		startTask(setHand);
}

task setClaw() // Taski Romelic Mudmivad Chaciklulia Da Aniwebs Motors Targets
{

	while(true)
	{

		// Tu Motoris Axlandeli Encoderi Ar Aris Is Rac Gvinda Rom Iyos, Da Arc Targeti Ar Aris Rac Gvinda Rom Iyos, Mashin Targets Vutolebt ClawTarget-s
		if(getMotorEncoder(claw) != clawTarget && getMotorTarget(claw) != clawTarget)
		{
				setMotorTarget(claw, clawTarget, clawSpeed);
		}

		wait(10); // Vicdit 10 Miliwami Radgan Tyuilad Ar Imushaos Punqciam Mudmivad

	}

}

/*
	Xeli-s Gamodzraveba Romlitac Zemot-Qvemot Iweva Claw

	@param [bool] setPoint 					Xeli-s Mamodzravebeli Motor-is Sasurveli Encoder Mnishvneloba (True=Gaxsnili, False=Daketili)
*/
void moveClaw(bool setPoint)
{
	if(setPoint) // Tu Setpoint Aris True, ClawTarget-s Vaniwebt Aweuli Mdgomareobis Shesabamis Encoderis Mnishvnelobas
	{
		clawTarget = getMotorEncoder(claw) - 280;
	}
	else // Tu Setpoint Aris false, ClawTarget-s Vaniwebt Chamoweuli Mdgomareobis Shesabamis Encoderis Mnishvnelobas
	{
		clawTarget = getMotorEncoder(claw) + 280;
	}

	// Varesetebt Task-s
		stopTask(setClaw);

		startTask(setClaw);
}
