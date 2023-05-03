#pragma once

void InitDebugAddressV2()
{
	pDebugConsoleOutput("Using V2 Addresses!", true, "red");

	PlayerObjectBasepointer.baseAddress = (void*)((long long)GameBaseAddress + 0x3EB5BC);
	PlayerObjectBasepointer.offsets.push_back((void*)0x18);
	PlayerObjectBasepointer.offsets.push_back((void*)0x4);
	PlayerObjectBasepointer.offsets.push_back((void*)0xC80);
}


