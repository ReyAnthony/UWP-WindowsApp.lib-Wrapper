#pragma once

#define APIWRAPPER_API __declspec(dllexport)

extern "C" {

	bool APIWRAPPER_API IsXbox();
	bool APIWRAPPER_API IsXboxOne();
	bool APIWRAPPER_API IsXboxOneS();
	bool APIWRAPPER_API IsXboxOneX();

	//Needs 10.0.22621.0
	//We still want people with Windows 10 to play this game
	//TODO Handle user calling this when OS is too old : 
	//https://learn.microsoft.com/en-gb/windows/uwp/updates-and-versions/choose-a-uwp-version?ocid=VSClient_VerX_NewProject_version
	bool APIWRAPPER_API IsXboxSeriesS();
	bool APIWRAPPER_API IsXboxSeriesX();
}