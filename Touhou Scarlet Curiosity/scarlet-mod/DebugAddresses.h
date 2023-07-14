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
		if (name == "player.energycurrent") SetPlayerEnergyCurrent(GetVariableInt32(&targetAddress->value));
		if (name == "player.energymax") SetPlayerEnergyMax(GetVariableInt32(&targetAddress->value));
		if (name == "player.hpcurrent") SetPlayerHPCurrent(GetVariableInt32(&targetAddress->value));
		if (name == "player.hpmax") SetPlayerHPMax(GetVariableInt32(&targetAddress->value));
		if (name == "player.spellcardbar") SetPlayerSpellcardBar(GetVariableInt32(&targetAddress->value));
		if (name == "player.speedfactor-x") SetPlayerSpeedFactorX(GetVariableFloat(&targetAddress->value));
		if (name == "player.speedfactor-y") SetPlayerSpeedFactorY(GetVariableFloat(&targetAddress->value));
		if (name == "player.speedfactor-z") SetPlayerSpeedFactorZ(GetVariableFloat(&targetAddress->value));
		if (name == "player.animationindex") SetPlayerAnimationIndex(GetVariableInt32(&targetAddress->value));
		if (name == "player.character")
		{
			std::string characterName = GetVariableString(&targetAddress->value);
			std::transform(characterName.begin(), characterName.end(), characterName.begin(), ::tolower);
			int target = -1;
			if (characterName == "remilia") target = 0;
			else if (characterName == "sakuya") target = 1;
			else if (characterName == "flann") target = 2;
			if (target > -1)
			{
				DbgWriteInt32(CharacterUsedBasePointer, target);
				CharacterUsedCurrent = target;
			}
		}
	}
	if (CharacterUsedCurrent > -1)
	{
		if (IsPlayerLevelStatsInstance(CharacterUsedCurrent))
		{
			if (name == "stats.levelindex") SetPlayerLevelStatsLevelIndex(GetVariableFloat(&targetAddress->value), CharacterUsedCurrent);
			if (name == "stats.experiencemax") SetPlayerLevelStatsExperienceMax(GetVariableFloat(&targetAddress->value), CharacterUsedCurrent);
			if (name == "stats.basehpmax") SetPlayerLevelStatsBaseHPMax(GetVariableFloat(&targetAddress->value), CharacterUsedCurrent);
			if (name == "stats.baseenergymax") SetPlayerLevelStatsBaseEnergyMax(GetVariableFloat(&targetAddress->value), CharacterUsedCurrent);
			if (name == "stats.baseenergyrechargespeed") SetPlayerLevelStatsBaseEnergyRechargeSpeed(GetVariableFloat(&targetAddress->value), CharacterUsedCurrent);
			if (name == "stats.baseattackdamage") SetPlayerLevelStatsBaseAttackDamage(GetVariableFloat(&targetAddress->value), CharacterUsedCurrent);
		}
		if (IsPlayerDisplayStatsInstance(CharacterUsedCurrent))
		{
			if (name == "stats.experiencecurrent") SetPlayerDisplayStatsExperienceCurrent(GetVariableInt32(&targetAddress->value), CharacterUsedCurrent);
			if (name == "stats.money") SetPlayerDisplayStatsMoney(GetVariableInt32(&targetAddress->value), CharacterUsedCurrent);
		}
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
	for (int i = 0; i < 3; i++)
	{
		if (IsBossObjectInstance(i))
		{
			std::string bossIndex = std::to_string(i + 1);
			if (name == "boss" + bossIndex + ".position-x") SetBossPositionX(GetVariableFloat(&targetAddress->value), i);
			if (name == "boss" + bossIndex + ".position-y") SetBossPositionY(GetVariableFloat(&targetAddress->value), i);
			if (name == "boss" + bossIndex + ".position-z") SetBossPositionZ(GetVariableFloat(&targetAddress->value), i);
			if (name == "boss" + bossIndex + ".direction") SetBossDirection(GetVariableFloat(&targetAddress->value), i);
			if (name == "boss" + bossIndex + ".hp") SetBossHP(GetVariableInt32(&targetAddress->value), i);
			if (name == "boss" + bossIndex + ".animationindex") SetBossAnimationIndex(GetVariableInt32(&targetAddress->value), i);
		}
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
		if (name == "player.energycurrent") SetVariable(&targetAddress->value, GetPlayerEnergyCurrent());
		if (name == "player.energymax") SetVariable(&targetAddress->value, GetPlayerEnergyMax());
		if (name == "player.hpcurrent") SetVariable(&targetAddress->value, GetPlayerHPCurrent());
		if (name == "player.hpmax") SetVariable(&targetAddress->value, GetPlayerHPMax());
		if (name == "player.spellcardbar") SetVariable(&targetAddress->value, GetPlayerSpellcardBar());
		if (name == "player.speedfactor-x") SetVariable(&targetAddress->value, GetPlayerSpeedFactorX());
		if (name == "player.speedfactor-y") SetVariable(&targetAddress->value, GetPlayerSpeedFactorY());
		if (name == "player.speedfactor-z") SetVariable(&targetAddress->value, GetPlayerSpeedFactorZ());
		if (name == "player.animationindex") SetVariable(&targetAddress->value, GetPlayerAnimationIndex());
	}
	if (CharacterUsedCurrent > -1)
	{
		if (name == "player.character")
		{
			std::string target = "none";
			if (CharacterUsedCurrent == 0) target = "Remilia";
			else if (CharacterUsedCurrent == 1) target = "Sakuya";
			else if (CharacterUsedCurrent == 2) target = "Flann";
			SetVariable(&targetAddress->value, target);
		}
		if (IsPlayerLevelStatsInstance(CharacterUsedCurrent))
		{
			if (name == "stats.levelindex") SetVariable(&targetAddress->value, GetPlayerLevelStatsLevelIndex(CharacterUsedCurrent));
			if (name == "stats.experiencemax") SetVariable(&targetAddress->value, GetPlayerLevelStatsExperienceMax(CharacterUsedCurrent));
			if (name == "stats.basehpmax") SetVariable(&targetAddress->value, GetPlayerLevelStatsBaseHPMax(CharacterUsedCurrent));
			if (name == "stats.baseenergymax") SetVariable(&targetAddress->value, GetPlayerLevelStatsBaseEnergyMax(CharacterUsedCurrent));
			if (name == "stats.baseenergyrechargespeed") SetVariable(&targetAddress->value, GetPlayerLevelStatsBaseEnergyRechargeSpeed(CharacterUsedCurrent));
			if (name == "stats.baseattackdamage") SetVariable(&targetAddress->value, GetPlayerLevelStatsBaseAttackDamage(CharacterUsedCurrent));
		}
		if (IsPlayerDisplayStatsInstance(CharacterUsedCurrent))
		{
			if (name == "stats.experiencecurrent") SetVariable(&targetAddress->value, GetPlayerDisplayStatsExperienceCurrent(CharacterUsedCurrent));
			if (name == "stats.money") SetVariable(&targetAddress->value, GetPlayerDisplayStatsMoney(CharacterUsedCurrent));
		}
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
	for (int i = 0; i < 3; i++)
	{
		if (IsBossObjectInstance(i))
		{
			std::string bossIndex = std::to_string(i + 1);
			if (name == "boss" + bossIndex + ".position-x") SetVariable(&targetAddress->value, GetBossPositionX(i));
			if (name == "boss" + bossIndex + ".position-y") SetVariable(&targetAddress->value, GetBossPositionY(i));
			if (name == "boss" + bossIndex + ".position-z") SetVariable(&targetAddress->value, GetBossPositionZ(i));
			if (name == "boss" + bossIndex + ".direction") SetVariable(&targetAddress->value, GetBossDirection(i));
			if (name == "boss" + bossIndex + ".hp") SetVariable(&targetAddress->value, GetBossHP(i));
			if (name == "boss" + bossIndex + ".animationindex") SetVariable(&targetAddress->value, GetBossAnimationIndex(i));
		}
	}
	if (name == "game.isgamepaused") SetVariable(&targetAddress->value, DbgReadBool(IsGamePausedAddress));


}


