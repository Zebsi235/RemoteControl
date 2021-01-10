//////////////////////////////////////////
// Workfile : Stereo.cpp
// Author : Sebastian Mueck
// Date : 09.01.2021
// Description : Implementation for concrete Device
//////////////////////////////////////////

#include "Stereo.h"
#include <string>

using namespace std;

string const outputStereo = "Stereo is ";
string const outputCD = "CD is ";

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
	ost << outputStereo;

	switch(mState){
		case TStatePower::eOn: ost << "on ";
			break;
		case TStatePower::eOff: ost << "off ";
			break;
	}


	if (mCD_Unit != nullptr)
	{
		ost << outputCD;

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
