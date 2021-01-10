#include "Client.h"
#include "Stereo.h"

using namespace std;

Client::Client(RemoteControl::SPtr const& remote)
{
	if (remote == nullptr)
	{
		throw string("null pointer in Client CTOR");
	}

	mRemote = remote;
}

void Client::AddDevice(std::string const& slotName, size_t const slotNr,
	Device::SPtr const& device, Command::SPtr const& onCmd, Command::SPtr const& offCmd)
{
	if (device == nullptr || onCmd == nullptr || offCmd == nullptr)
	{
		throw string("null pointer in Client AddDevice");
	}

	if (slotNr == 0 || slotNr > numOfSlots)
	{
		throw string("slot number must be between 1 and 6");
	}

	mRemote->ProgramSlot(slotName, slotNr, onCmd, offCmd);
	mDevices[slotNr - 1] = device;
}

void Client::PrintDeviceInfo(std::ostream& ost) const
{
	ost << endl << "devices:" << endl;
	ost << "----------------------" << endl;

	for (size_t i = 0; i < numOfSlots; i++)
	{
		if (mDevices[i] != nullptr)
		{
			ost << mRemote->GetSlotName(i + 1) << ": ";
			mDevices[i]->Info(ost);
		}
	}
}
