//////////////////////////////////////////
// Workfile : Client.h
// Author : Michael Enzelsberger
// Date : 09.01.2021
// Description : Client that connects 
//				 Devices to RemoteControl.
//////////////////////////////////////////

#ifndef CLIENT_H
#define CLIENT_H

#include "Object.h"
#include "RemoteControl.h"

class Client: public Object
{
public:
	Client(RemoteControl::SPtr const& remote);
	void AddDevice(std::string const& slotName, size_t const slotNr, 
		Device::SPtr const& device, Command::SPtr const& onCmd, Command::SPtr const& offCmd);
	void PrintDeviceInfo(std::ostream& ost) const;
private:
	RemoteControl::SPtr mRemote;
	Device::SPtr mDevices[numOfSlots] = { nullptr };
};

#endif
