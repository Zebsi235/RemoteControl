//////////////////////////////////////////
// Workfile : Stereo.cpp
// Author : Pascal Lang
// Date : 09.01.2021
// Description : Implementation for concrete Device
//////////////////////////////////////////

#include "Stereo.h"
#include <string>

using namespace std;

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

	switch(mState){
		case TStatePower::eOn: ost << "on ";
			break;
		case TStatePower::eOff: ost << "off ";
			break;
	}


	if (mCD_Unit != nullptr)
	{
		ost << "CD is ";

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
	return mState;
}

void Stereo::SetState(TStatePower const& state)
{
	mState = state;

	if (mCD_Unit != nullptr)
	{
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
