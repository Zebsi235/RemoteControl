//////////////////////////////////////////
// Workfile : StereoCD.h
// Author : Michael Enzelsberger
// Date : 09.01.2021
// Description : Header for StereoCD-Devices.
//////////////////////////////////////////

#ifndef STEREOCD_H
#define STEREOCD_H

#include "Device.h"
#include <fstream>
#include "TStateCD.h"

class StereoCD : public Device
{
public:
	void Info(std::ostream& ost) const override;
	void SetState(TStatePower const& state) override;
	TStatePower GetState() const override;
	void SetStateCD(TStateCD const& state);
	TStateCD GetStateCD() const;

	using SPtr = std::shared_ptr<StereoCD>;

private:
	TStateCD mStateCD = TStateCD::eClosed;
};

#endif