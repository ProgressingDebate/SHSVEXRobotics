#pragma config(Motor,  port1,           rearLeftWheelMotor, tmotorVex269_HBridge, openLoop)
#pragma config(Motor,  port2,           rearRightWheelMotor, tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port3,           frontLeftWheelMotor, tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port4,           frontRightWheelMotor, tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port5,           leftArmMotor,  tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port6,           rightArmMotor, tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port7,           wristMotor,    tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port8,           clawMotor,     tmotorVex269_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
////////////////////////////////////////////////////////////////////////////////////
//
//									BaseFunctions
//
//	These functions all take the parameters (int time, int speed).
//	Time must be given in milliseconds. Speed should be a positive integer (1-100).
//
//	List of Functions: raiseArm, lowerArm, moveForward, moveBackward, turnRight, turnLeft
//						openClaw, closeClaw.
//
//	NOTE: Motors must be configured to match given aliases.
////////////////////////////////////////////////////////////////////////////////////
*/

void raiseArm(int time, int speed)
{
	clearTimer(T2);
	while(time1[T2] < time)
	{
		motor[leftArmMotor] = speed;
		motor[rightArmMotor] = speed;
	}
	//Stop Raising the Arm After Given Time
	motor[leftArmMotor] = 0;
	motor[rightArmMotor] = 0;
}

void lowerArm(int time, int speed)
{
	clearTimer(T2);
	while(time1[T2] < time)
	{
		motor[leftArmMotor] = -speed;
		motor[rightArmMotor] = -speed;
	}
	//Stop Lowering the Arm After Given Time
	motor[leftArmMotor] = 0;
	motor[rightArmMotor] = 0;
}

void moveForward(int time, int speed){
	clearTimer(T1);
	while(time1[T1] < time)
	{
		motor[rearRightWheelMotor] = speed;
		motor[frontRightWheelMotor] = speed;
		motor[rearLeftWheelMotor] = speed;
		motor[frontLeftWheelMotor] = speed;
	}
	//Stop Moving Forward After Given Time
	motor[rearRightWheelMotor] = 0;
	motor[frontRightWheelMotor] = 0;
	motor[rearLeftWheelMotor] = 0;
	motor[frontLeftWheelMotor] = 0;
}

void moveBackward(int time, int speed){
	clearTimer(T1);
	while(time1[T1] < time)
	{
		motor[rearRightWheelMotor] = -speed;
		motor[frontRightWheelMotor] = -speed;
		motor[rearLeftWheelMotor] = -speed;
		motor[frontLeftWheelMotor] = -speed;
	}
	//Stop Moving Backward After Given Time
	motor[rearRightWheelMotor] = 0;
	motor[frontRightWheelMotor] = 0;
	motor[rearLeftWheelMotor] = 0;
	motor[frontLeftWheelMotor] = 0;
}

void turnRight(int time, int speed)
{
	clearTimer(T1);
	while(time1[T1] < time)
	{
		motor[rearRightWheelMotor] = -speed;
		motor[frontRightWheelMotor] = -speed;
		motor[rearLeftWheelMotor] = speed;
		motor[frontLeftWheelMotor] = speed;
	}
	//Stop Turning Right After Given Time
	motor[rearRightWheelMotor] = 0;
	motor[frontRightWheelMotor] = 0;
	motor[rearLeftWheelMotor] = 0;
	motor[frontLeftWheelMotor] = 0;
}

void turnLeft(int time, int speed)
{
	clearTimer(T1);
	while(time1[T1] < time)
	{
		motor[rearRightWheelMotor] = speed;
		motor[frontRightWheelMotor] = speed;
		motor[rearLeftWheelMotor] = -speed;
		motor[frontLeftWheelMotor] = -speed;
	}
	//Stop Turning Left After Given Time
	motor[rearRightWheelMotor] = 0;
	motor[frontRightWheelMotor] = 0;
	motor[rearLeftWheelMotor] = 0;
	motor[frontLeftWheelMotor] = 0;
}

void openClaw(int time, int speed)
{
	clearTimer(T3);
	while(time1[T3] < time)
	{
		motor[clawMotor] = -speed;
	}
	//Stop Opening the Claw After Given Time
	motor[clawMotor] = 0;
}

void closeClaw(int time, int speed)
{
	clearTimer(T3);
	while(time1[T3] < time)
	{
		motor[clawMotor] = speed;
	}
	//Stop Closing the Claw After Given Time
	motor[clawMotor] = 0;
}

task main()
{
	/*
		Sample Task
		moveForward(2000, 25);
	*/
}