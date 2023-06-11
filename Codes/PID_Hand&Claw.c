/*
	Xeli-s Gamodzraveba Romlitac Zemot-Qvemot Iweva Claw

	@param [PID] pid 								Xeli-s PID Romlitac Vakontrolebt Xeli-s Motors
	@param [int] setPoint 					Xeli-s Mamodzravebeli Motor-is Sasurveli Encoder Mnishvneloba (Dadebiti=Aweva, Uaryopiti=Daweva)
*/
void handUp(int setpoint)
{
		PID_resetVariables(Hand_normal);

		Hand_normal.setpoint = -setpoint;
}

int gripStrength = 15;

/*
	Xeli-s Gamodzraveba Romlitac Zemot-Qvemot Iweva Claw

	@param [PID] pid 								Claw-s PID Romlitac Vakontrolebt Claw-s Motors
	@param [bool] setPoint 					Xeli-s Mamodzravebeli Motor-is Sasurveli Encoder Mnishvneloba (True=Gaxsnili, False=Daketili)
*/
void clawOpened(bool setPoint, int time = 1300)
{
	if(setPoint) // Tu Setpoint Aris True, ClawTarget-s Vaniwebt Aweuli Mdgomareobis Shesabamis Encoderis Mnishvnelobas
	{
		setMotorSpeed(claw, gripStrength);
	}
	else // Tu Setpoint Aris false, ClawTarget-s Vaniwebt Chamoweuli Mdgomareobis Shesabamis Encoderis Mnishvnelobas
	{
		setMotorSpeed(claw, -gripStrength);
	}

	wait(time);

	if(getMotorEncoder(claw) > -20)
		setMotorSpeed(claw, 0);
}
