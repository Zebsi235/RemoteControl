//////////////////////////////////////////
// Workfile : Off.cpp
// Author : Michael Enzelsberger
// Date : 09.01.2021
// Description : Concrete Off Command.
//////////////////////////////////////////

#include "Off.h"

using namespace std;

Off::Off(Device::SPtr const& device)
{
	//check nullpointer
	if (device == nullptr)
	{
		throw string("null pointer in CTOR Off");
	}
	//store device
	mDevice = device;
}

void Off::Execute()
{
	//store current state as previous state
	mPrevState = mDevice->GetState();
	//overwrite current state
	mDevice->SetState(TStatePower::eOff);
}

void Off::Undo() const
{
	//overwrite current state with prev state
	mDevice->SetState(mPrevState);
}
