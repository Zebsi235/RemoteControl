//////////////////////////////////////////
// Workfile : Slot.h
// Author : Sebastian Mueck
// Date : 09.01.2021
// Description : Header for Slot class
//////////////////////////////////////////

#ifndef SLOT_H
#define SLOT_H

#include "Object.h"
#include "Button.h"
#include "Command.h"

class Slot : public Object
{
public:
	void SetOn(Command::SPtr const& cmd);
	void SetOff(Command::SPtr const& cmd);
	void SetName(std::string const& name);
	Command::SPtr GetOn();
	Command::SPtr GetOff();
	std::string GetName();

private:
	Button mOn;
	Button mOff;
	std::string mName;
};

#endif
