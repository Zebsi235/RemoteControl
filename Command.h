//////////////////////////////////////////
// Workfile : Command.h
// Author : Michael Enzelsberger
// Date : 09.01.2021
// Description : Interface for commands.
//////////////////////////////////////////

#ifndef COMMAND_H
#define COMMAND_H

#include <memory>

class Command
{
public:
	virtual void Execute() = 0;
	virtual void Undo() const = 0;
	virtual ~Command() = default;

	using SPtr = std::shared_ptr<Command>;
};

#endif