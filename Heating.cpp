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
	//Prints the information
	//if the Heating is on or off
	switch(mState){
		case TStatePower::eOn: ost << "on" << endl;
			break;
		case TStatePower::eOff: ost << "off" << endl;
			break;
	}
}

//returns the state of the Heating
TStatePower Heating::GetState() const
{
	return mState;
}

//chages the state of Heating if a button is
//pressed on the remote
void Heating::SetState(TStatePower const& state)
{
	mState = state;
}
