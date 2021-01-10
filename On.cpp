//////////////////////////////////////////
// Workfile : On.cpp
// Author : Michael Enzelsberger
// Date : 09.01.2021
// Description : Concrete On Command.
//////////////////////////////////////////

#include "On.h"

using namespace std;

On::On(Device::SPtr const& device)
{
	if (device == nullptr)
	{
		throw string("null pointer in CTOR Off");
	}
	mDevice = device;
}


void On::Execute()
{
	mPrevState = mDevice->GetState();
	mDevice->SetState(TStatePower::eOn);
}

void On::Undo() const
{
	mDevice->SetState(mPrevState);
}
