//////////////////////////////////////////
// Workfile : StereoCD.cpp
// Author : Michael Enzelsberger
// Date : 09.01.2021
// Description : Implementation for StereoCD-Devices.
//////////////////////////////////////////

#include "StereoCD.h"

using namespace std;

void StereoCD::Info(std::ostream& ost) const
{
	ost << "CD is ";
	//Prints the information
	//if the StereoCD is open or closed
	switch (mStateCD)
	{
	case TStateCD::eOpen: ost << "open" << endl;
		break;
	case TStateCD::eClosed: ost << "closed" << endl;
		break;
	}
}

void StereoCD::SetState(TStatePower const& state)
{
}

//returns that the Device is off
//funtion does not get called
//but has to be implemented
TStatePower StereoCD::GetState() const
{
	return TStatePower::eOff;
}

//Sets the state of StereoCD to open or close
void StereoCD::SetStateCD(TStateCD const& state)
{
	mStateCD = state;
}

//returns if StereoCD is open or closed
TStateCD StereoCD::GetStateCD() const
{
	return mStateCD;
}
