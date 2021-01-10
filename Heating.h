//////////////////////////////////////////
// Workfile : Heating.h
// Author : Sebastian Mueck
// Date : 09.01.2021
// Description : Header for concrete Device
//////////////////////////////////////////

#ifndef HEATING_H
#define HEATING_H

#include <fstream>
#include "Device.h"
#include "TStatePower.h"

class Heating : public Device
{
public:
	void Info(std::ostream& ost) const override;
	TStatePower GetState() const override;
	void SetState(TStatePower const& state) override;
	
private:
	TStatePower mState = TStatePower::eOff;
};

#endif