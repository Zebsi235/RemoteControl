//////////////////////////////////////////
// Workfile : Close.h
// Author : Michael Enzelsberger
// Date : 09.01.2021
// Description : Concrete Close Command.
//////////////////////////////////////////

#ifndef CLOSE_H
#define CLOSE_H

#include "Object.h"
#include "Command.h"
#include "Device.h"
#include "StereoCD.h"

class Close : public Command, public Object
{
public:
	Close(StereoCD::SPtr const& cd);
	void Execute() override;
	void Undo() const override;

private:
	//member of device for the command
	StereoCD::SPtr mCD;
	//stores previous state
	TStateCD mPrevState;
};

#endif
