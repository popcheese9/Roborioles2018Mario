// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "ctre/Phoenix.h"
#include <math.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))
#include "DriveBase.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "../Commands/Drive.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

DriveBase::DriveBase() : frc::Subsystem("DriveBase") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    rightMotor1 = RobotMap::driveBaseRightMotor1;
    leftMotor1 = RobotMap::driveBaseLeftMotor1;
    leftMotor2 = RobotMap::driveBaseLeftMotor2;
    rightMotor2 = RobotMap::driveBaseRightMotor2;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

    //invert motor
    //leftMotor1->SetInverted(true);
    //leftMotor2->SetInverted(true);

    //set left2 follow left1
    leftMotor2->Set(ControlMode::Follower,1);

    //set right2 follow right1
    rightMotor2->Set(ControlMode::Follower,3);
}

void DriveBase::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

        SetDefaultCommand(new Drive());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void DriveBase::Periodic() {
    // Put code here to be run every loop

}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveBase::DriveWithJoystick()
{
	//diffDrive->ArcadeDrive(Robot::oi->getDriveStick()->GetY(), Robot::oi->getDriveStick()->GetX());
	DriveBase::diffDrive(Robot::oi->getDriveStick()->GetY(), Robot::oi->getDriveStick()->GetX());
}

void DriveBase::diffDrive(float moveValue, float rotateValue)
{
	float leftMotorOutput;
	float rightMotorOutput;

	moveValue = Limit(moveValue);

	if (moveValue > 0.0)
	{
		if (rotateValue > 0.0)
		{
			leftMotorOutput = moveValue - rotateValue;
			rightMotorOutput = max(moveValue, rotateValue);
		}
		else
		{
			leftMotorOutput = max(moveValue, -rotateValue);
			rightMotorOutput = moveValue + rotateValue;
		}
	}
	else
	{
		if (rotateValue > 0.0)
		{
			leftMotorOutput = - max(-moveValue, rotateValue);
			rightMotorOutput = moveValue + rotateValue;
		}
		else
		{
			leftMotorOutput = moveValue - rotateValue;
			rightMotorOutput = - max(-moveValue, -rotateValue);
		}
	}
	leftMotor1->Set(leftMotorOutput);
	rightMotor1->Set(rightMotorOutput);
}



float DriveBase::Limit(float num)
{
	if (num > 1.0)
	{
		return 1.0;
	}
	if (num < -1.0)
	{
		return -1.0;
	}
	return num;
}
