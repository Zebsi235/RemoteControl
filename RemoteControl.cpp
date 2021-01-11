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
	//initialize each slot with empty and NoCommand at first
	for (size_t i = 1; i <= numOfSlots; i++)
	{
		ProgramSlot("empty", i, make_shared<NoCommand>(), make_shared<NoCommand>());
	}
}

void RemoteControl::OnButtonPressed(size_t const slotNr)
{
	//check if slotNr is valid
	if (slotNr == 0 || slotNr > numOfSlots)
	{
		throw string("slot number must be between 1 and 6");
	}

	//Get the right command and store as previous command
	mPrevCmd = mSlots[slotNr - 1].GetOn();
	//execute the on command
	mSlots[slotNr - 1].GetOn()->Execute();
}

void RemoteControl::OffButtonPressed(size_t const slotNr)
{
	//check if slotNr is valid
	if (slotNr == 0 || slotNr > numOfSlots)
	{
		throw string("slot number must be between 1 and 6");
	}

	//get the right off command and store as previous command
	mPrevCmd = mSlots[slotNr - 1].GetOff();
	//execute the off command
	mSlots[slotNr - 1].GetOff()->Execute();
}

void RemoteControl::UndoButtonPressed()
{
	//call undo function of the previous command
	mPrevCmd->Undo();
}

void RemoteControl::ProgramSlot(std::string const& slotName, size_t const slotNr, 
		Command::SPtr const& onCmd, Command::SPtr const& offCmd)
{
	//check for nullpointer
	if (onCmd == nullptr || offCmd == nullptr)
	{
		throw string("null pointer in RemoteControl ProgramSlot");
	}

	//check if slotNr is valid
	if (slotNr == 0 || slotNr > numOfSlots)
	{
		throw string("slot number must be between 1 and 6");
	}

	//Set the information required for each slot
	mSlots[slotNr - 1].SetName(slotName);
	mSlots[slotNr - 1].SetOn(onCmd);
	mSlots[slotNr - 1].SetOff(offCmd);
}

void RemoteControl::PrintRemoteInfo(std::ostream& ost)
{
	ost << "remote control:" << endl;
	ost << "-----------------------" << endl;

	//print info for each slot
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
	//check if slotNr is valid
	if (slotNr == 0 || slotNr > numOfSlots)
	{
		throw string("slot number must be between 1 and 6");
	}

	//get name of corresponding slot
	return mSlots[slotNr - 1].GetName();
}
