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
	void OnButtonPressed(size_t const slotNr);
	void OffButtonPressed(size_t const slotNr);
	void UndoButtonPressed();
	void ProgramSlot(std::string const& slotName, size_t const slotNr, 
	Command::SPtr const& onCmd, Command::SPtr const& offCmd);

	void PrintRemoteInfo(std::ostream& ost);
	std::string GetSlotName(size_t const slotNr);

	using SPtr = std::shared_ptr<RemoteControl>;

private:
	Slot mSlots[numOfSlots];
	Command::SPtr mPrevCmd;
};

#endif