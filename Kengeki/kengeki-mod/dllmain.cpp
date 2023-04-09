#include "pch.h"
#include "xNyuLibrary.h"

EXTERN_DLL_EXPORT void __cdecl OnInitDebugMod(DebugSettings _globalSettings, DebugFeatures* _features, void* _logger, void* _drawRectangle, void* _drawText)
{
	//
	// Standard initialization sequence, copy all debugaddress/function if needed, take settings and loggger and draw funtion pointers
	// Feature availability has to be written in the DebugFunction struct
	//

	GlobalSettings = _globalSettings;

	pDebugConsoleOutput = (DebugConsoleOutputT)_logger;
	pDebugDrawRectangle = (DebugDrawRectangleT)_drawRectangle;
	pDebugDrawText = (DebugDrawTextT)_drawText;

	DebugFeatures features;
	features.debugAddress = true;
	features.debugFunction = true;
	features.savefileEditor = true;
	features.supervision = false;

	std::memcpy(_features, &features, sizeof(DebugFeatures));

	if (GlobalSettings.config_version == "v1")
	{
		InitDebugAddressV1();
	}

	if (GlobalSettings.config_version == "v2")
	{
		InitDebugAddressV2();
	}

	GodModeHPAddress.nameFull = "Player.HP";
	GodModeHPAddress.value = Variable();
	GodModeHPAddress.value.value = "300";
	GodModeHPAddress.value.type = "int32";

	GodModeMPAddress.nameFull = "Player.Mana";
	GodModeMPAddress.value = Variable();
	GodModeMPAddress.value.value = "3000";
	GodModeMPAddress.value.type = "int32";
}

EXTERN_DLL_EXPORT void OnFrameDebugMod()
{
	if (!GodmodeInit)
	{
		SetDebugAddressValue(&GodModeHPAddress);
		SetDebugAddressValue(&GodModeMPAddress);
		pDebugDrawRectangle(1800, 800, 20, 20, ColorBlack, 0.9f);
		pDebugDrawText("G", 1810, 82, FontSmallMedium, ColorWhite, 1.0f, "center");
	}

}

EXTERN_DLL_EXPORT void OnExitDebugMod()
{

	//
	// This function get's called when den debug mod get's ejected, clear buffers and stuff here
	//

}


