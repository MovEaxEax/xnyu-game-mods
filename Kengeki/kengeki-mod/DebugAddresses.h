#pragma once

std::vector<DebugAddressParent> debugAdresses;

int int32Buffer = 0;
long long int64Buffer = 0;
float floatBuffer = 0;
double doubleBuffer = 0;
bool boolBuffer = 0;
BYTE byteBuffer = 0;
char* stringBuffer = new char[2048];

EXTERN_DLL_EXPORT void SetDebugAddressValue(DebugAddress* targetAddress)
{
	if (targetAddress->nameFull == "Player.Position-X")
	{
		floatBuffer = GetVariableFloat(targetAddress->value.value);
		if (DbgWriteFloat(PlayerPositionX, &floatBuffer)) SetVariable(&targetAddress->value, floatBuffer);
	}
	if (targetAddress->nameFull == "Player.Position-Y")
	{
		floatBuffer = GetVariableFloat(targetAddress->value.value);
		if (DbgWriteFloat(PlayerPositionY, &floatBuffer)) SetVariable(&targetAddress->value, floatBuffer);
	}
	if (targetAddress->nameFull == "Player.Position-Z")
	{
		floatBuffer = GetVariableFloat(targetAddress->value.value);
		if (DbgWriteFloat(PlayerPositionZ, &floatBuffer)) SetVariable(&targetAddress->value, floatBuffer);
	}
	if (targetAddress->nameFull == "Player.Mana")
	{
		int32Buffer = GetVariableInt32(targetAddress->value.value);
		if (DbgWriteFloat(PlayerMana, &int32Buffer)) SetVariable(&targetAddress->value, int32Buffer);
	}
	if (targetAddress->nameFull == "Player.HP")
	{
		int32Buffer = GetVariableInt32(targetAddress->value.value);
		if (DbgWriteFloat(PlayerHP, &int32Buffer)) SetVariable(&targetAddress->value, int32Buffer);
	}
	if (targetAddress->nameFull == "Boss.HP")
	{
		int32Buffer = GetVariableInt32(targetAddress->value.value);
		if (DbgWriteFloat(BossHP, &int32Buffer)) SetVariable(&targetAddress->value, int32Buffer);
	}
}

EXTERN_DLL_EXPORT void GetDebugAddressValue(DebugAddress* targetAddress)
{
	if (targetAddress->nameFull == "Player.Position-X")
	{
		if (DbgReadFloat(PlayerPositionX, &floatBuffer)) SetVariable(&targetAddress->value, floatBuffer);
		else SetVariable(&targetAddress->value, "none");
	}
	if (targetAddress->nameFull == "Player.Position-Y")
	{
		if (DbgReadFloat(PlayerPositionY, &floatBuffer)) SetVariable(&targetAddress->value, floatBuffer);
		else SetVariable(&targetAddress->value, "none");
	}
	if (targetAddress->nameFull == "Player.Position-Z")
	{
		if (DbgReadFloat(PlayerPositionZ, &floatBuffer)) SetVariable(&targetAddress->value, floatBuffer);
		else SetVariable(&targetAddress->value, "none");
	}
	if (targetAddress->nameFull == "Player.Mana")
	{
		if (DbgReadInt32(PlayerMana, &int32Buffer)) SetVariable(&targetAddress->value, int32Buffer);
		else SetVariable(&targetAddress->value, "none");
	}
	if (targetAddress->nameFull == "Player.HP")
	{
		if (DbgReadInt32(BossHP, &int32Buffer)) SetVariable(&targetAddress->value, int32Buffer);
		else SetVariable(&targetAddress->value, "none");
	}
	if (targetAddress->nameFull == "Boss.HP")
	{
		if (DbgReadInt32(PlayerPositionX, &int32Buffer)) SetVariable(&targetAddress->value, int32Buffer);
		else SetVariable(&targetAddress->value, "none");
	}
}


