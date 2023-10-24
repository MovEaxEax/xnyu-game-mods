#pragma once

std::vector<DebugAddressParent> debugAdresses;

int int32Buffer = 0;
long long int64Buffer = 0;
float floatBuffer = 0;
double doubleBuffer = 0;
bool boolBuffer = 0;
BYTE byteBuffer = 0;
char* stringBuffer = new char[2048];
void* pointerBuffer;

EXTERN_DLL_EXPORT void SetDebugAddressValue(DebugAddress* targetAddress)
{
	std::string name = targetAddress->nameFull;
	std::transform(name.begin(), name.end(), name.begin(), ::tolower);

	if (IsPlayerObjectInstance())
	{
		if (name == "player.position-x") SetPlayerPositionX(GetVariableFloat(&targetAddress->value));
		if (name == "player.position-y") SetPlayerPositionY(GetVariableFloat(&targetAddress->value));
		if (name == "player.position-z") SetPlayerPositionZ(GetVariableFloat(&targetAddress->value));
		if (name == "player.hpcurrent") SetPlayerHPCurrent(GetVariableInt32(&targetAddress->value));
		if (name == "player.hpmax") SetPlayerHPMax(GetVariableInt32(&targetAddress->value));
		if (name == "player.animationindex") SetPlayerAnimationIndex(GetVariableInt32(&targetAddress->value));
		if (name == "player.timeinstage") SetPlayerTimeInStage(GetVariableDouble(&targetAddress->value));
		if (name == "player.skillhealcooldown") SetPlayerHealCooldown(GetVariableInt32(&targetAddress->value));
		if (name == "player.blockcanreset") SetPlayerBlockCanReset(GetVariableInt32(&targetAddress->value));
	}
}

EXTERN_DLL_EXPORT void GetDebugAddressValue(DebugAddress* targetAddress)
{
	std::string name = targetAddress->nameFull;
	std::transform(name.begin(), name.end(), name.begin(), ::tolower);

	SetVariable(&targetAddress->value, "none");
	pDebugConsoleOutput("Till here", false, "green");
	if (IsPlayerObjectInstance())
	{
		pDebugConsoleOutput("Instance?", false, "green");
		if (name == "player.position-x")
		{
			SetVariable(&targetAddress->value, GetPlayerPositionX());
			pDebugConsoleOutput("VALUE: " + std::to_string(GetPlayerPositionX()), false, "green");
		}
		if (name == "player.position-y") SetVariable(&targetAddress->value, GetPlayerPositionY());
		if (name == "player.position-z") SetVariable(&targetAddress->value, GetPlayerPositionZ());
		if (name == "player.hpcurrent") SetVariable(&targetAddress->value, GetPlayerHPCurrent());
		if (name == "player.hpmax") SetVariable(&targetAddress->value, GetPlayerHPMax());
		if (name == "player.animationindex") SetVariable(&targetAddress->value, GetPlayerAnimationIndex());
		if (name == "player.timeinstage") SetVariable(&targetAddress->value, GetPlayerTimeInStage());
		if (name == "player.skillhealcooldown") SetVariable(&targetAddress->value, GetPlayerHealCooldown());
		if (name == "player.blockcanreset") SetVariable(&targetAddress->value, GetPlayerBlockCanReset());
	}
}


