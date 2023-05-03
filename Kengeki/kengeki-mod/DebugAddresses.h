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
	if (IsPlayerObjectInstance())
	{
		if (targetAddress->nameFull == "Player.Position-X") SetPlayerPositionX(GetVariableFloat(&targetAddress->value));
		if (targetAddress->nameFull == "Player.Position-Y") SetPlayerPositionY(GetVariableFloat(&targetAddress->value));
		if (targetAddress->nameFull == "Player.Position-Z") SetPlayerPositionZ(GetVariableFloat(&targetAddress->value));
		if (targetAddress->nameFull == "Player.Direction") SetPlayerDirection(GetVariableFloat(&targetAddress->value));
		if (targetAddress->nameFull == "Player.Energy") SetPlayerEnergy(GetVariableInt32(&targetAddress->value));
		if (targetAddress->nameFull == "Player.HP") SetPlayerHP(GetVariableInt32(&targetAddress->value));
		if (targetAddress->nameFull == "Player.SpellcardBar") SetPlayerSpellcardBar(GetVariableInt32(&targetAddress->value));
		if (targetAddress->nameFull == "Player.SpeedFactor-X") SetPlayerSpeedFactorX(GetVariableFloat(&targetAddress->value));
		if (targetAddress->nameFull == "Player.SpeedFactor-Y") SetPlayerSpeedFactorY(GetVariableFloat(&targetAddress->value));
		if (targetAddress->nameFull == "Player.SpeedFactor-Z") SetPlayerSpeedFactorZ(GetVariableFloat(&targetAddress->value));
		if (targetAddress->nameFull == "Player.AnimationIndex") SetPlayerAnimationIndex(GetVariableInt32(&targetAddress->value));
	}
	if (IsCameraObjectInstance())
	{
		if (targetAddress->nameFull == "Camera.Position-X") SetCameraPositionX(GetVariableFloat(&targetAddress->value));
		if (targetAddress->nameFull == "Camera.Position-Y") SetCameraPositionY(GetVariableFloat(&targetAddress->value));
		if (targetAddress->nameFull == "Camera.Position-Z") SetCameraPositionZ(GetVariableFloat(&targetAddress->value));
		if (targetAddress->nameFull == "Camera.Angle-X") SetCameraAngleX(GetVariableFloat(&targetAddress->value));
		if (targetAddress->nameFull == "Camera.Angle-Y") SetCameraAngleY(GetVariableFloat(&targetAddress->value));
		if (targetAddress->nameFull == "Camera.Angle-Z") SetCameraAngleZ(GetVariableFloat(&targetAddress->value));
		if (targetAddress->nameFull == "Camera.Zoom") SetCameraZoom(GetVariableFloat(&targetAddress->value));
	}
	if (IsGameGlobalsInstance())
	{
		if (targetAddress->nameFull == "Objects.ObjectsCounter") SetAllObjects(GetVariableInt32(&targetAddress->value));
	}
	if (targetAddress->nameFull == "Game.IsGamePaused") DbgWriteBool(IsGamePausedAddress, GetVariableBool(&targetAddress->value));

}

EXTERN_DLL_EXPORT void GetDebugAddressValue(DebugAddress* targetAddress)
{
	SetVariable(&targetAddress->value, "none");
	if (IsPlayerObjectInstance())
	{
		if (targetAddress->nameFull == "Player.Position-X") SetVariable(&targetAddress->value, GetPlayerPositionX());
		if (targetAddress->nameFull == "Player.Position-Y") SetVariable(&targetAddress->value, GetPlayerPositionY());
		if (targetAddress->nameFull == "Player.Position-Z") SetVariable(&targetAddress->value, GetPlayerPositionZ());
		if (targetAddress->nameFull == "Player.Direction") SetVariable(&targetAddress->value, GetPlayerDirection());
		if (targetAddress->nameFull == "Player.Energy") SetVariable(&targetAddress->value, GetPlayerEnergy());
		if (targetAddress->nameFull == "Player.HP") SetVariable(&targetAddress->value, GetPlayerHP());
		if (targetAddress->nameFull == "Player.SpellcardBar") SetVariable(&targetAddress->value, GetPlayerSpellcardBar());
		if (targetAddress->nameFull == "Player.SpeedFactor-X") SetVariable(&targetAddress->value, GetPlayerSpeedFactorX());
		if (targetAddress->nameFull == "Player.SpeedFactor-Y") SetVariable(&targetAddress->value, GetPlayerSpeedFactorY());
		if (targetAddress->nameFull == "Player.SpeedFactor-Z") SetVariable(&targetAddress->value, GetPlayerSpeedFactorZ());
		if (targetAddress->nameFull == "Player.AnimationIndex")
		{
			SetVariable(&targetAddress->value, GetPlayerAnimationIndex());
		}
	}
	if (IsCameraObjectInstance())
	{
		if (targetAddress->nameFull == "Camera.Position-X")
		{
			SetVariable(&targetAddress->value, GetCameraPositionX());
			std::cout << std::dec << GetCameraPositionX() << std::endl;
		}
		if (targetAddress->nameFull == "Camera.Position-Y") SetVariable(&targetAddress->value, GetCameraPositionY());
		if (targetAddress->nameFull == "Camera.Position-Z") SetVariable(&targetAddress->value, GetCameraPositionZ());
		if (targetAddress->nameFull == "Camera.Angle-X") SetVariable(&targetAddress->value, GetCameraAngleX());
		if (targetAddress->nameFull == "Camera.Angle-Y") SetVariable(&targetAddress->value, GetCameraAngleY());
		if (targetAddress->nameFull == "Camera.Angle-Z") SetVariable(&targetAddress->value, GetCameraAngleZ());
		if (targetAddress->nameFull == "Camera.Zoom") SetVariable(&targetAddress->value, GetCameraZoom());
	}
	if (IsGameGlobalsInstance())
	{
		if (targetAddress->nameFull == "Objects.ObjectsCounter") SetVariable(&targetAddress->value, GetAllObjects());
	}
	if (targetAddress->nameFull == "Game.IsGamePaused") SetVariable(&targetAddress->value, DbgReadBool(IsGamePausedAddress));


}


