// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/Drive.h"
#include "Commands/IntakeOpenClose.h"
#include "Commands/Lift.h"
#include "Commands/Pickup.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    gamePad.reset(new frc::Joystick(2));
    
    intakeButton.reset(new frc::JoystickButton(gamePad.get(), 1));
    intakeButton->WhenPressed(new IntakeOpenClose());
    liftStick.reset(new frc::Joystick(1));
    
    driveStick.reset(new frc::Joystick(0));
    

    // SmartDashboard Buttons
    frc::SmartDashboard::PutData("IntakeOpenClose", new IntakeOpenClose());
    frc::SmartDashboard::PutData("Pickup", new Pickup());
    frc::SmartDashboard::PutData("Lift", new Lift());
    frc::SmartDashboard::PutData("Drive", new Drive());
    frc::SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<frc::Joystick> OI::getDriveStick() {
   return driveStick;
}

std::shared_ptr<frc::Joystick> OI::getLiftStick() {
   return liftStick;
}

std::shared_ptr<frc::Joystick> OI::getGamePad() {
   return gamePad;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
