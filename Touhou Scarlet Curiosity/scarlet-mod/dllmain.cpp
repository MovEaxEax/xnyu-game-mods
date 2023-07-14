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
	
	if (GlobalSettings.config_version == "v1.0")
	{
		InitDebugAddressV1();
		InitDebugFunctionsV1();
	}

	if (GlobalSettings.config_version == "v1.2")
	{
		InitDebugAddressV2();
		InitDebugFunctionsV2();
	}

	GetMemoryRegions(memoryRegionsStart, memoryRegionsEnd, &memoryRegionsCounter);
}

bool originalPaused = false;
EXTERN_DLL_EXPORT void OnDebugMenu(bool isEnabled)
{
	// Pause game if debug menu is showing up
	if (isEnabled)
	{
		originalPaused = DbgReadBool(IsGamePausedAddress);
		DbgWriteBool(IsGamePausedAddress, true);
	}
	else
	{
		DbgWriteBool(IsGamePausedAddress, originalPaused);
	}
}

EXTERN_DLL_EXPORT void OnFrameDebugMod()
{
	pThreadHookerSuspendThreads(0);
	boolBuffer = DbgReadPointer(PlayerObjectBasepointer, &pointerBuffer);
	SetPlayerObjectInstance(pointerBuffer, boolBuffer);
	boolBuffer = DbgReadPointer(CameraObjectBasepointer, &pointerBuffer);
	SetCameraObjectInstance(pointerBuffer, boolBuffer);
	boolBuffer = DbgReadPointer(GameGlobalsBasepointer, &pointerBuffer);
	SetGameGlobalsInstance(pointerBuffer, boolBuffer);
	for (int i = 0; i < 3; i++)
	{
		boolBuffer = DbgReadPointer(BossObjectBasepointer[i], &pointerBuffer);
		SetBossObjectInstance(pointerBuffer, boolBuffer, i);
	}
	for (int i = 0; i < 3; i++)
	{
		boolBuffer = DbgReadPointer(PlayerDisplayStatsBasepointer[i], &pointerBuffer);
		SetPlayerDisplayStatsInstance(pointerBuffer, boolBuffer, i);
	}
	boolBuffer = DbgReadInt32(CharacterUsedBasePointer, &int32Buffer);
	CharacterUsedCurrent =  boolBuffer ? int32Buffer : -1;
	for (int i = 0; i < 3; i++)
	{
		boolBuffer = DbgReadPointer(PlayerLevelStatsBasepointer[i], &pointerBuffer);
		SetPlayerLevelStatsInstance(pointerBuffer, boolBuffer, i);
	}
	pThreadHookerResumeThreads(0);

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
			SetPlayerEnergyCurrent(GetPlayerEnergyMax() * 1000);
			SetPlayerSpellcardBar(1000);
			pDebugDrawRectangle(325, 899, 20, 20, ColorBlack, 0.9f);
			pDebugDrawText("G", 335, 901, FontSmallMedium, ColorPink, 1.0f, "center");
		}

		if (LockPositionX) SetPlayerPositionX(PlayerPositionXLocked);
		if (LockPositionY) SetPlayerPositionY(PlayerPositionYLocked);
		if (LockPositionZ) SetPlayerPositionZ(PlayerPositionZLocked);
		if (LockDirection) SetPlayerDirection(PlayerDirectionLocked);
		if (LockSpeedFactorX) SetPlayerSpeedFactorX(PlayerSpeedFactorXLocked);
		if (LockSpeedFactorY) SetPlayerSpeedFactorX(PlayerSpeedFactorYLocked);
		if (LockSpeedFactorZ) SetPlayerSpeedFactorX(PlayerSpeedFactorZLocked);
		if (LockAnimationIndex) SetPlayerAnimationIndex(PlayerAnimationIndexLocked);
	}

	if (IsCameraObjectInstance())
	{
		if (LockCameraPositionX) SetCameraPositionX(CameraPositionXLocked);
		if (LockCameraPositionY) SetCameraPositionY(CameraPositionYLocked);
		if (LockCameraPositionZ) SetCameraPositionZ(CameraPositionZLocked);
		if (LockCameraAngleX) SetCameraAngleX(CameraAngleXLocked);
		if (LockCameraAngleY) SetCameraAngleY(CameraAngleYLocked);
		if (LockCameraAngleZ) SetCameraAngleZ(CameraAngleZLocked);
		if (LockCameraZoom) SetCameraZoom(CameraZoomLocked);
	}

	for (int i = 0; i < 3; i++)
	{
		if (IsBossObjectInstance(i))
		{
			if (LockBossPositionX[i]) SetBossPositionX(BossPositionXLocked[i], i);
			if (LockBossPositionY[i]) SetBossPositionY(BossPositionYLocked[i], i);
			if (LockBossPositionZ[i]) SetBossPositionZ(BossPositionZLocked[i], i);
			if (LockBossDirection[i]) SetBossDirection(BossDirectionLocked[i], i);
			if (LockBossAnimationIndex[i]) SetBossAnimationIndex(BossAnimationIndexLocked[i], i);
		}
	}

	if (updateSettingsFrameskip >= 120)
	{
		GetMemoryRegions(memoryRegionsStart, memoryRegionsEnd, &memoryRegionsCounter);
		updateSettingsFrameskip = 0;
	}
	updateSettingsFrameskip++;
}

EXTERN_DLL_EXPORT void OnExitDebugMod()
{

	//
	// This function get's called when den debug mod get's ejected, clear buffers and stuff here
	//

}


