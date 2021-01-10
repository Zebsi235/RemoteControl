//////////////////////////////////////////
// Workfile : Device.h
// Author : Pascal Lang
// Date : 09.01.2021
// Description : Interface for Devices.
//////////////////////////////////////////

#ifndef DEVICE_H
#define DEVICE_H

#include <fstream>
#include "TStatePower.h"

class Device
{
public:
	virtual void Info(std::ostream& ost) const = 0;
	virtual void SetState(TStatePower const& state) = 0;
	virtual TStatePower GetState() const = 0;

	virtual ~Device() = default;

	using SPtr = std::shared_ptr<Device>;
};

#endif
