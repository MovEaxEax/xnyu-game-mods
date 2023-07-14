#pragma once

void InitDebugAddressV2()
{
	pDebugConsoleOutput("Using V2 Addresses!", true, "red");

	PlayerObjectBasepointer.baseAddress = (void*)((long long)GameBaseAddress + 0x531CF0);
	PlayerObjectBasepointer.offsets.push_back((void*)0x3C);
	PlayerObjectBasepointer.offsets.push_back((void*)0x0);

	PlayerDisplayStatsBasepointer[0].baseAddress = (void*)((long long)GameBaseAddress + 0x531D0C);
	PlayerDisplayStatsBasepointer[0].offsets.push_back((void*)0xC);
	PlayerDisplayStatsBasepointer[0].offsets.push_back((void*)0x0);

	PlayerDisplayStatsBasepointer[1].baseAddress = (void*)((long long)GameBaseAddress + 0x531D0C);
	PlayerDisplayStatsBasepointer[1].offsets.push_back((void*)0x10);
	PlayerDisplayStatsBasepointer[1].offsets.push_back((void*)0x0);

	PlayerDisplayStatsBasepointer[2].baseAddress = (void*)((long long)GameBaseAddress + 0x531D0C);
	PlayerDisplayStatsBasepointer[2].offsets.push_back((void*)0x14);
	PlayerDisplayStatsBasepointer[2].offsets.push_back((void*)0x0);

	PlayerLevelStatsBasepointer[0].baseAddress = (void*)((long long)GameBaseAddress + 0x531D0C);
	PlayerLevelStatsBasepointer[0].offsets.push_back((void*)0xC);
	PlayerLevelStatsBasepointer[0].offsets.push_back((void*)0x94);
	PlayerLevelStatsBasepointer[0].offsets.push_back((void*)0x0);

	PlayerLevelStatsBasepointer[1].baseAddress = (void*)((long long)GameBaseAddress + 0x531D0C);
	PlayerLevelStatsBasepointer[1].offsets.push_back((void*)0x10);
	PlayerLevelStatsBasepointer[1].offsets.push_back((void*)0x94);
	PlayerLevelStatsBasepointer[1].offsets.push_back((void*)0x0);

	PlayerLevelStatsBasepointer[2].baseAddress = (void*)((long long)GameBaseAddress + 0x531D0C);
	PlayerLevelStatsBasepointer[2].offsets.push_back((void*)0x14);
	PlayerLevelStatsBasepointer[2].offsets.push_back((void*)0x94);
	PlayerLevelStatsBasepointer[2].offsets.push_back((void*)0x0);

	CharacterUsedBasePointer.baseAddress = (void*)((long long)GameBaseAddress + 0x531D0C);
	CharacterUsedBasePointer.offsets.push_back((void*)0x1C);

	CameraObjectBasepointer.baseAddress = (void*)((long long)GameBaseAddress + 0x531CD0);
	CameraObjectBasepointer.offsets.push_back((void*)0xC);
	CameraObjectBasepointer.offsets.push_back((void*)0x0);
	CameraObjectBasepointer.offsets.push_back((void*)0x0);
	CameraObjectBasepointer.offsets.push_back((void*)0x8);
	CameraObjectBasepointer.offsets.push_back((void*)0x0);

	GameGlobalsBasepointer.baseAddress = (void*)((long long)GameBaseAddress + 0x531CF0);
	GameGlobalsBasepointer.offsets.push_back((void*)0x1C);
	GameGlobalsBasepointer.offsets.push_back((void*)0x0);

	BossObjectBasepointer[0].baseAddress = (void*)((long long)GameBaseAddress + 0x531CF0);
	BossObjectBasepointer[0].offsets.push_back((void*)0x8C);
	BossObjectBasepointer[0].offsets.push_back((void*)0x0);
	BossObjectBasepointer[0].offsets.push_back((void*)0x14);
	BossObjectBasepointer[0].offsets.push_back((void*)0x22C);
	BossObjectBasepointer[0].offsets.push_back((void*)0x14);
	BossObjectBasepointer[0].offsets.push_back((void*)0x0);

	BossObjectBasepointer[1].baseAddress = (void*)((long long)GameBaseAddress + 0x531CF0);
	BossObjectBasepointer[1].offsets.push_back((void*)0x8C);
	BossObjectBasepointer[1].offsets.push_back((void*)0x4);
	BossObjectBasepointer[1].offsets.push_back((void*)0x14);
	BossObjectBasepointer[1].offsets.push_back((void*)0x22C);
	BossObjectBasepointer[1].offsets.push_back((void*)0x14);
	BossObjectBasepointer[1].offsets.push_back((void*)0x0);

	BossObjectBasepointer[2].baseAddress = (void*)((long long)GameBaseAddress + 0x531CF0);
	BossObjectBasepointer[2].offsets.push_back((void*)0x8C);
	BossObjectBasepointer[2].offsets.push_back((void*)0x8);
	BossObjectBasepointer[2].offsets.push_back((void*)0x14);
	BossObjectBasepointer[2].offsets.push_back((void*)0x22C);
	BossObjectBasepointer[2].offsets.push_back((void*)0x14);
	BossObjectBasepointer[2].offsets.push_back((void*)0x0);

	IsGamePausedAddress = (void*)((long long)GameBaseAddress + 0x531D14);
}