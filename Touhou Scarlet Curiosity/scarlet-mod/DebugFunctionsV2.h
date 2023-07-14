#pragma once

void InitDebugFunctionsV2()
{
    pDebugConsoleOutput("Using V2 Functions!", true, "red");
    pThreadHookerSuspendThreads(5);
    DWORD TextAddress = GetTextSectionBaseAddress(GameBaseAddress, ".text");
    //SetCamera_Hook<SetCameraT>::instance = new SetCamera_Hook<SetCameraT>((void*)(TextAddress + 0x213B10));
    //SetCamera_Hook<SetCameraT>::instance->install();
    pThreadHookerSuspendThreads(5);
}
