//////////////////////////////////////////
// Workfile : Stereo.cpp
// Author : Pascal Lang
// Date : 09.01.2021
// Description : Implementation for concrete Device
//////////////////////////////////////////

#include "Stereo.h"
#include <string>

using namespace std;

//Custom C-Tor to create a stereo-device with cd drive
Stereo::Stereo(StereoCD::SPtr const& cd)
{
	if (cd != nullptr)
	{
		mCD_Unit = cd;
	}
}

void Stereo::Info(std::ostream& ost) const
{
	ost << "Stereo is ";
	//prints the current power state of the 
	//stereo system
	switch(mState){
		case TStatePower::eOn: ost << "on ";
			break;
		case TStatePower::eOff: ost << "off ";
			break;
	}

	//if the member is different to nullpointer
	//the stereo device has a cd drive
	if (mCD_Unit != nullptr)
	{
		ost << "CD is ";

		//prints the current state of the cd drive
		switch (mCD_Unit->GetStateCD())
		{
		case TStateCD::eOpen: ost << "open" << endl;
			break;
		case TStateCD::eClosed: ost << "closed" << endl;
			break;
		}
	}
	else
	{
		ost << endl;
	}
}

TStatePower Stereo::GetState() const
{
	//returns the current powerstate
	return mState;
}

void Stereo::SetState(TStatePower const& state)
{
	//set the current powerstate to the given one
	mState = state;

	if (mCD_Unit != nullptr)
	{
		//if the stereo-device has a cd drive
		//it will be truned on or off, depending on the 
		//given powerstate.
		if (state == TStatePower::eOn)
		{
			mCD_Unit->SetStateCD(TStateCD::eOpen);
		}
		else
		{
			mCD_Unit->SetStateCD(TStateCD::eClosed);
		}
	}
}
