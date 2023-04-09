#pragma once

void InitDebugAddressV1()
{
	HMODULE KengekiBaseAddress = GetModuleHandle(NULL);

	PlayerPositionX.baseAddress = (void*)((long long)KengekiBaseAddress + 0x3EB5BC);
	PlayerPositionX.offsets.push_back((void*)0x18);
	PlayerPositionX.offsets.push_back((void*)0x4);
	PlayerPositionX.offsets.push_back((void*)0xC80);
	PlayerPositionX.offsets.push_back((void*)0x3C);

	PlayerPositionY.baseAddress = (void*)((long long)KengekiBaseAddress + 0x3EB5BC);
	PlayerPositionY.offsets.push_back((void*)0x18);
	PlayerPositionY.offsets.push_back((void*)0x4);
	PlayerPositionY.offsets.push_back((void*)0xC80);
	PlayerPositionY.offsets.push_back((void*)0x44);

	PlayerPositionZ.baseAddress = (void*)((long long)KengekiBaseAddress + 0x3EB5BC);
	PlayerPositionZ.offsets.push_back((void*)0x18);
	PlayerPositionZ.offsets.push_back((void*)0x4);
	PlayerPositionZ.offsets.push_back((void*)0xC80);
	PlayerPositionZ.offsets.push_back((void*)0x40);

	PlayerHP.baseAddress = (void*)((long long)KengekiBaseAddress + 0x3EB5BC);
	PlayerHP.offsets.push_back((void*)0x18);
	PlayerHP.offsets.push_back((void*)0x4);
	PlayerHP.offsets.push_back((void*)0xC80);
	PlayerHP.offsets.push_back((void*)0x2A8);

	PlayerMana.baseAddress = (void*)((long long)KengekiBaseAddress + 0x3EB5BC);
	PlayerMana.offsets.push_back((void*)0x18);
	PlayerMana.offsets.push_back((void*)0x4);
	PlayerMana.offsets.push_back((void*)0xC80);
	PlayerMana.offsets.push_back((void*)0x400);

	BossHP.baseAddress = (void*)((long long)KengekiBaseAddress + 0x3EB6A0);
	BossHP.offsets.push_back((void*)0x2A8);
	BossHP.offsets.push_back((void*)0x8);
	BossHP.offsets.push_back((void*)0x0);
	BossHP.offsets.push_back((void*)0x194);

}




