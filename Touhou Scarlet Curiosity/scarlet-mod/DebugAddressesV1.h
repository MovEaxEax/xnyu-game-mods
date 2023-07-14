#pragma once

void InitDebugAddressV1()
{
	pDebugConsoleOutput("Using V1 Addresses!", true, "red");

	PlayerObjectBasepointer.baseAddress = (void*)((long long)GameBaseAddress + 0x5A4994);
	PlayerObjectBasepointer.offsets.push_back((void*)0x4C);
	PlayerObjectBasepointer.offsets.push_back((void*)0x0);

	PlayerDisplayStatsBasepointer[0].baseAddress = (void*)((long long)GameBaseAddress + 0x5A49B0);
	PlayerDisplayStatsBasepointer[0].offsets.push_back((void*)0xC);
	PlayerDisplayStatsBasepointer[0].offsets.push_back((void*)0x0);

	PlayerDisplayStatsBasepointer[1].baseAddress = (void*)((long long)GameBaseAddress + 0x5A49B0);
	PlayerDisplayStatsBasepointer[1].offsets.push_back((void*)0x10);
	PlayerDisplayStatsBasepointer[1].offsets.push_back((void*)0x0);

	PlayerDisplayStatsBasepointer[2].baseAddress = (void*)((long long)GameBaseAddress + 0x5A49B0);
	PlayerDisplayStatsBasepointer[2].offsets.push_back((void*)0x14);
	PlayerDisplayStatsBasepointer[2].offsets.push_back((void*)0x0);

	PlayerLevelStatsBasepointer[0].baseAddress = (void*)((long long)GameBaseAddress + 0x5A49B0);
	PlayerLevelStatsBasepointer[0].offsets.push_back((void*)0xC);
	PlayerLevelStatsBasepointer[0].offsets.push_back((void*)0xA0);
	PlayerLevelStatsBasepointer[0].offsets.push_back((void*)0x0);

	PlayerLevelStatsBasepointer[1].baseAddress = (void*)((long long)GameBaseAddress + 0x5A49B0);
	PlayerLevelStatsBasepointer[1].offsets.push_back((void*)0x10);
	PlayerLevelStatsBasepointer[1].offsets.push_back((void*)0xA0);
	PlayerLevelStatsBasepointer[1].offsets.push_back((void*)0x0);

	PlayerLevelStatsBasepointer[2].baseAddress = (void*)((long long)GameBaseAddress + 0x5A49B0);
	PlayerLevelStatsBasepointer[2].offsets.push_back((void*)0x14);
	PlayerLevelStatsBasepointer[2].offsets.push_back((void*)0xA0);
	PlayerLevelStatsBasepointer[2].offsets.push_back((void*)0x0);

	CharacterUsedBasePointer.baseAddress = (void*)((long long)GameBaseAddress + 0x5A49B0);
	CharacterUsedBasePointer.offsets.push_back((void*)0x1C);

	CameraObjectBasepointer.baseAddress = (void*)((long long)GameBaseAddress + 0x5A4978);
	CameraObjectBasepointer.offsets.push_back((void*)0xC);
	CameraObjectBasepointer.offsets.push_back((void*)0x0);
	CameraObjectBasepointer.offsets.push_back((void*)0x0);
	CameraObjectBasepointer.offsets.push_back((void*)0x8);
	CameraObjectBasepointer.offsets.push_back((void*)0x0);

	GameGlobalsBasepointer.baseAddress = (void*)((long long)GameBaseAddress + 0x5A4994);
	GameGlobalsBasepointer.offsets.push_back((void*)0x2C);
	GameGlobalsBasepointer.offsets.push_back((void*)0x0);

	BossObjectBasepointer[0].baseAddress = (void*)((long long)GameBaseAddress + 0x5A4994);
	BossObjectBasepointer[0].offsets.push_back((void*)0xA0);
	BossObjectBasepointer[0].offsets.push_back((void*)0x0);
	BossObjectBasepointer[0].offsets.push_back((void*)0x10);
	BossObjectBasepointer[0].offsets.push_back((void*)0x238);
	BossObjectBasepointer[0].offsets.push_back((void*)0x10);
	BossObjectBasepointer[0].offsets.push_back((void*)0x0);

	BossObjectBasepointer[1].baseAddress = (void*)((long long)GameBaseAddress + 0x5A4994);
	BossObjectBasepointer[1].offsets.push_back((void*)0xA0);
	BossObjectBasepointer[1].offsets.push_back((void*)0x4);
	BossObjectBasepointer[1].offsets.push_back((void*)0x10);
	BossObjectBasepointer[1].offsets.push_back((void*)0x238);
	BossObjectBasepointer[1].offsets.push_back((void*)0x10);
	BossObjectBasepointer[1].offsets.push_back((void*)0x0);

	BossObjectBasepointer[2].baseAddress = (void*)((long long)GameBaseAddress + 0x5A4994);
	BossObjectBasepointer[2].offsets.push_back((void*)0xA0);
	BossObjectBasepointer[2].offsets.push_back((void*)0x8);
	BossObjectBasepointer[2].offsets.push_back((void*)0x10);
	BossObjectBasepointer[2].offsets.push_back((void*)0x238);
	BossObjectBasepointer[2].offsets.push_back((void*)0x10);
	BossObjectBasepointer[2].offsets.push_back((void*)0x0);

	IsGamePausedAddress = (void*)((long long)GameBaseAddress + 0x5A4DB8);

}


