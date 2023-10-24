#pragma once

void InitDebugAddressV110()
{
	pDebugConsoleOutput("Using V1.1.0 Addresses!", true, "red");

	PlayerObjectBasepointer.baseAddress = (void*)((long long)GameBaseAddress + 0x7287D8);
	PlayerObjectBasepointer.offsets.push_back((void*)0x60);
	PlayerObjectBasepointer.offsets.push_back((void*)0x0);
}


