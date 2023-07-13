#include "pch.h"
#include "xNyuLibrary.h"

EXTERN_DLL_EXPORT void __cdecl OnInitDebugMod(DebugSettings _globalSettings, DebugFeatures* _features, DebugReferences _references)
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
	features.savefileEditor = true;
	features.supervision = false;
	features.editorMode = false;

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
	boolBuffer = DbgReadPointer(PlayerObjectBasepointer, &pointerBuffer);
	SetPlayerObjectInstance(pointerBuffer, boolBuffer);
	boolBuffer = DbgReadPointer(CameraObjectBasepointer, &pointerBuffer);
	SetCameraObjectInstance(pointerBuffer, boolBuffer);
	boolBuffer = DbgReadPointer(GameGlobalsBasepointer, &pointerBuffer);
	SetGameGlobalsInstance(pointerBuffer, boolBuffer);
	boolBuffer = DbgReadPointer(BossObjectBasepointer, &pointerBuffer);
	SetBossObjectInstance(pointerBuffer, boolBuffer);

	if (IsPlayerObjectInstance())
	{
		if (GodmodeActivated)
		{
			Variable GodModeValue;
			GodModeValue.type = "int32";
			GodModeValue.value = "5000";
			SetPlayerHP(GetVariableInt32(&GodModeValue));
			SetPlayerEnergy(GetVariableInt32(&GodModeValue));
			SetPlayerSpellcardBar(GetVariableInt32(&GodModeValue));
			pDebugDrawRectangle(1800, 800, 20, 20, ColorBlack, 0.9f);
			pDebugDrawText("G", 1810, 802, FontSmallMedium, ColorWhite, 1.0f, "center");
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

	if (IsBossObjectInstance())
	{
		if (LockBossPositionX) SetBossPositionX(BossPositionXLocked);
		if (LockBossPositionY) SetBossPositionY(BossPositionYLocked);
		if (LockBossPositionZ) SetBossPositionZ(BossPositionZLocked);
		if (LockBossDirection) SetBossDirection(BossDirectionLocked);
		if (LockBossAnimationIndex) SetBossAnimationIndex(BossAnimationIndexLocked);
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


