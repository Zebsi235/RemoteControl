//////////////////////////////////////////
// Workfile : StereoCD.h
// Author : Michael Enzelsberger
// Date : 09.01.2021
// Description : Header for StereoCD-Devices.
//////////////////////////////////////////

#ifndef STEREOCD_H
#define STEREOCD_H

#include "Object.h"
#include "Device.h"
#include <fstream>
#include "TStateCD.h"

class StereoCD : public Device, public Object
{
public:
	//Print function
	void Info(std::ostream& ost) const override;
	//Set functions
	void SetState(TStatePower const& state) override;
	void SetStateCD(TStateCD const& state);
	//Get functions
	TStatePower GetState() const override;
	TStateCD GetStateCD() const;

	using SPtr = std::shared_ptr<StereoCD>;

private:
	TStateCD mStateCD = TStateCD::eClosed;
};

#endif