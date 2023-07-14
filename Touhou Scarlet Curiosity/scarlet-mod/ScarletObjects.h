#pragma once

int CharacterUsedCurrent = -1;



PlayerObjectV1* playerObjectV1;
PlayerObjectV2* playerObjectV2;

void SetPlayerObjectInstance(void* pointer, bool success)
{
	if (!success)
	{
		if (GlobalSettings.config_version == "v1.0") playerObjectV1 = (PlayerObjectV1*)0x00;
		else playerObjectV2 = (PlayerObjectV2*)0x00;
	}
	else
	{
		if (GlobalSettings.config_version == "v1.0") playerObjectV1 = (PlayerObjectV1*)pointer;
		else playerObjectV2 = (PlayerObjectV2*)pointer;
	}
}

bool IsPlayerObjectInstance()
{
	if (GlobalSettings.config_version == "v1.0") return playerObjectV1 != 0x00;
	else return playerObjectV2 != 0x00;
}

float GetPlayerPositionX()
{
	if (GlobalSettings.config_version == "v1.0") return playerObjectV1->Position.x;
	else return playerObjectV2->Position.x;
}

void SetPlayerPositionX(float value)
{
	if (GlobalSettings.config_version == "v1.0") playerObjectV1->Position.x = value;
	else playerObjectV2->Position.x = value;
}

float GetPlayerPositionY()
{
	if (GlobalSettings.config_version == "v1.0") return playerObjectV1->Position.y;
	else return playerObjectV2->Position.y;
}

void SetPlayerPositionY(float value)
{
	if (GlobalSettings.config_version == "v1.0") playerObjectV1->Position.y = value;
	else playerObjectV2->Position.y = value;
}

float GetPlayerPositionZ()
{
	if (GlobalSettings.config_version == "v1.0") return playerObjectV1->Position.z;
	else return playerObjectV2->Position.z;
}

void SetPlayerPositionZ(float value)
{
	if (GlobalSettings.config_version == "v1.0") playerObjectV1->Position.z = value;
	else playerObjectV2->Position.z = value;
}

float GetPlayerDirection()
{
	if (GlobalSettings.config_version == "v1.0") return atan2(playerObjectV1->Rotation.x, playerObjectV1->Rotation.y) * 360 / PI;
	else return atan2(playerObjectV2->Rotation.x, playerObjectV2->Rotation.y) * 360 / PI;
}

void SetPlayerDirection(float value)
{
	float angleRadians = value * PI / 360;
	float angleFactor1 = sin(angleRadians);
	float angleFactor2 = cos(angleRadians);
	if (GlobalSettings.config_version == "v1.0")
	{
		playerObjectV1->Rotation.x = angleFactor1;
		playerObjectV1->Rotation.y = angleFactor2;
	}
	else
	{
		playerObjectV2->Rotation.x = angleFactor1;
		playerObjectV2->Rotation.y = angleFactor2;
	}
}

int GetPlayerEnergyMax()
{
	if (GlobalSettings.config_version == "v1.0") return playerObjectV1->EnergyMax;
	else return playerObjectV2->EnergyMax;
}

void SetPlayerEnergyMax(int value)
{
	if (GlobalSettings.config_version == "v1.0") playerObjectV1->EnergyMax = value;
	else playerObjectV2->EnergyMax = value;
}

int GetPlayerEnergyCurrent()
{
	if (GlobalSettings.config_version == "v1.0") return playerObjectV1->EnergyCurrent;
	else return playerObjectV2->EnergyCurrent;
}

void SetPlayerEnergyCurrent(int value)
{
	if (GlobalSettings.config_version == "v1.0") playerObjectV1->EnergyCurrent = value;
	else playerObjectV2->EnergyCurrent = value;
}

int GetPlayerHPCurrent()
{
	if (GlobalSettings.config_version == "v1.0") return playerObjectV1->HPCurrent;
	else return playerObjectV2->HPCurrent;
}

void SetPlayerHPCurrent(int value)
{
	if (GlobalSettings.config_version == "v1.0") playerObjectV1->HPCurrent = value;
	else playerObjectV2->HPCurrent = value;
}

int GetPlayerHPMax()
{
	if (GlobalSettings.config_version == "v1.0") return playerObjectV1->HPMax;
	else return playerObjectV2->HPMax;
}

void SetPlayerHPMax(int value)
{
	if (GlobalSettings.config_version == "v1.0") playerObjectV1->HPMax = value;
	else playerObjectV2->HPMax = value;
}

int GetPlayerSpellcardBar()
{
	if (GlobalSettings.config_version == "v1.0") return playerObjectV1->SpellcardBar;
	else return playerObjectV2->SpellcardBar;
}

void SetPlayerSpellcardBar(int value)
{
	if (GlobalSettings.config_version == "v1.0") playerObjectV1->SpellcardBar = value;
	else playerObjectV2->SpellcardBar = value;
}

// Speedfactors
float GetPlayerSpeedFactorX()
{
	if (GlobalSettings.config_version == "v1.0") return playerObjectV1->SpeedVelocity.x;
	else return playerObjectV2->SpeedVelocity.x;
}

void SetPlayerSpeedFactorX(float value)
{
	if (GlobalSettings.config_version == "v1.0") playerObjectV1->SpeedVelocity.x = value;
	else playerObjectV2->SpeedVelocity.x = value;
}

float GetPlayerSpeedFactorY()
{
	if (GlobalSettings.config_version == "v1.0") return playerObjectV1->SpeedVelocity.y;
	else return playerObjectV2->SpeedVelocity.y;
}

void SetPlayerSpeedFactorY(float value)
{
	if (GlobalSettings.config_version == "v1.0") playerObjectV1->SpeedVelocity.y = value;
	else playerObjectV2->SpeedVelocity.y = value;
}

float GetPlayerSpeedFactorZ()
{
	if (GlobalSettings.config_version == "v1.0") return playerObjectV1->SpeedVelocity.z;
	else return playerObjectV2->SpeedVelocity.z;
}

void SetPlayerSpeedFactorZ(float value)
{
	if (GlobalSettings.config_version == "v1.0") playerObjectV1->SpeedVelocity.z = value;
	else playerObjectV2->SpeedVelocity.z = value;
}

// Animations
int GetPlayerAnimationIndex()
{
	if (GlobalSettings.config_version == "v1.0") return playerObjectV1->AnimationIndex;
	else return playerObjectV2->AnimationIndex;
}

void SetPlayerAnimationIndex(int value)
{
	if (GlobalSettings.config_version == "v1.0") playerObjectV1->AnimationIndex = value;
	else playerObjectV2->AnimationIndex = value;
}



CameraObjectV1* cameraObjectV1;
CameraObjectV2* cameraObjectV2;

void SetCameraObjectInstance(void* pointer, bool success)
{
	if (!success)
	{
		if (GlobalSettings.config_version == "v1.0") cameraObjectV1 = (CameraObjectV1*)0x00;
		else cameraObjectV2 = (CameraObjectV2*)0x00;
	}
	else
	{
		if (GlobalSettings.config_version == "v1.0") cameraObjectV1 = (CameraObjectV1*)pointer;
		else cameraObjectV2 = (CameraObjectV2*)pointer;
	}
}

bool IsCameraObjectInstance()
{
	if (GlobalSettings.config_version == "v1.0") return cameraObjectV1 != 0x00;
	else return cameraObjectV2 != 0x00;
}

// Camera positions
Vector3 GetCameraPosition()
{
	if (GlobalSettings.config_version == "v1.0") return cameraObjectV1->Position;
	else return cameraObjectV2->Position;
}

void SetCameraPosition(Vector3 value)
{
	if (GlobalSettings.config_version == "v1.0") cameraObjectV1->Position = value;
	else cameraObjectV2->Position = value;
}

float GetCameraPositionX()
{
	if (GlobalSettings.config_version == "v1.0") return cameraObjectV1->Position.x;
	else return cameraObjectV2->Position.x;
}

void SetCameraPositionX(float value)
{
	if (GlobalSettings.config_version == "v1.0") cameraObjectV1->Position.x = value;
	else cameraObjectV2->Position.x = value;
}

float GetCameraPositionY()
{
	if (GlobalSettings.config_version == "v1.0") return cameraObjectV1->Position.y;
	else return cameraObjectV2->Position.y;
}

void SetCameraPositionY(float value)
{
	if (GlobalSettings.config_version == "v1.0") cameraObjectV1->Position.y = value;
	else cameraObjectV2->Position.y = value;
}

float GetCameraPositionZ()
{
	if (GlobalSettings.config_version == "v1.0") return cameraObjectV1->Position.z;
	else return cameraObjectV2->Position.z;
}

void SetCameraPositionZ(float value)
{
	if (GlobalSettings.config_version == "v1.0") cameraObjectV1->Position.z = value;
	else cameraObjectV2->Position.z = value;
}

Vector3 GetCameraRotation()
{
	if (GlobalSettings.config_version == "v1.0") return cameraObjectV1->Rotation;
	else return cameraObjectV2->Rotation;
}

void SetCameraRotation(Vector3 value)
{
	if (GlobalSettings.config_version == "v1.0") cameraObjectV1->Rotation = value;
	else cameraObjectV2->Rotation = value;
}

float GetCameraAngleX()
{
	if (GlobalSettings.config_version == "v1.0") return cameraObjectV1->Rotation.x;
	else return cameraObjectV2->Rotation.x;
}

void SetCameraAngleX(float value)
{
	if (GlobalSettings.config_version == "v1.0") cameraObjectV1->Rotation.x = value;
	else cameraObjectV2->Rotation.x = value;
}

float GetCameraAngleY()
{
	if (GlobalSettings.config_version == "v1.0") return cameraObjectV1->Rotation.y;
	else return cameraObjectV2->Rotation.y;
}

void SetCameraAngleY(float value)
{
	if (GlobalSettings.config_version == "v1.0") cameraObjectV1->Rotation.y = value;
	else cameraObjectV2->Rotation.y = value;
}

float GetCameraAngleZ()
{
	if (GlobalSettings.config_version == "v1.0") return cameraObjectV1->Rotation.z;
	else return cameraObjectV2->Rotation.z;
}

void SetCameraAngleZ(float value)
{
	if (GlobalSettings.config_version == "v1.0") cameraObjectV1->Rotation.z = value;
	else cameraObjectV2->Rotation.z = value;
}

float GetCameraZoom()
{
	//if (GlobalSettings.config_version == "v1.0") return cameraObjectV1->Zoom;
	//else return cameraObjectV2->Zoom;
	return 0;
}

void SetCameraZoom(float value)
{
	//if (GlobalSettings.config_version == "v1.0") cameraObjectV1->Zoom = value;
	//else cameraObjectV2->Zoom = value;
}



GameGlobalsV1* gameGlobalsV1;
GameGlobalsV2* gameGlobalsV2;

void SetGameGlobalsInstance(void* pointer, bool success)
{
	if (!success)
	{
		if (GlobalSettings.config_version == "v1.0") gameGlobalsV1 = (GameGlobalsV1*)0x00;
		else gameGlobalsV2 = (GameGlobalsV2*)0x00;
	}
	else
	{
		if (GlobalSettings.config_version == "v1.0") gameGlobalsV1 = (GameGlobalsV1*)pointer;
		else gameGlobalsV2 = (GameGlobalsV2*)pointer;
	}
}

bool IsGameGlobalsInstance()
{
	if (GlobalSettings.config_version == "v1.0") return gameGlobalsV1 != 0x00;
	else return gameGlobalsV2 != 0x00;
}

int GetAllObjects()
{
	if (GlobalSettings.config_version == "v1.0") return gameGlobalsV1->AllObjects;
	else return gameGlobalsV2->AllObjects;
}

void SetAllObjects(int value)
{
	if (GlobalSettings.config_version == "v1.0") gameGlobalsV1->AllObjects = value;
	else gameGlobalsV2->AllObjects = value;
}



BossObjectV1* bossObjectV1[3];
BossObjectV2* bossObjectV2[3];

void SetBossObjectInstance(void* pointer, bool success, int index)
{
	if (!success)
	{
		if (GlobalSettings.config_version == "v1.0") bossObjectV1[index] = (BossObjectV1*)0x00;
		else bossObjectV2[index] = (BossObjectV2*)0x00;
	}
	else
	{
		if (GlobalSettings.config_version == "v1.0") bossObjectV1[index] = (BossObjectV1*)pointer;
		else bossObjectV2[index] = (BossObjectV2*)pointer;
	}
}

bool IsBossObjectInstance(int index)
{
	if (GlobalSettings.config_version == "v1.0") return bossObjectV1[index] != 0x00;
	else return bossObjectV2[index] != 0x00;
}

// Boss positions
float GetBossPositionX(int index)
{
	if (GlobalSettings.config_version == "v1.0") return bossObjectV1[index]->Position.x;
	else return bossObjectV2[index]->Position.x;
}

void SetBossPositionX(float value, int index)
{
	if (GlobalSettings.config_version == "v1.0") bossObjectV1[index]->Position.x = value;
	else bossObjectV2[index]->Position.x = value;
}

float GetBossPositionY(int index)
{
	if (GlobalSettings.config_version == "v1.0") return bossObjectV1[index]->Position.y;
	else return bossObjectV2[index]->Position.y;
}

void SetBossPositionY(float value, int index)
{
	if (GlobalSettings.config_version == "v1.0") bossObjectV1[index]->Position.y = value;
	else bossObjectV2[index]->Position.y = value;
}

float GetBossPositionZ(int index)
{
	if (GlobalSettings.config_version == "v1.0") return bossObjectV1[index]->Position.z;
	else return bossObjectV2[index]->Position.z;
}

void SetBossPositionZ(float value, int index)
{
	if (GlobalSettings.config_version == "v1.0") bossObjectV1[index]->Position.z = value;
	else bossObjectV2[index]->Position.z = value;
}

float GetBossDirection(int index)
{
	if (GlobalSettings.config_version == "v1.0") return atan2(bossObjectV1[index]->Rotation.x, bossObjectV1[index]->Rotation.y) * 360 / PI;
	else return atan2(bossObjectV2[index]->Rotation.x, bossObjectV2[index]->Rotation.y) * 360 / PI;
}

void SetBossDirection(float value, int index)
{
	float angleRadians = value * PI / 360;
	float angleFactor1 = sin(angleRadians);
	float angleFactor2 = cos(angleRadians);
	if (GlobalSettings.config_version == "v1.0")
	{
		bossObjectV1[index]->Rotation.x = angleFactor1;
		bossObjectV1[index]->Rotation.y = angleFactor2;
	}
	else
	{
		bossObjectV2[index]->Rotation.x = angleFactor1;
		bossObjectV2[index]->Rotation.y = angleFactor2;
	}
}

// HP
int GetBossHP(int index)
{
	if (GlobalSettings.config_version == "v1.0") return bossObjectV1[index]->HPCurrent;
	else return bossObjectV2[index]->HPCurrent;
}

void SetBossHP(int value, int index)
{
	if (GlobalSettings.config_version == "v1.0") bossObjectV1[index]->HPCurrent = value;
	else bossObjectV2[index]->HPCurrent = value;
}

// Animations
int GetBossAnimationIndex(int index)
{
	if (GlobalSettings.config_version == "v1.0") return bossObjectV1[index]->AnimationIndex;
	else return bossObjectV2[index]->AnimationIndex;
}

void SetBossAnimationIndex(int value, int index)
{
	if (GlobalSettings.config_version == "v1.0") bossObjectV1[index]->AnimationIndex = value;
	else bossObjectV2[index]->AnimationIndex = value;
}



PlayerLevelStatsV1* playerLevelStatsV1[3];
PlayerLevelStatsV2* playerLevelStatsV2[3];

void SetPlayerLevelStatsInstance(void* pointer, bool success, int index)
{
	if (index < 0) return;
	if (!success)
	{
		if (GlobalSettings.config_version == "v1.0") playerLevelStatsV1[index] = (PlayerLevelStatsV1*)0x00;
		else playerLevelStatsV2[index] = (PlayerLevelStatsV2*)0x00;
	}
	else
	{
		if (GlobalSettings.config_version == "v1.0") playerLevelStatsV1[index] = (PlayerLevelStatsV1*)pointer;
		else playerLevelStatsV2[index] = (PlayerLevelStatsV2*)pointer;
	}
}

bool IsPlayerLevelStatsInstance(int index)
{
	if (index < 0) return false;
	if (GlobalSettings.config_version == "v1.0") return playerLevelStatsV1[index] != 0x00;
	else return playerLevelStatsV2[index] != 0x00;
}

int GetPlayerLevelStatsLevelIndex(int index)
{
	if (GlobalSettings.config_version == "v1.0") return playerLevelStatsV1[index]->LevelIndex;
	else return playerLevelStatsV2[index]->LevelIndex;
}

void SetPlayerLevelStatsLevelIndex(int value, int index)
{
	if (GlobalSettings.config_version == "v1.0") playerLevelStatsV1[index]->LevelIndex = value;
	else playerLevelStatsV2[index]->LevelIndex = value;
}

int GetPlayerLevelStatsExperienceMax(int index)
{
	if (GlobalSettings.config_version == "v1.0") return playerLevelStatsV1[index]->MaxEXP;
	else return playerLevelStatsV2[index]->MaxEXP;
}

void SetPlayerLevelStatsExperienceMax(int value, int index)
{
	if (GlobalSettings.config_version == "v1.0") playerLevelStatsV1[index]->MaxEXP = value;
	else playerLevelStatsV2[index]->MaxEXP = value;
}

int GetPlayerLevelStatsBaseHPMax(int index)
{
	if (GlobalSettings.config_version == "v1.0") return playerLevelStatsV1[index]->MaxHP;
	else return playerLevelStatsV2[index]->MaxHP;
}

void SetPlayerLevelStatsBaseHPMax(int value, int index)
{
	if (GlobalSettings.config_version == "v1.0") playerLevelStatsV1[index]->MaxHP = value;
	else playerLevelStatsV2[index]->MaxHP = value;
}

int GetPlayerLevelStatsBaseEnergyMax(int index)
{
	if (GlobalSettings.config_version == "v1.0") return playerLevelStatsV1[index]->MaxEnergy;
	else return playerLevelStatsV2[index]->MaxEnergy;
}

void SetPlayerLevelStatsBaseEnergyMax(int value, int index)
{
	if (GlobalSettings.config_version == "v1.0") playerLevelStatsV1[index]->MaxEnergy = value;
	else playerLevelStatsV2[index]->MaxEnergy = value;
}

int GetPlayerLevelStatsBaseEnergyRechargeSpeed(int index)
{
	if (GlobalSettings.config_version == "v1.0") return playerLevelStatsV1[index]->EnergyRecharge;
	else return playerLevelStatsV2[index]->EnergyRecharge;
}

void SetPlayerLevelStatsBaseEnergyRechargeSpeed(int value, int index)
{
	if (GlobalSettings.config_version == "v1.0") playerLevelStatsV1[index]->EnergyRecharge = value;
	else playerLevelStatsV2[index]->EnergyRecharge = value;
}

int GetPlayerLevelStatsBaseAttackDamage(int index)
{
	if (GlobalSettings.config_version == "v1.0") return playerLevelStatsV1[index]->AttackDamage;
	else return playerLevelStatsV2[index]->AttackDamage;
}

void SetPlayerLevelStatsBaseAttackDamage(int value, int index)
{
	if (GlobalSettings.config_version == "v1.0") playerLevelStatsV1[index]->AttackDamage = value;
	else playerLevelStatsV2[index]->AttackDamage = value;
}



PlayerDisplayStatsV1* playerDisplayStatsV1[3];
PlayerDisplayStatsV2* playerDisplayStatsV2[3];

void SetPlayerDisplayStatsInstance(void* pointer, bool success, int index)
{
	if (!success)
	{
		if (GlobalSettings.config_version == "v1.0") playerDisplayStatsV1[index] = (PlayerDisplayStatsV1*)0x00;
		else playerDisplayStatsV2[index] = (PlayerDisplayStatsV2*)0x00;
	}
	else
	{
		if (GlobalSettings.config_version == "v1.0") playerDisplayStatsV1[index] = (PlayerDisplayStatsV1*)pointer;
		else playerDisplayStatsV2[index] = (PlayerDisplayStatsV2*)pointer;
	}
}

bool IsPlayerDisplayStatsInstance(int index)
{
	if (GlobalSettings.config_version == "v1.0") return playerDisplayStatsV1[index] != 0x00;
	else return playerDisplayStatsV2[index] != 0x00;
}

int GetPlayerDisplayStatsExperienceCurrent(int index)
{
	if (GlobalSettings.config_version == "v1.0") return playerDisplayStatsV1[index]->CurrentEXP;
	else return playerDisplayStatsV2[index]->CurrentEXP;
}

void SetPlayerDisplayStatsExperienceCurrent(int value, int index)
{
	if (GlobalSettings.config_version == "v1.0") playerDisplayStatsV1[index]->CurrentEXP = value;
	else playerDisplayStatsV2[index]->CurrentEXP = value;
}

int GetPlayerDisplayStatsMoney(int index)
{
	if (GlobalSettings.config_version == "v1.0") return playerDisplayStatsV1[index]->Money;
	else return playerDisplayStatsV2[index]->Money;
}

void SetPlayerDisplayStatsMoney(int value, int index)
{
	if (GlobalSettings.config_version == "v1.0") playerDisplayStatsV1[index]->Money = value;
	else playerDisplayStatsV2[index]->Money = value;
}


