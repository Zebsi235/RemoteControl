//////////////////////////////////////////
// Workfile : Open.h
// Author : Michael Enzelsberger
// Date : 09.01.2021
// Description : Concrete Open Command.
//////////////////////////////////////////

#ifndef OPEN_H
#define OPEN_H

#include "Object.h"
#include "Command.h"
#include "Device.h"
#include "StereoCD.h"

class Open : public Command, public Object
{
public:
	Open(StereoCD::SPtr const& cd);
	void Execute() override;
	void Undo() const override;

private:
	//member of device for the command
	StereoCD::SPtr mCD;
	//stores previous state
	TStateCD mPrevState;
};

#endif
