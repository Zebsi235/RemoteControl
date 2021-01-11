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
	//prints the info of the device into the given ostream
	virtual void Info(std::ostream& ost) const = 0;
	//sets power state of device
	virtual void SetState(TStatePower const& state) = 0;
	//returns power state of device
	virtual TStatePower GetState() const = 0;
	//virtual destructor
	virtual ~Device() = default;

	using SPtr = std::shared_ptr<Device>;
};

#endif
