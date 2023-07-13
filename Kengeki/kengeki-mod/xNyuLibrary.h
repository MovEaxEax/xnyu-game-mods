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
#include <mutex>

#define PI 3.14159265

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

std::string GetCurrentDateTime() {
    std::stringstream ss;
    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    ss << std::put_time(std::localtime(&time), "%Y-%m-%d %H-%M-%S");
    return ss.str();
}

DWORD GetTextSectionBaseAddress(HMODULE moduleHandle, std::string sectionName) {
    PIMAGE_DOS_HEADER dosHeader = (PIMAGE_DOS_HEADER)moduleHandle;
    PIMAGE_NT_HEADERS ntHeaders = (PIMAGE_NT_HEADERS)((BYTE*)moduleHandle + dosHeader->e_lfanew);

    PIMAGE_SECTION_HEADER sectionHeader = IMAGE_FIRST_SECTION(ntHeaders);
    for (UINT i = 0; i < ntHeaders->FileHeader.NumberOfSections; ++i, ++sectionHeader) {
        if (memcmp(sectionHeader->Name, sectionName.c_str(), 5) == 0) {
            return (DWORD)moduleHandle + sectionHeader->VirtualAddress;
        }
    }

    return NULL;
}

void SuspendOtherThreads() {
    DWORD currentThreadId = GetCurrentThreadId();
    HANDLE hThreadSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
    if (hThreadSnapshot == INVALID_HANDLE_VALUE) {
        return;
    }

    THREADENTRY32 threadEntry;
    threadEntry.dwSize = sizeof(THREADENTRY32);

    if (Thread32First(hThreadSnapshot, &threadEntry)) {
        do {
            if (threadEntry.th32OwnerProcessID == GetCurrentProcessId() &&
                threadEntry.th32ThreadID != currentThreadId) {
                HANDLE hThread = OpenThread(THREAD_SUSPEND_RESUME, FALSE, threadEntry.th32ThreadID);
                if (hThread != NULL) {
                    SuspendThread(hThread);
                    CloseHandle(hThread);
                }
            }
        } while (Thread32Next(hThreadSnapshot, &threadEntry));
    }

    CloseHandle(hThreadSnapshot);
}

void ResumeOtherThreads() {
    DWORD currentThreadId = GetCurrentThreadId();
    HANDLE hThreadSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
    if (hThreadSnapshot == INVALID_HANDLE_VALUE) {
        return;
    }

    THREADENTRY32 threadEntry;
    threadEntry.dwSize = sizeof(THREADENTRY32);

    if (Thread32First(hThreadSnapshot, &threadEntry)) {
        do {
            if (threadEntry.th32OwnerProcessID == GetCurrentProcessId() &&
                threadEntry.th32ThreadID != currentThreadId) {
                HANDLE hThread = OpenThread(THREAD_SUSPEND_RESUME, FALSE, threadEntry.th32ThreadID);
                if (hThread != NULL) {
                    ResumeThread(hThread);
                    CloseHandle(hThread);
                }
            }
        } while (Thread32Next(hThreadSnapshot, &threadEntry));
    }

    CloseHandle(hThreadSnapshot);
}



typedef void(__stdcall* TASRoutineT)();
TASRoutineT pTASRoutine = nullptr;

int updateSettingsFrameskip = 0;

uintptr_t memoryRegionsStart[65000];
uintptr_t memoryRegionsEnd[65000];
int memoryRegionsCounter = 0;

void GetMemoryRegions(uintptr_t* srcRegions, uintptr_t* dstRegions, int* count) {
    HANDLE processHandle = GetCurrentProcess();
    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);

    int Counter = 0;

    LPVOID lpAddress = systemInfo.lpMinimumApplicationAddress;
    while (lpAddress < systemInfo.lpMaximumApplicationAddress) {
        MEMORY_BASIC_INFORMATION memInfo;
        SIZE_T bytesReturned = VirtualQueryEx(processHandle, lpAddress, &memInfo, sizeof(memInfo));
        if (bytesReturned == 0) {
            break;
        }

        // Check if the memory region is readable and/or writable
        if (memInfo.Protect & (PAGE_READONLY | PAGE_READWRITE | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE)) {
            Counter++;
        }

        lpAddress = (LPVOID)((DWORD_PTR)memInfo.BaseAddress + memInfo.RegionSize);
    }

    //srcRegions = new uintptr_t[Counter];
    //dstRegions = new uintptr_t[Counter];

    Counter = 0;
    lpAddress = systemInfo.lpMinimumApplicationAddress;
    while (lpAddress < systemInfo.lpMaximumApplicationAddress) {
        MEMORY_BASIC_INFORMATION memInfo;
        SIZE_T bytesReturned = VirtualQueryEx(processHandle, lpAddress, &memInfo, sizeof(memInfo));
        if (bytesReturned == 0) {
            break;
        }

        if (memInfo.Protect & (PAGE_READONLY | PAGE_READWRITE | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE)) {
            uintptr_t start = (uintptr_t)memInfo.BaseAddress;
            uintptr_t end = (uintptr_t)memInfo.BaseAddress + memInfo.RegionSize;
            std::memcpy(srcRegions + (Counter * sizeof(uintptr_t)), &start, sizeof(uintptr_t));
            std::memcpy(dstRegions + (Counter * sizeof(uintptr_t)), &end, sizeof(uintptr_t));
            //std::cout << "Start: " << std::hex << srcRegions[Counter] << " | End: " << dstRegions[Counter] << std::endl;
            Counter++;
        }

        lpAddress = (LPVOID)((DWORD_PTR)memInfo.BaseAddress + memInfo.RegionSize);
    }

    std::memcpy(count, &Counter, sizeof(int));
}

//
// Definements ---------------------------------------------------------------------
//

#define EXTERN_DLL_EXPORT extern "C" __declspec(dllexport)

struct DebugSettings {
    std::string config_modname;
    std::string config_processname;
    std::string config_version;
    std::string config_tashook;
    std::string config_mousedriver_set;
    std::string config_mousedriver_get;
    std::string config_keyboarddriver_set;
    std::string config_keyboarddriver_get;
    std::string config_joystickdriver_set;
    std::string config_joystickdriver_get;
    std::string config_graphicdriver;
    std::string config_d3d9_hook;
    bool config_rawinput_demand;
    std::string config_root_directory;
    std::string config_settings_directory;
    std::string config_script_directory;
    std::string config_working_directory;
    std::string config_log_directory;
    std::string config_debugmod_directory;
    std::string config_debugfunction_directory;
    std::string config_debugaddress_directory;
    std::string config_editormode_directory;
    std::string config_supervision_directory;
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
    bool editorMode;
};

struct DebugReferences
{
    void* logger;
    void* drawRectangle;
    void* drawText;
    void* TASRoutine;
    void* installGraphicsHook;
    void* removeGraphicsHook;
};

struct Point
{
    float x;
    float y;
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
HMODULE GameBaseAddress = GetModuleHandle(NULL);

// After includes
#include "GraphicsHook.h"

#include "PlayerObjectV1.h"
#include "BossObjectV1.h"
#include "CameraObjectV1.h"
#include "GameGlobalsV1.h"
#include "SavefileV1.h"

#include "PlayerObjectV2.h"
#include "BossObjectV2.h"
#include "CameraObjectV2.h"
#include "GameGlobalsV2.h"
#include "SavefileV2.h"

#include "KengekiObjects.h"

#include "Typedefs.h"
#include "xNyuDrawingEssentials.h"
#include "BasePointer.h"
#include "ReadMemory.h"
#include "WriteMemory.h"
#include "SigScan.h"
#include "Variables.h"
#include "Settings.h"

#include "DebugAddressesGlobals.h"
#include "DebugAddressesV1.h"
#include "DebugAddressesV2.h"

#include "DebugFunctionsGlobals.h"
#include "DebugFunctionsV1.h"
#include "DebugFunctionsV2.h"

#include "DebugAddresses.h"
#include "DebugFunctions.h"
#include "SavefileEditor.h"
#include "Supervision.h"
#include "EditorMode.h"


