
void InitDebugFunctionsV110()
{
    pDebugConsoleOutput("Using V1.1.0 Functions!", true, "red");
    pThreadHookerSuspendThreads(5);
    DWORD TextAddress = GetTextSectionBaseAddress(GameBaseAddress, ".text");
    //SetCameraPosition_Hook<SetCameraPositionT>::instance = new SetCameraPosition_Hook<SetCameraPositionT>((void*)(TextAddress + 0x114630));
    //SetCameraPosition_Hook<SetCameraPositionT>::instance->install();
    //SetCameraRotation_Hook<SetCameraRotationT>::instance = new SetCameraRotation_Hook<SetCameraRotationT>((void*)(TextAddress + 0x3BE2C0));
    //SetCameraRotation_Hook<SetCameraRotationT>::instance->install();
    pThreadHookerSuspendThreads(5);
}
