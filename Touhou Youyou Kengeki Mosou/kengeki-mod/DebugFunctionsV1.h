#pragma once

void InitDebugFunctionsV1()
{
	pDebugConsoleOutput("Using V1 Functions!", false, "red");

	pSharedSetPosition = (SharedSetPositionT)(GetTextSectionBaseAddress(GameBaseAddress, ".text") + 0x3330);
}



