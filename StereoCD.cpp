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

TStatePower StereoCD::GetState() const
{
	return TStatePower::eOff;
}

void StereoCD::SetStateCD(TStateCD const& state)
{
	mStateCD = state;
}

TStateCD StereoCD::GetStateCD() const
{
	return mStateCD;
}
