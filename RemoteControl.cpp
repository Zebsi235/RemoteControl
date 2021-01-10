//////////////////////////////////////////
// Workfile : RemoteControl.cpp
// Author : Michael Enzelsberger
// Date : 09.01.2021
// Description : Invoker for remote control
//////////////////////////////////////////

#include "RemoteControl.h"
#include "NoCommand.h"

using namespace std;

RemoteControl::RemoteControl()
{
	for (size_t i = 1; i <= numOfSlots; i++)
	{
		
		ProgramSlot("empty", i, make_shared<NoCommand>(), make_shared<NoCommand>());
	}
}

void RemoteControl::OnButtonPressed(size_t const slotNr)
{
	if (slotNr == 0 || slotNr > numOfSlots)
	{
		throw string("slot number must be between 1 and 6");
	}

	mPrevCmd = mSlots[slotNr - 1].GetOn();
	mSlots[slotNr - 1].GetOn()->Execute();
}

void RemoteControl::OffButtonPressed(size_t const slotNr)
{
	if (slotNr == 0 || slotNr > numOfSlots)
	{
		throw string("slot number must be between 1 and 6");
	}

	mPrevCmd = mSlots[slotNr - 1].GetOff();
	mSlots[slotNr - 1].GetOff()->Execute();
}

void RemoteControl::UndoButtonPressed()
{
	mPrevCmd->Undo();
}

void RemoteControl::ProgramSlot(std::string const& slotName, size_t const slotNr, 
		Command::SPtr const& onCmd, Command::SPtr const& offCmd)
{
	if (onCmd == nullptr || offCmd == nullptr)
	{
		throw string("null pointer in RemoteControl ProgramSlot");
	}

	if (slotNr == 0 || slotNr > numOfSlots)
	{
		throw string("slot number must be between 1 and 6");
	}

	mSlots[slotNr - 1].SetName(slotName);
	mSlots[slotNr - 1].SetOn(onCmd);
	mSlots[slotNr - 1].SetOff(offCmd);
}

void RemoteControl::PrintRemoteInfo(std::ostream& ost)
{
	ost << "remote control:" << endl;
	ost << "-----------------------" << endl;

	for (size_t i = 0; i < numOfSlots; i++)
	{
		ost << i + 1 << "..." << mSlots[i].GetName() << endl;
	}

	ost << "u...undo" << endl << "i...output device info" << endl;
	ost << "-----------------------" << endl;
	ost << "input slot number and on('o') or off('f'): " << endl;
}

std::string RemoteControl::GetSlotName(size_t const slotNr)
{
	if (slotNr == 0 || slotNr > numOfSlots)
	{
		throw string("slot number must be between 1 and 6");
	}

	return mSlots[slotNr - 1].GetName();
}
