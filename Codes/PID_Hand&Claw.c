/*
	Xeli-s Gamodzraveba Romlitac Zemot-Qvemot Iweva Claw

	@param [PID] pid 								Xeli-s PID Romlitac Vakontrolebt Xeli-s Motors
	@param [bool] setPoint 					Xeli-s Mamodzravebeli Motor-is Sasurveli Encoder Mnishvneloba (True=Aweva, False=Daweva)
*/
void moveHand(PID* pid, bool setPoint)
{
	if(setPoint) // Tu Setpoint Aris True, HandTarget-s Vaniwebt Aweuli Mdgomareobis Shesabamis Encoderis Mnishvnelobas
	{
		pid->setpoint = getMotorEncoder(hand) - 35;
	}
	else // Tu Setpoint Aris false, HandTarget-s Vaniwebt Chamoweuli Mdgomareobis Shesabamis Encoderis Mnishvnelobas
	{
		pid->setpoint = getMotorEncoder(hand) + 35;
	}
}


/*
	Xeli-s Gamodzraveba Romlitac Zemot-Qvemot Iweva Claw

	@param [PID] pid 								Claw-s PID Romlitac Vakontrolebt Claw-s Motors
	@param [bool] setPoint 					Xeli-s Mamodzravebeli Motor-is Sasurveli Encoder Mnishvneloba (True=Gaxsnili, False=Daketili)
*/
void moveClaw(PID* pid, bool setPoint)
{
	if(setPoint) // Tu Setpoint Aris True, ClawTarget-s Vaniwebt Aweuli Mdgomareobis Shesabamis Encoderis Mnishvnelobas
	{
		pid->setpoint = getMotorEncoder(claw) - 100;
	}
	else // Tu Setpoint Aris false, ClawTarget-s Vaniwebt Chamoweuli Mdgomareobis Shesabamis Encoderis Mnishvnelobas
	{
		pid->setpoint = getMotorEncoder(claw) + 100;
	}
}
