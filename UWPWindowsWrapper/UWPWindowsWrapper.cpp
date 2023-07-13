#include "pch.h"
#include <gamingdeviceinformation.h>
#include "UWPWindowsWrapper.h"

//Thank you microsoft, I searched what to link for 2 HOURS
//https://learn.microsoft.com/fr-fr/uwp/win32-and-com/win32-apis

GAMING_DEVICE_DEVICE_ID GetGamingDeviceModelInfos();
GAMING_DEVICE_DEVICE_ID GetGamingDeviceModelInfos()
{
    GAMING_DEVICE_MODEL_INFORMATION infos;
    if (FAILED(GetGamingDeviceModelInformation(&infos)))
    {
        return GAMING_DEVICE_DEVICE_ID_NONE;
    }
    return infos.deviceId;
}

bool IsXbox()
{
    return GetGamingDeviceModelInfos() != GAMING_DEVICE_DEVICE_ID_NONE;
}

bool IsXboxOne()
{
    return GetGamingDeviceModelInfos() == GAMING_DEVICE_DEVICE_ID_XBOX_ONE;
}

bool IsXboxOneS()
{
    return GetGamingDeviceModelInfos() == GAMING_DEVICE_DEVICE_ID_XBOX_ONE_S;
}

bool IsXboxOneX()
{
    return GetGamingDeviceModelInfos() == GAMING_DEVICE_DEVICE_ID_XBOX_ONE_X;
}

bool IsXboxSeriesS()
{
    return GetGamingDeviceModelInfos() == GAMING_DEVICE_DEVICE_ID_XBOX_SERIES_S;
}

bool IsXboxSeriesX()
{
    return GetGamingDeviceModelInfos() == GAMING_DEVICE_DEVICE_ID_XBOX_SERIES_X;
}
