//////////////////////////////////////////
// Workfile : Slot.cpp
// Author : Sebastian Mueck
// Date : 09.01.2021
// Description : Implementation for Slot class
//////////////////////////////////////////

#include "Slot.h"

using namespace std;

void Slot::SetOn(Command::SPtr const& cmd)
{
	if (cmd == nullptr)
	{
		throw string("null pointer in Slot SetOn");
	}

	mOn.SetCmd(cmd);
}

void Slot::SetOff(Command::SPtr const& cmd)
{
	if (cmd == nullptr)
	{
		throw string("null pointer in Slot SetOff");
	}

	mOff.SetCmd(cmd);
}

void Slot::SetName(std::string const& name)
{
	mName = name;
}

Command::SPtr Slot::GetOn() const
{
	return mOn.GetCmd();
}

Command::SPtr Slot::GetOff() const
{
	return mOff.GetCmd();
}

std::string Slot::GetName() const
{
	return mName;
}
