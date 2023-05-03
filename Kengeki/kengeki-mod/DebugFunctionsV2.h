#pragma once

void InitDebugFunctionsV2()
{
	pDebugConsoleOutput("Using V2 Functions!", false, "red");

	pSharedSetPosition = (SharedSetPositionT)(GetTextSectionBaseAddress(GameBaseAddress, ".text") + 0x3330);
}
