#pragma once

void InitDebugAddressV1()
{
	pDebugConsoleOutput("Using V1 Addresses!", true, "red");

	PlayerObjectBasepointer.baseAddress = (void*)((long long)GameBaseAddress + 0x3EB5BC);
	PlayerObjectBasepointer.offsets.push_back((void*)0x18);
	PlayerObjectBasepointer.offsets.push_back((void*)0x4);
	PlayerObjectBasepointer.offsets.push_back((void*)0xC80);
	PlayerObjectBasepointer.offsets.push_back((void*)0x0);

	CameraObjectBasepointer.baseAddress = (void*)((long long)GameBaseAddress + 0x3ECE48);
	CameraObjectBasepointer.offsets.push_back((void*)0xC);
	CameraObjectBasepointer.offsets.push_back((void*)0x0);
	CameraObjectBasepointer.offsets.push_back((void*)0x8);
	CameraObjectBasepointer.offsets.push_back((void*)0x0);

	GameGlobalsBasepointer.baseAddress = (void*)((long long)GameBaseAddress + 0x3ECE48);
	GameGlobalsBasepointer.offsets.push_back((void*)0x0);

	BossObjectBasepointer.baseAddress = (void*)((long long)GameBaseAddress + 0x3EB6A0);
	BossObjectBasepointer.offsets.push_back((void*)0x194);
	BossObjectBasepointer.offsets.push_back((void*)0x0);
	BossObjectBasepointer.offsets.push_back((void*)0x8);
	BossObjectBasepointer.offsets.push_back((void*)0x0);

	IsGamePausedAddress = (void*)((long long)GameBaseAddress + 0x3EB428);

}


