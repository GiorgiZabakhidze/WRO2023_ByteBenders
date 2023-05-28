/*
	Xeli-s Gamodzraveba Romlitac Zemot-Qvemot Iweva Claw

	@param [PID] pid 								Xeli-s PID Romlitac Vakontrolebt Xeli-s Motors
	@param [int] setPoint 					Xeli-s Mamodzravebeli Motor-is Sasurveli Encoder Mnishvneloba (Dadebiti=Aweva, Uaryopiti=Daweva)
*/
void handUp(int setPoint)
{
		PID_resetVariables(Hand_normal);

		Hand_normal.setpoint = -setpoint;
}


/*
	Xeli-s Gamodzraveba Romlitac Zemot-Qvemot Iweva Claw

	@param [PID] pid 								Claw-s PID Romlitac Vakontrolebt Claw-s Motors
	@param [bool] setPoint 					Xeli-s Mamodzravebeli Motor-is Sasurveli Encoder Mnishvneloba (True=Gaxsnili, False=Daketili)
*/
void clawOpened(bool setPoint)
{
	if(setPoint) // Tu Setpoint Aris True, ClawTarget-s Vaniwebt Aweuli Mdgomareobis Shesabamis Encoderis Mnishvnelobas
	{
		setMotorSpeed(claw, 40);
	}
	else // Tu Setpoint Aris false, ClawTarget-s Vaniwebt Chamoweuli Mdgomareobis Shesabamis Encoderis Mnishvnelobas
	{
		setMotorSpeed(claw, -40);
	}

	wait(1000);
}
