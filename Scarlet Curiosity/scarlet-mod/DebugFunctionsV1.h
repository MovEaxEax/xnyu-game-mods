
typedef int(__thiscall* SetCameraPositionT)(void* camera, Vector3* position);

template <typename FuncT>
class SetCameraPosition_Hook : public xNyuHook<SetCameraPositionT> {
public:
    static SetCameraPosition_Hook* instance;
    SetCameraPosition_Hook(void* originalAddress, void* hookExecuteBefore = nullptr, void* hookExecuteAfter = nullptr)
        : xNyuHook<SetCameraPositionT>(originalAddress, hookExecuteBefore, hookExecuteAfter) {
        instance = this;
    }
    static int __thiscall CustomHook(void* camera, Vector3* position)
    {
        instance->remove();
        if (IsCameraObjectInstance() && cameraObjectV1 == camera)
        {
            if (EditorModeActivated)
            {
                SetCameraPosition(EditorModeCameraPosition);
                SetCameraRotation(EditorModeCameraRotation);
            }
        }
        int result = instance->pFunction(camera, position);
        instance->install();
        return result;
    }
    void install() {
        if (sizeof(void*) == 8) Subhook.Install((void*)instance->pFunction, instance->CustomHook, subhook::HookFlags::HookFlag64BitOffset);
        if (sizeof(void*) == 4) Subhook.Install((void*)instance->pFunction, instance->CustomHook);
    }
};
SetCameraPosition_Hook<SetCameraPositionT>* SetCameraPosition_Hook<SetCameraPositionT>::instance = nullptr;



typedef void(__thiscall* SetCameraRotationT)(void* camera);

template <typename FuncT>
class SetCameraRotation_Hook : public xNyuHook<SetCameraRotationT> {
public:
    static SetCameraRotation_Hook* instance;
    SetCameraRotation_Hook(void* originalAddress, void* hookExecuteBefore = nullptr, void* hookExecuteAfter = nullptr)
        : xNyuHook<SetCameraRotationT>(originalAddress, hookExecuteBefore, hookExecuteAfter) {
        instance = this;
    }
    static void __thiscall CustomHook(void* camera)
    {
        instance->remove();
        if (IsCameraObjectInstance())
        {
            if (EditorModeActivated)
            {
                instance->install();
                return;
            }
        }
        instance->pFunction(camera);
        instance->install();
    }
    void install() {
        if (sizeof(void*) == 8) Subhook.Install((void*)instance->pFunction, instance->CustomHook, subhook::HookFlags::HookFlag64BitOffset);
        if (sizeof(void*) == 4) Subhook.Install((void*)instance->pFunction, instance->CustomHook);
    }
};
SetCameraRotation_Hook<SetCameraRotationT>* SetCameraRotation_Hook<SetCameraRotationT>::instance = nullptr;



void InitDebugFunctionsV1()
{
    pDebugConsoleOutput("Using V1 Functions!", true, "red");
    pThreadHookerSuspendThreads(5);
    DWORD TextAddress = GetTextSectionBaseAddress(GameBaseAddress, ".text");
    SetCameraPosition_Hook<SetCameraPositionT>::instance = new SetCameraPosition_Hook<SetCameraPositionT>((void*)(TextAddress + 0x114630));
    SetCameraPosition_Hook<SetCameraPositionT>::instance->install();
    SetCameraRotation_Hook<SetCameraRotationT>::instance = new SetCameraRotation_Hook<SetCameraRotationT>((void*)(TextAddress + 0x3BE2C0));
    SetCameraRotation_Hook<SetCameraRotationT>::instance->install();
    pThreadHookerSuspendThreads(5);
}
