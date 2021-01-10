//////////////////////////////////////////
// Workfile : NoCommand.h
// Author : Michael Enzelsberger
// Date : 09.01.2021
// Description : Concrete Command (does not do anything).
//////////////////////////////////////////

#ifndef NOCOMMAND_H
#define NOCOMMAND_H

#include "Object.h"
#include "Command.h"

class NoCommand : public Command, public Object
{
public:
	NoCommand() = default;
	void Execute() override{}
	void Undo() const override{}

};

#endif
