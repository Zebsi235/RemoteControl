//////////////////////////////////////////
// Workfile : Heating.h
// Author : Sebastian Mueck
// Date : 09.01.2021
// Description : Header for concrete Device
//////////////////////////////////////////

#ifndef HEATING_H
#define HEATING_H

#include "Object.h"
#include <fstream>
#include "Device.h"
#include "TStatePower.h"

class Heating : public Device, public Object
{
public:
	//Print function
	void Info(std::ostream& ost) const override;
	//Get function
	TStatePower GetState() const override;
	//Set function
	void SetState(TStatePower const& state) override;
	
private:
	TStatePower mState = TStatePower::eOff;
};

#endif