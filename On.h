//////////////////////////////////////////
// Workfile : On.h
// Author : Michael Enzelsberger
// Date : 09.01.2021
// Description : Concrete On Command.
//////////////////////////////////////////

#ifndef ON_H
#define ON_H

#include "Object.h"
#include "Command.h"
#include "Device.h"

class On : public Command, public Object
{
public:
	On(Device::SPtr const& device);
	void Execute() override;
	void Undo() const override;

private:
	//member of device for the command
	Device::SPtr mDevice;
	//stores previous state
	TStatePower mPrevState;
};

#endif
