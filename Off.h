//////////////////////////////////////////
// Workfile : Off.h
// Author : Michael Enzelsberger
// Date : 09.01.2021
// Description : Concrete Off Command.
//////////////////////////////////////////

#ifndef OFF_H
#define OFF_H

#include "Object.h"
#include "Command.h"
#include "Device.h"

class Off : public Command, public Object
{
public:
	Off(Device::SPtr const& device);
	void Execute() override;
	void Undo() const override;

private:
	Device::SPtr mDevice;
	TStatePower mPrevState;
};

#endif
