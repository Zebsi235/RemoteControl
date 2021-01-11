//////////////////////////////////////////
// Workfile : Client.cpp
// Author : Michael Enzelsberger
// Date : 09.01.2021
// Description : Client that connects 
//				 Devices to RemoteControl.
//////////////////////////////////////////

#include "Client.h"
#include "Stereo.h"

using namespace std;

Client::Client(RemoteControl::SPtr const& remote)
{
	//check nullptr
	if (remote == nullptr)
	{
		throw string("null pointer in Client CTOR");
	}
	//store remote control
	mRemote = remote;
}

void Client::AddDevice(std::string const& slotName, size_t const slotNr,
	Device::SPtr const& device, Command::SPtr const& onCmd, Command::SPtr const& offCmd)
{
	//check device and commands for nullptr
	if (device == nullptr || onCmd == nullptr || offCmd == nullptr)
	{
		throw string("null pointer in Client AddDevice");
	}

	//check if slotNr is valid
	if (slotNr == 0 || slotNr > numOfSlots)
	{
		throw string("slot number must be between 1 and 6");
	}

	//calls function which programs the slot for the device
	mRemote->ProgramSlot(slotName, slotNr, onCmd, offCmd);
	//stores device in device array
	mDevices[slotNr - 1] = device;
}

void Client::PrintDeviceInfo(std::ostream& ost) const
{
	//print header
	ost << endl << "devices:" << endl;
	ost << "----------------------" << endl;

	//print info for each device
	for (size_t i = 0; i < numOfSlots; i++)
	{
		//only print if device is existing
		if (mDevices[i] != nullptr)
		{
			//first print name of the device
			ost << mRemote->GetSlotName(i + 1) << ": ";
			mDevices[i]->Info(ost);
		}
	}
}
