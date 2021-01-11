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
	//check nullpointer
	if (device == nullptr)
	{
		throw string("null pointer in CTOR Off");
	}
	//store device
	mDevice = device;
}


void On::Execute()
{
	//store current state as previous state
	mPrevState = mDevice->GetState();
	//overwrite current state
	mDevice->SetState(TStatePower::eOn);
}

void On::Undo() const
{
	//overwrite current state with previous state
	mDevice->SetState(mPrevState);
}
