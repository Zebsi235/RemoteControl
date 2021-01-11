//////////////////////////////////////////
// Workfile : Button.cpp
// Author : Sebastian Mueck
// Date : 09.01.2021
// Description : Implementation for Buttons.
//////////////////////////////////////////

#include "Button.h"

using namespace std;

void Button::SetCmd(Command::SPtr const& cmd)
{
	//if the command is not a nullptr
	if (cmd == nullptr)
	{
		throw string("null pointer in Button SetCmd");
	}
	//the given command gets saved to mCommand
	mCommand = cmd;
}

//returns the command assigned to the 
//specific button
Command::SPtr Button::GetCmd() const
{
	return mCommand;
}
