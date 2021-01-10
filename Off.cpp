//////////////////////////////////////////
// Workfile : Off.h
// Author : Michael Enzelsberger
// Date : 09.01.2021
// Description : Concrete Off Command.
//////////////////////////////////////////

#include "Off.h"

using namespace std;

Off::Off(Device::SPtr const& device)
{
	if (device == nullptr)
	{
		throw string("null pointer in CTOR Off");
	}
	mDevice = device;
}

void Off::Execute()
{
	mPrevState = mDevice->GetState();
	mDevice->SetState(TStatePower::eOff);
}

void Off::Undo() const
{
	mDevice->SetState(mPrevState);
}
