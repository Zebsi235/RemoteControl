//////////////////////////////////////////
// Workfile : Stereo.h
// Author : Pascal Lang
// Date : 09.01.2021
// Description : Header for Stereo-Devices.
//////////////////////////////////////////

#ifndef STEREO_H
#define STEREO_H

#include "Object.h"
#include "Device.h"
#include "StereoCD.h"
#include <fstream>
#include "TStatePower.h"


class Stereo : public Device, public Object
{
public:
	
	//it is possible to create a stereo device with or 
	//without a cd drive.
	Stereo(StereoCD::SPtr const& cd);
	void Info(std::ostream& ost) const override;
	void SetState(TStatePower const& state) override;
	TStatePower GetState() const override;

	using SPtr = std::shared_ptr<Stereo>;
	
private:
	TStatePower mState = TStatePower::eOff;
	StereoCD::SPtr mCD_Unit = nullptr;
};

#endif