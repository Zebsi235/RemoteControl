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
	if (cd == nullptr)
	{
		throw string("null pointer in CTOR Open");
	}
	mCD = cd;
}

void Open::Execute()
{
	mPrevState = mCD->GetStateCD();
	mCD->SetStateCD(TStateCD::eOpen);
}

void Open::Undo() const
{
	mCD->SetStateCD(mPrevState);
}
