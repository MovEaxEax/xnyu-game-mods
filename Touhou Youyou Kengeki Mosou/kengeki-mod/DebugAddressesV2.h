#pragma once

void InitDebugAddressV2()
{
	pDebugConsoleOutput("Using V2 Addresses!", true, "red");

	//PlayerObjectBasepointer.baseAddress = (void*)((long long)GameBaseAddress + 0x407FB8);
	PlayerObjectBasepointer.baseAddress = (void*)((long long)GameBaseAddress + 0x406724);
	PlayerObjectBasepointer.offsets.push_back((void*)0x20);
	PlayerObjectBasepointer.offsets.push_back((void*)0x0);
	PlayerObjectBasepointer.offsets.push_back((void*)0xC3C);
	//PlayerObjectBasepointer.offsets.push_back((void*)0x4);
	//PlayerObjectBasepointer.offsets.push_back((void*)0x8);
	PlayerObjectBasepointer.offsets.push_back((void*)0x0);

	CameraObjectBasepointer.baseAddress = (void*)((long long)GameBaseAddress + 0x407FB8);
	CameraObjectBasepointer.offsets.push_back((void*)0xC);
	CameraObjectBasepointer.offsets.push_back((void*)0x0);
	CameraObjectBasepointer.offsets.push_back((void*)0x8);
	CameraObjectBasepointer.offsets.push_back((void*)0x0);

	GameGlobalsBasepointer.baseAddress = (void*)((long long)GameBaseAddress + 0x407FB8);
	GameGlobalsBasepointer.offsets.push_back((void*)0x0);

	IsGamePausedAddress = (void*)((long long)GameBaseAddress + 0x406590);

}