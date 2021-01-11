//////////////////////////////////////////
// Workfile : Open.cpp
// Author : Michael Enzelsberger
// Date : 09.01.2021
// Description : Concrete Open Command.
//////////////////////////////////////////

#include "Open.h"

using namespace std;

Open::Open(StereoCD::SPtr const& cd)
{
	//check nullpointer
	if (cd == nullptr)
	{
		throw string("null pointer in CTOR Open");
	}
	//store device pointer
	mCD = cd;
}

void Open::Execute()
{
	//store current state as previous state
	mPrevState = mCD->GetStateCD();
	//overwrite current state
	mCD->SetStateCD(TStateCD::eOpen);
}

void Open::Undo() const
{
	//overwrite current state with previous state
	mCD->SetStateCD(mPrevState);
}
