//////////////////////////////////////////
// Workfile : TV.h
// Author : Pascal Lang
// Date : 09.01.2021
// Description : Header for TV-Devices.
//////////////////////////////////////////

#ifndef TV_H
#define TV_H

#include "Device.h"
#include <fstream>

class TV : public Device
{
public:
	void Info(std::ostream& ost) const override;
	void SetState(TStatePower const& state) override;
	TStatePower GetState() const override;

	using SPtr = std::shared_ptr<TV>;
	
private:
	TStatePower mState = TStatePower::eOff;
};

#endif