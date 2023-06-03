#pragma config(Sensor, S1,     usonic,         sensorEV3_Ultrasonic)
#pragma config(Sensor, S2,     gyro,           sensorEV3_Gyro)
#pragma config(Sensor, S3,     color2,         sensorEV3_Color)
#pragma config(Sensor, S4,     color1,         sensorEV3_Color)
#pragma config(Motor,  motorA,          claw,          tmotorEV3_Medium, PIDControl, encoder)
#pragma config(Motor,  motorB,          wheelR,        tmotorEV3_Medium, PIDControl, encoder)
#pragma config(Motor,  motorC,          wheelL,        tmotorEV3_Medium, PIDControl, reversed, encoder)
#pragma config(Motor,  motorD,          hand,          tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// color1 - LineFollower-is Sensor-i
// color2 - ColorCheck-is Sensor-i

//float lineCorrectionTime = 1000;

int cBlack = 8;
int cDarkBlue = 11;
int cBlue = 15;
int cWhite = 50;

int checkedColor = -1;
bool checkStatus = false;

int colorsAsked[2]; 	// 3=Mwvane, 2=Blue, 0=Empty.
int blockColors[4]; 	// 3=Mwvane, 2=Blue, 0=Empty.
int robotBlocks[4]; 	// 3=Mwvane, 2=Blue, 0=Empty.

#include "AlgorithmTypeFunctions.c"
#include "PID.c"

PID Hand_normal;
PID LineFollower_normal_r;
PID LineFollower_normal_l;
PID Gyro_rotate;
PID Gyro_move;
PID Gyro_move_fast;
PID Encoder_move;
PID Encoder_move_fast;
PID Encoder_rotate;

#include "PID_Usage.c"
#include "PID_tasks.c"
#include "PID_Start.c"
#include "PID_LineFollower.c"
#include "PID_Gyro.c"
#include "PID_Hand&Claw.c"
#include "Hand&Claw.c"
#include "PID_Encoder.c"
#include "Functions.c"
#include "Tasks.c"
#include "PID_highLevelFunctions.c"
#include "Initialization.c"
#include "DoTheJob_1.c"
#include "DoTheJob_2.c"
#include "DoTheJob_3.c"



task main()
{

	Initializate();

	//Encoder_rotate.oneSided = true;
	//Encoder_rotate.side = true;

	//PID_Encoder_Rotate(Encoder_rotate, DegToDeltaEncoder(90));

	DoTheJob_1();

	DoTheJob_2();

	//PID_LineFollower_On_Until_Encoder(LineFollower_normal_r, getMotorEncoder(wheelL) - MmToEncoder(350));

	//Encoder_move.setpoint = getMotorEncoder(wheelR) + getMotorEncoder(wheelL);

	//wait(100);

	//PID_Encoder_On_Until_Reflected(Encoder_move, cBlack + 1);

	//Gyro_moveMm(Gyro_move, 999999);

	//Gyro_rotate.oneSided = false;

	//PID_Gyro_Rotate(Gyro_rotate, -90);

	//Gyro_rotate.oneSided = false;
	//Gyro_rotate.side = true;

	//PID_Gyro_Rotate(Gyro_rotate, -90);

	//while(task_usage[1].use != none){}

	//PID_Gyro_On_ForTime(Gyro_move, 9999);

	//Gyro_move_fast.setpoint = getGyroDegrees(gyro);

	//wait(100);

	//playSound(soundBlip);

	//PID_LineFollower_On_ForTime(LineFollower_normal_l, 99999);
}
