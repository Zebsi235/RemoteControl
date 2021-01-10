//////////////////////////////////////////
// Workfile : Close.cpp
// Author : Michael Enzelsberger
// Date : 09.01.2021
// Description : Concrete Close Command.
//////////////////////////////////////////

#include "Close.h"

using namespace std;

Close::Close(StereoCD::SPtr const& cd)
{
	if (cd == nullptr)
	{
		throw string("null pointer in CTOR Close");
	}
	mCD = cd;
}

void Close::Execute()
{
	mPrevState = mCD->GetStateCD();
	mCD->SetStateCD(TStateCD::eClosed);
}

void Close::Undo() const
{
	mCD->SetStateCD(mPrevState);
}
