//////////////////////////////////////////
// Workfile : RemoteControl.h
// Author : Michael Enzelsberger
// Date : 09.01.2021
// Description : Invoker for remote control
//////////////////////////////////////////

#ifndef REMOTECONTROL_H
#define REMOTECONTROL_H

#include "Object.h"
#include "Command.h"
#include "Device.h"
#include "Slot.h"

static size_t const numOfSlots = 6;

class RemoteControl : public Object
{
public:
	RemoteControl();
	//method to execute the on-command of given slotNr
	void OnButtonPressed(size_t const slotNr);
	//method to execute the off-command of given slotNr
	void OffButtonPressed(size_t const slotNr);
	//method to revert the last command
	void UndoButtonPressed();
	//method to programm a device to a given slot
	void ProgramSlot(std::string const& slotName, size_t const slotNr, 
	Command::SPtr const& onCmd, Command::SPtr const& offCmd);

	//prints all slots to the given ostream
	void PrintRemoteInfo(std::ostream& ost);
	//returns the name of slotNr
	std::string GetSlotName(size_t const slotNr);

	using SPtr = std::shared_ptr<RemoteControl>;

private:
	Slot mSlots[numOfSlots];
	Command::SPtr mPrevCmd;
};

#endif