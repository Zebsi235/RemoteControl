//////////////////////////////////////////
// Workfile : TV.cpp
// Author : Pascal Lang
// Date : 09.01.2021
// Description : Source Code for TV-Devices.
//////////////////////////////////////////

#include "TV.h"
#include "TStatePower.h"

using namespace std;

void TV::Info(ostream& ost) const
{
	ost << "TV is ";
	//print the current powerstate to
	//the given ostream
	switch(mState){
		case TStatePower::eOn: ost << "on" << endl;
			break;
		case TStatePower::eOff: ost << "off" << endl;
			break;
	}
}

void TV::SetState(TStatePower const& state)
{
	//Set internal powerstate to
	//given value
	mState = state;
}

TStatePower TV::GetState() const
{
	//returns current powerstate
	return mState;
}