#pragma once
#include <windows.h>
#include <windowsx.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <math.h>
#include <psapi.h>
#include <stdio.h>
#include <iomanip>
#include <filesystem>
#include <tlhelp32.h>
#include <ctime> 
#include <atlimage.h>
#include <thread>
#include <objidl.h>
#include <cmath>
#include <limits>
#include <shlobj.h>

std::string ToHexString(int value)
{
    std::stringstream stream;
    stream << "0X" << std::uppercase << std::setfill('0') << std::setw(sizeof(long long) * 2) << std::hex << value;
    return stream.str();
}

std::string ToHexString(long long value)
{
    std::stringstream stream;
    stream << "0X" << std::uppercase << std::setfill('0') << std::setw(sizeof(int) * 2) << std::hex << value;
    return stream.str();
}

std::string ToHexString(BYTE value)
{
    std::stringstream stream;
    stream << "0X" << std::uppercase << std::setfill('0') << std::setw(sizeof(BYTE) * 2) << std::hex << value;
    return stream.str();
}

std::string ToHexString(float value)
{
    std::stringstream stream;
    stream << "0X" << std::uppercase << std::setfill('0') << std::setw(sizeof(float) * 2) << std::hex << value;
    return stream.str();
}

std::string ToHexString(double value)
{
    std::stringstream stream;
    stream << "0X" << std::uppercase << std::setfill('0') << std::setw(sizeof(double) * 2) << std::hex << value;
    return stream.str();
}

//
// Definements ---------------------------------------------------------------------
//

#define EXTERN_DLL_EXPORT extern "C" __declspec(dllexport)

struct DebugSettings {
    std::string config_modname;
    std::string config_processname;
    std::string config_version;
    std::string config_mousedriver_set;
    std::string config_mousedriver_get;
    std::string config_keyboarddriver_set;
    std::string config_keyboarddriver_get;
    std::string config_joystickdriver_set;
    std::string config_joystickdriver_get;
    std::string config_graphicdriver;
    std::string config_root_directory;
    std::string config_settings_directory;
    std::string config_script_directory;
    std::string config_working_directory;
    std::string config_log_directory;
    std::string config_debugmod_directory;
    std::string config_debugfunction_directory;
    std::string config_debugaddress_directory;
    std::string config_inputmapping_directory;
    std::string config_savefile_directory;
    std::string config_debugconfig_directory;
    int config_frame_skip;
    int config_tas_delay;
};

DebugSettings GlobalSettings;

struct DebugFeatures
{
    bool debugAddress;
    bool debugFunction;
    bool savefileEditor;
    bool supervision;
};

std::string GetAppDataPath() {
    TCHAR path[MAX_PATH];
    if (SHGetFolderPathW(NULL, CSIDL_APPDATA, NULL, 0, path) == MB_OK) {
        std::wstring appDataPath = std::wstring(path) + L"\\";
        return std::string(appDataPath.begin(), appDataPath.end());
    }
    return "";
}

std::string AppdataRoamingPath = GetAppDataPath();


// After includes
#include "Typedefs.h"
#include "xNyuDrawingEssentials.h"
#include "BasePointer.h"
#include "ReadMemory.h"
#include "WriteMemory.h"
#include "SigScan.h"
#include "Variables.h"

#include "DebugAddressesGlobals.h"
#include "DebugAddressesV1.h"
#include "DebugAddressesV2.h"

#include "DebugAddresses.h"
#include "DebugFunctions.h"
#include "SavefileEditor.h"
#include "Supervision.h"



