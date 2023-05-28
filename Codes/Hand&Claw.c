// Vaketebt Chaciklul Tasks Rom Xelis Makontrolebel Motors Mudmivad Qondes Is Encoder Value Rac Gvinda

int handSpeed = 30; // Xelis Modzraobis Sichqare
int clawSpeed = 30; // Claw-s Modzraobis Sichqare

int handTarget = 0; // Encoderis Mnishvneloba Rac Gvinda Xelis Makontrolebel Motors Qondes
int clawTarget = 0; // Encoderis Mnishvneloba Rac Gvinda Claw-s Makontrolebel Motors Qondes

task handControl() // Taski Romelic Mudmivad Chaciklulia Da Aniwebs Motors Targets
{

	while(true)
	{

		// Tu Motoris Axlandeli Encoderi Ar Aris Is Rac Gvinda Rom Iyos, Da Arc Targeti Ar Aris Rac Gvinda Rom Iyos, Mashin Targets Vutolebt handTarget-s
		if(getMotorEncoder(hand) != handTarget && getMotorTarget(hand) != handTarget)
		{
				setMotorTarget(hand, handTarget, handSpeed);
		}

		wait(50); // Vicdit 10 Miliwami Radgan Tyuilad Ar Imushaos Punqciam Mudmivad

	}

}

/*
	Xeli-s Gamodzraveba Romlitac Zemot-Qvemot Iweva Claw

	@param [bool] setPoint 					Xeli-s Mamodzravebeli Motor-is Sasurveli Encoder Mnishvneloba (Dadebiti=Aweuli, Uaryopiti=Chamoweuli)
*/
void setHand(int setPoint)
{
	handTarget = setpoint;

	// Varesetebt Task-s
		stopTask(handControl);

		startTask(handControl);
}

task clawControl() // Taski Romelic Mudmivad Chaciklulia Da Aniwebs Motors Targets
{

	while(true)
	{

		// Tu Motoris Axlandeli Encoderi Ar Aris Is Rac Gvinda Rom Iyos, Da Arc Targeti Ar Aris Rac Gvinda Rom Iyos, Mashin Targets Vutolebt ClawTarget-s
		if(getMotorEncoder(claw) != clawTarget && getMotorTarget(claw) != clawTarget)
		{
				setMotorTarget(claw, clawTarget, clawSpeed);
		}

		wait(50); // Vicdit 10 Miliwami Radgan Tyuilad Ar Imushaos Punqciam Mudmivad

	}

}

/*
	Xeli-s Gamodzraveba Romlitac Zemot-Qvemot Iweva Claw

	@param [bool] setPoint 					Xeli-s Mamodzravebeli Motor-is Sasurveli Encoder Mnishvneloba (Dadebiti=Gaxsnili, Uaryopiti=Daketili)
*/
void setClaw(int setPoint)
{
	clawTarget = setpoint;

	// Varesetebt Task-s
		stopTask(clawControl);

		startTask(clawControl);
}
