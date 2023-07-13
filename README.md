# UWP-WindowsApp.lib-Wrapper
Wrapping GetGamingDeviceModelInformation (for now) for detecting Xbox console type

For the record, because Microsoft Documentation is rather *lacking*... This code needs to linked against WindowsApp.lib.

Example usage in Unity : 

```
using System.Runtime.InteropServices;
using UnityEngine;

namespace CoreToolset
{
    public static class PlatformHelper
    {
        public static bool IsConsole => SystemInfo.deviceType == DeviceType.Console || Application.isConsolePlatform;

#if UNITY_WSA
        public static bool IsWSA => true;
#else
        public static bool IsWSA => false;
#endif

        public static bool IsPC => SystemInfo.deviceType == DeviceType.Desktop;
        public static bool IsWsaConsole => IsWSA && IsConsole;
        public static bool IsWsaPC => IsWSA && IsPC;

#if UNITY_WSA && !UNITY_EDITOR
        private const string DLL = "UWPWindowsAPIWrapper.dll";

        [DllImport(DLL)]
        public static extern bool IsXbox();

        [DllImport(DLL)]
        public static extern bool IsXboxOne();

        [DllImport(DLL)]
        public static extern bool IsXboxOneS();

        [DllImport(DLL)]
        public static extern bool IsXboxOneX();

        [DllImport(DLL)]
        public static extern bool IsXboxSeriesS();

        [DllImport(DLL)]
        public static extern bool IsXboxSeriesX();
#else
        public static bool IsXbox() => false;
        public static bool IsXboxOne() => false;
        public static bool IsXboxOneS() => false;
        public static bool IsXboxOneX() => false;
        public static bool IsXboxSeriesS() => false;
        public static bool IsXboxSeriesX() => false;
#endif

        public static bool IsWsaXbox => IsWSA && IsXbox();
        public static bool IsWsaXboxOne => IsWSA && IsXboxOne();
        public static bool IsWsaXboxOneS => IsWSA && IsXboxOneS();
        public static bool IsWsaXboxOneX => IsWSA && IsXboxOneX();
        public static bool IsWsaXboxSeriesS => IsWSA && IsXboxSeriesS();
        public static bool IsWsaXboxSeriesX => IsWSA && IsXboxSeriesX();
    }
}
```
