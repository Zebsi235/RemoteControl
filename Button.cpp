//////////////////////////////////////////
// Workfile : Button.cpp
// Author : Michael Enzelsberger
// Date : 09.01.2021
// Description : Implementation for Buttons.
//////////////////////////////////////////

#include "Button.h"

using namespace std;

void Button::SetCmd(Command::SPtr const& cmd)
{
	if (cmd == nullptr)
	{
		throw string("null pointer in Button SetCmd");
	}

	mCommand = cmd;
}

Command::SPtr Button::GetCmd() const
{
	return mCommand;
}
