////////////////////////////////
// Workfile : main.cpp
// Date : 19.12.2020
// Description : Testing Driver
////////////////////////////////

#include <iostream>
#include <cassert>
#include <string>
#include <memory>
//#include <vld.h>

#include "RemoteControl.h"
#include "Client.h"
#include "TStateCD.h"
#include "TStatePower.h"
#include "Device.h"
#include "TV.h"
#include "Heating.h"
#include "Stereo.h"
#include "On.h"
#include "Off.h"
#include "Open.h"
#include "Close.h"
#include "NoCommand.h"

using namespace std;

int main()
{
	try
	{
		RemoteControl::SPtr ferni{ make_shared<RemoteControl>() };
		TV::SPtr tv{ make_shared<TV>() };
		Heating::SPtr heizung{ make_shared<Heating>() };
		Stereo::SPtr anlage{ make_shared<Stereo>(nullptr) };
		StereoCD::SPtr CD{ make_shared<StereoCD>() };
		Stereo::SPtr anlage2{ make_shared<Stereo>(CD) };
		Client client{ ferni };

		client.AddDevice("Samsung", 3, tv, make_shared<On>(tv), make_shared<Off>(tv));
		client.AddDevice("Heizung", 1, heizung, make_shared<On>(heizung), make_shared<Off>(heizung));
		client.AddDevice("Stereo ohne CD", 4, anlage, make_shared<On>(anlage), make_shared<Off>(anlage));
		client.AddDevice("Stereo mit CD", 5, anlage2, make_shared<On>(anlage2), make_shared<Off>(anlage2));
		client.AddDevice("Laufwerk", 6, CD, make_shared<Open>(CD), make_shared<Close>(CD));

		string input = "";
		size_t slot = 0;

		ferni->PrintRemoteInfo(cout);

		while (true)
		{
			getline(cin, input);

			if (input.length() == 2)
			{
				switch (input[0])
				{
				case '1':
					slot = 1;
					break;
				case '2':
					slot = 2;
					break;
				case '3':
					slot = 3;
					break;
				case '4':
					slot = 4;
					break;
				case '5':
					slot = 5;
					break;
				case '6':
					slot = 6;
					break;
				default:
					slot = 0;
					break;
				}

				if (slot != 0)
				{
					switch (input[1])
					{
					case 'o':
						ferni->OnButtonPressed(slot);
						break;
					case 'f':
						ferni->OffButtonPressed(slot);
						break;
					default:
						break;
					}
				}
			}
			else if (input.length() == 1)
			{
				switch (input[0])
				{
				case 'u':
					ferni->UndoButtonPressed();
					break;
				case 'i':
					client.PrintDeviceInfo(cout);
					break;
				default:
					break;
				}
			}
			else
			{
				cout << "wrong input!" << endl;
			}
		}
	}
	catch (string const& error)
	{
		assert(!error.empty());
		cerr << error << endl;

		return 1; // Programm mit Fehlercode beenden
	}
	catch (bad_alloc const& error)
	{
		cerr << "memory allocation: " << error.what() << endl;

		return 1;
	}
	catch (exception const& error)
	{
		cerr << "standard exception: " << error.what() << endl;

		return 1;
	}
	catch (...)
	{
		cerr << "unhandled exception" << endl;

		return 1;
	}

	return 0;
}