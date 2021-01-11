//////////////////////////////////////////
// Workfile : Slot.cpp
// Author : Sebastian Mueck
// Date : 09.01.2021
// Description : Implementation for Slot class
//////////////////////////////////////////

#include "Slot.h"

using namespace std;

void Slot::SetOn(Command::SPtr const& cmd)
{	//if the command is no nullptr 
	if (cmd == nullptr)
	{
		throw string("null pointer in Slot SetOn");
	}

	//the On command gets connected 
	//to a button
	mOn.SetCmd(cmd);
}

void Slot::SetOff(Command::SPtr const& cmd)
{	
	//if the command is no nullptr 
	if (cmd == nullptr)
	{
		throw string("null pointer in Slot SetOff");
	}

	//the Off command gets connected 
	//to a button
	mOff.SetCmd(cmd);
}

//Sets the name of the Device in this slot
void Slot::SetName(std::string const& name)
{
	mName = name;
}

//returns the command that is
//bound to the On button of this slot
Command::SPtr Slot::GetOn() const
{
	return mOn.GetCmd();
}

//returns the command that is
//bound to the Off button of this slot
Command::SPtr Slot::GetOff() const
{
	return mOff.GetCmd();
}

//returns name of specific device 
//in the slot 
std::string Slot::GetName() const
{
	return mName;
}
