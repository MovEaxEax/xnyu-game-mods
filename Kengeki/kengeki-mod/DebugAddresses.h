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
		if (name == "player.direction") SetPlayerDirection(GetVariableFloat(&targetAddress->value));
		if (name == "player.energy") SetPlayerEnergy(GetVariableInt32(&targetAddress->value));
		if (name == "player.hp") SetPlayerHP(GetVariableInt32(&targetAddress->value));
		if (name == "player.spellcardbar") SetPlayerSpellcardBar(GetVariableInt32(&targetAddress->value));
		if (name == "player.speedfactor-x") SetPlayerSpeedFactorX(GetVariableFloat(&targetAddress->value));
		if (name == "player.speedfactor-y") SetPlayerSpeedFactorY(GetVariableFloat(&targetAddress->value));
		if (name == "player.speedfactor-z") SetPlayerSpeedFactorZ(GetVariableFloat(&targetAddress->value));
		if (name == "player.animationindex") SetPlayerAnimationIndex(GetVariableInt32(&targetAddress->value));
	}
	if (IsCameraObjectInstance())
	{
		if (name == "camera.position-x") SetCameraPositionX(GetVariableFloat(&targetAddress->value));
		if (name == "camera.position-y") SetCameraPositionY(GetVariableFloat(&targetAddress->value));
		if (name == "camera.position-z") SetCameraPositionZ(GetVariableFloat(&targetAddress->value));
		if (name == "camera.angle-x") SetCameraAngleX(GetVariableFloat(&targetAddress->value));
		if (name == "camera.angle-y") SetCameraAngleY(GetVariableFloat(&targetAddress->value));
		if (name == "camera.angle-z") SetCameraAngleZ(GetVariableFloat(&targetAddress->value));
		if (name == "camera.zoom") SetCameraZoom(GetVariableFloat(&targetAddress->value));
	}
	if (IsGameGlobalsInstance())
	{
		if (name == "objects.objectscounter") SetAllObjects(GetVariableInt32(&targetAddress->value));
	}
	if (name == "game.isgamepaused") DbgWriteBool(IsGamePausedAddress, GetVariableBool(&targetAddress->value));

}

EXTERN_DLL_EXPORT void GetDebugAddressValue(DebugAddress* targetAddress)
{
	std::string name = targetAddress->nameFull;
	std::transform(name.begin(), name.end(), name.begin(), ::tolower);

	SetVariable(&targetAddress->value, "none");
	if (IsPlayerObjectInstance())
	{
		if (name == "player.position-x") SetVariable(&targetAddress->value, GetPlayerPositionX());
		if (name == "player.position-y") SetVariable(&targetAddress->value, GetPlayerPositionY());
		if (name == "player.position-z") SetVariable(&targetAddress->value, GetPlayerPositionZ());
		if (name == "player.direction") SetVariable(&targetAddress->value, GetPlayerDirection());
		if (name == "player.energy") SetVariable(&targetAddress->value, GetPlayerEnergy());
		if (name == "player.hp") SetVariable(&targetAddress->value, GetPlayerHP());
		if (name == "player.spellcardbar") SetVariable(&targetAddress->value, GetPlayerSpellcardBar());
		if (name == "player.speedfactor-x") SetVariable(&targetAddress->value, GetPlayerSpeedFactorX());
		if (name == "player.speedfactor-y") SetVariable(&targetAddress->value, GetPlayerSpeedFactorY());
		if (name == "player.speedfactor-z") SetVariable(&targetAddress->value, GetPlayerSpeedFactorZ());
		if (name == "player.animationindex") SetVariable(&targetAddress->value, GetPlayerAnimationIndex());
	}
	if (IsCameraObjectInstance())
	{
		if (name == "camera.position-x") SetVariable(&targetAddress->value, GetCameraPositionX());
		if (name == "camera.position-y") SetVariable(&targetAddress->value, GetCameraPositionY());
		if (name == "camera.position-z") SetVariable(&targetAddress->value, GetCameraPositionZ());
		if (name == "camera.angle-x") SetVariable(&targetAddress->value, GetCameraAngleX());
		if (name == "camera.angle-y") SetVariable(&targetAddress->value, GetCameraAngleY());
		if (name == "camera.angle-z") SetVariable(&targetAddress->value, GetCameraAngleZ());
		if (name == "camera.zoom") SetVariable(&targetAddress->value, GetCameraZoom());
	}
	if (IsGameGlobalsInstance())
	{
		if (name == "objects.objectscounter") SetVariable(&targetAddress->value, GetAllObjects());
	}
	if (name == "game.isgamepaused") SetVariable(&targetAddress->value, DbgReadBool(IsGamePausedAddress));


}


