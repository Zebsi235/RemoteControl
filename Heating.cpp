//////////////////////////////////////////
// Workfile : Heating.cpp
// Author : Sebastian Mueck
// Date : 09.01.2021
// Description : Implementation for concrete Device
//////////////////////////////////////////

#include "Heating.h"

using namespace std;

void Heating::Info(std::ostream& ost) const
{
	ost << "Heating is ";

	switch(mState){
		case TStatePower::eOn: ost << "on" << endl;
			break;
		case TStatePower::eOff: ost << "off" << endl;
			break;
	}
}

TStatePower Heating::GetState() const
{
	return mState;
}

void Heating::SetState(TStatePower const& state)
{
	mState = state;
}
