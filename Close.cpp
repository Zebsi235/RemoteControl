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
	//check nullpointer
	if (cd == nullptr)
	{
		throw string("null pointer in CTOR Close");
	}
	//store device
	mCD = cd;
}

void Close::Execute()
{
	//store current state
	mPrevState = mCD->GetStateCD();
	//overwrite current state
	mCD->SetStateCD(TStateCD::eClosed);
}

void Close::Undo() const
{
	//set state with previous state
	mCD->SetStateCD(mPrevState);
}
