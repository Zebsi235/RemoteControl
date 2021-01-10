//////////////////////////////////////////
// Workfile : TV.cpp
// Author : Pascal Lang
// Date : 09.01.2021
// Description : Source Code for TV-Devices.
//////////////////////////////////////////

#include "TV.h"
#include "TStatePower.h"

using namespace std;

string const output ="TV is ";

void TV::Info(ostream& ost) const
{
	ost << output;

	switch(mState){
		case TStatePower::eOn: ost << "on" << endl;
			break;
		case TStatePower::eOff: ost << "off" << endl;
			break;
	}
}


void TV::SetState(TStatePower const& state)
{
	mState = state;
}

TStatePower TV::GetState() const
{
	return mState;
}