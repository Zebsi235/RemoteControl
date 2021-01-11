//////////////////////////////////////////
// Workfile : TV.h
// Author : Pascal Lang
// Date : 09.01.2021
// Description : Header for TV-Devices.
//////////////////////////////////////////

#ifndef TV_H
#define TV_H

#include "Object.h"
#include "Device.h"
#include <fstream>

class TV : public Device, public Object
{
public:
	//prints device info to given ostream
	void Info(std::ostream& ost) const override;
	//sets the power state
	void SetState(TStatePower const& state) override;
	//returns current power state
	TStatePower GetState() const override;

	using SPtr = std::shared_ptr<TV>;
	
private:
	TStatePower mState = TStatePower::eOff;
};

#endif