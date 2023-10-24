#include "pch.h"
#include "xNyuLibrary.h"

EXTERN_DLL_EXPORT void __cdecl OnInitDebugMod(DebugSettings _globalSettings, DebugFeatures* _features, DebugReferences _references, ThreadReferences _threadReferences)
{
	//
	// Standard initialization sequence, copy all debugaddress/function if needed, take settings and loggger and draw funtion pointers
	// Feature availability has to be written in the DebugFunction struct
	//

	GlobalSettings = _globalSettings;

	pDebugConsoleOutput = (DebugConsoleOutputT)_references.logger;
	pDebugDrawRectangle = (DebugDrawRectangleT)_references.drawRectangle;
	pDebugDrawText = (DebugDrawTextT)_references.drawText;

	pInstallGraphicHook = (InstallGraphicHookT)_references.installGraphicsHook;
	pRemoveGraphicHook = (RemoveGraphicHookT)_references.removeGraphicsHook;

	DebugFeatures features;
	features.debugAddress = true;
	features.debugFunction = true;
	features.savefileEditor = false;
	features.supervision = false;
	features.editorMode = false;

	pThreadHookerGetThreadCount = (ThreadHookerGetThreadCountT)_threadReferences.ThreadHookerGetThreadCount;
	pThreadHookerGetThreads = (ThreadHookerGetThreadsT)_threadReferences.ThreadHookerGetThreads;
	pThreadHookerGetSafeThreadCount = (ThreadHookerGetSafeThreadCountT)_threadReferences.ThreadHookerGetSafeThreadCount;
	pThreadHookerGetSafeThreads = (ThreadHookerGetSafeThreadsT)_threadReferences.ThreadHookerGetSafeThreads;
	pThreadHookerSuspendThreads = (ThreadHookerSuspendThreadsT)_threadReferences.ThreadHookerSuspendThreads;
	pThreadHookerResumeThreads = (ThreadHookerResumeThreadsT)_threadReferences.ThreadHookerResumeThreads;
	pThreadHookerCreateThread = (ThreadHookerCreateThreadT)_threadReferences.ThreadHookerCreateThread;
	pThreadHookerCreateRemoteThread = (ThreadHookerCreateRemoteThreadT)_threadReferences.ThreadHookerCreateRemoteThread;
	pThreadHookerCreateRemoteThreadEx = (ThreadHookerCreateRemoteThreadExT)_threadReferences.ThreadHookerCreateRemoteThreadEx;

	std::memcpy(_features, &features, sizeof(DebugFeatures));

	pTASRoutine = (TASRoutineT)_references.TASRoutine;
	
	if (GlobalSettings.config_version == "V1.1.0")
	{
		InitDebugAddressV110();
		InitDebugFunctionsV110();
	}

	GetMemoryRegions(memoryRegionsStart, memoryRegionsEnd, &memoryRegionsCounter);
}

bool originalPaused = false;
EXTERN_DLL_EXPORT void OnDebugMenu(bool isEnabled)
{
	// Pause game if debug menu is showing up
}

EXTERN_DLL_EXPORT void OnFrameDebugMod()
{
	pThreadHookerSuspendThreads(0);
	boolBuffer = DbgReadPointer(PlayerObjectBasepointer, &pointerBuffer);
	SetPlayerObjectInstance(pointerBuffer, boolBuffer);

	// EditorMode Handling
	if (EditorModeActivated)
	{
		canMove = false;
		canRotate = false;
		isRunning = false;
	}

	if (IsPlayerObjectInstance())
	{
		if (GodmodeActivated)
		{
			SetPlayerHPCurrent(GetPlayerHPMax());
			SetPlayerHealCooldown(10000000);
			pDebugDrawRectangle(325, 899, 20, 20, ColorBlack, 0.9f);
			pDebugDrawText("G", 335, 901, FontSmallMedium, ColorPink, 1.0f, "center");
		}

		if (LockPositionX) SetPlayerPositionX(PlayerPositionXLocked);
		if (LockPositionY) SetPlayerPositionY(PlayerPositionYLocked);
		if (LockPositionZ) SetPlayerPositionZ(PlayerPositionZLocked);
		if (LockAnimationIndex) SetPlayerAnimationIndex(PlayerAnimationIndexLocked);
	}

	if (updateSettingsFrameskip >= 120)
	{
		GetMemoryRegions(memoryRegionsStart, memoryRegionsEnd, &memoryRegionsCounter);
		updateSettingsFrameskip = 0;
	}
	pThreadHookerResumeThreads(0);
	updateSettingsFrameskip++;
}

EXTERN_DLL_EXPORT void OnExitDebugMod()
{

	//
	// This function get's called when den debug mod get's ejected, clear buffers and stuff here
	//

}


