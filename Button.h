//////////////////////////////////////////
// Workfile : Button.h
// Author : Sebastian Mueck
// Date : 09.01.2021
// Description : Header for Buttons.
//////////////////////////////////////////

#ifndef BUTTON_H
#define BUTTON_H

#include "Object.h"
#include "Command.h"

class Button: public Object
{
public:
	void SetCmd(Command::SPtr const& cmd);
	Command::SPtr GetCmd() const;

private:
	Command::SPtr mCommand;
};

#endif