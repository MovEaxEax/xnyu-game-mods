#pragma once

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

// Player positions
float GetPlayerPositionX()
{
	if (GlobalSettings.config_version == "v1.0") return playerObjectV1->PositionX;
	else return playerObjectV2->PositionX;
}

void SetPlayerPositionX(float value)
{
	if (GlobalSettings.config_version == "v1.0") playerObjectV1->PositionX = value;
	else playerObjectV2->PositionX = value;
}

float GetPlayerPositionY()
{
	if (GlobalSettings.config_version == "v1.0") return playerObjectV1->PositionY;
	else return playerObjectV2->PositionY;
}

void SetPlayerPositionY(float value)
{
	if (GlobalSettings.config_version == "v1.0") playerObjectV1->PositionY = value;
	else playerObjectV2->PositionY = value;
}

float GetPlayerPositionZ()
{
	if (GlobalSettings.config_version == "v1.0") return playerObjectV1->PositionZ;
	else return playerObjectV2->PositionZ;
}

void SetPlayerPositionZ(float value)
{
	if (GlobalSettings.config_version == "v1.0") playerObjectV1->PositionZ = value;
	else playerObjectV2->PositionZ = value;
}

float GetPlayerDirection()
{
	if (GlobalSettings.config_version == "v1.0") return atan2(playerObjectV1->AngleFactor1, playerObjectV1->AngleFactor2) * 360 / PI;
	else return atan2(playerObjectV2->AngleFactor1, playerObjectV2->AngleFactor2) * 360 / PI;
}

void SetPlayerDirection(float value)
{
	float angleRadians = value * PI / 360;
	float angleFactor1 = sin(angleRadians);
	float angleFactor2 = cos(angleRadians);
	if (GlobalSettings.config_version == "v1.0")
	{
		playerObjectV1->AngleFactor1 = angleFactor1;
		playerObjectV1->AngleFactor1 = angleFactor2;
	}
	else
	{
		playerObjectV2->AngleFactor1 = angleFactor1;
		playerObjectV2->AngleFactor1 = angleFactor2;
	}
}

// HP, Energy, Spellcard
int GetPlayerEnergy()
{
	if (GlobalSettings.config_version == "v1.0") return playerObjectV1->EnergyCurrent;
	else return playerObjectV2->EnergyCurrent;
}

void SetPlayerEnergy(int value)
{
	if (GlobalSettings.config_version == "v1.0") playerObjectV1->EnergyCurrent = value;
	else playerObjectV2->EnergyCurrent = value;
}

int GetPlayerHP()
{
	if (GlobalSettings.config_version == "v1.0") return playerObjectV1->HPCurrent;
	else return playerObjectV2->HPCurrent;
}

void SetPlayerHP(int value)
{
	if (GlobalSettings.config_version == "v1.0") playerObjectV1->HPCurrent = value;
	else playerObjectV2->HPCurrent = value;
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
	if (GlobalSettings.config_version == "v1.0") return playerObjectV1->SpeedFactorX;
	else return playerObjectV2->SpeedFactorX;
}

void SetPlayerSpeedFactorX(float value)
{
	if (GlobalSettings.config_version == "v1.0") playerObjectV1->SpeedFactorX = value;
	else playerObjectV2->SpeedFactorX = value;
}

float GetPlayerSpeedFactorY()
{
	if (GlobalSettings.config_version == "v1.0") return playerObjectV1->SpeedFactorY;
	else return playerObjectV2->SpeedFactorY;
}

void SetPlayerSpeedFactorY(float value)
{
	if (GlobalSettings.config_version == "v1.0") playerObjectV1->SpeedFactorY = value;
	else playerObjectV2->SpeedFactorY = value;
}

float GetPlayerSpeedFactorZ()
{
	if (GlobalSettings.config_version == "v1.0") return playerObjectV1->SpeedFactorZ;
	else return playerObjectV2->SpeedFactorZ;
}

void SetPlayerSpeedFactorZ(float value)
{
	if (GlobalSettings.config_version == "v1.0") playerObjectV1->SpeedFactorZ = value;
	else playerObjectV2->SpeedFactorZ = value;
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
float GetCameraPositionX()
{
	if (GlobalSettings.config_version == "v1.0") return cameraObjectV1->PositionX;
	else return cameraObjectV2->PositionX;
}

void SetCameraPositionX(float value)
{
	if (GlobalSettings.config_version == "v1.0") cameraObjectV1->PositionX = value;
	else cameraObjectV2->PositionX = value;
}

float GetCameraPositionY()
{
	if (GlobalSettings.config_version == "v1.0") return cameraObjectV1->PositionY;
	else return cameraObjectV2->PositionY;
}

void SetCameraPositionY(float value)
{
	if (GlobalSettings.config_version == "v1.0") cameraObjectV1->PositionY = value;
	else cameraObjectV2->PositionY = value;
}

float GetCameraPositionZ()
{
	if (GlobalSettings.config_version == "v1.0") return cameraObjectV1->PositionZ;
	else return cameraObjectV2->PositionZ;
}

void SetCameraPositionZ(float value)
{
	if (GlobalSettings.config_version == "v1.0") cameraObjectV1->PositionZ = value;
	else cameraObjectV2->PositionZ = value;
}

float GetCameraAngleX()
{
	if (GlobalSettings.config_version == "v1.0") return cameraObjectV1->AngleX;
	else return cameraObjectV2->AngleX;
}

void SetCameraAngleX(float value)
{
	if (GlobalSettings.config_version == "v1.0") cameraObjectV1->AngleX = value;
	else cameraObjectV2->AngleX = value;
}

float GetCameraAngleY()
{
	if (GlobalSettings.config_version == "v1.0") return cameraObjectV1->AngleY;
	else return cameraObjectV2->AngleY;
}

void SetCameraAngleY(float value)
{
	if (GlobalSettings.config_version == "v1.0") cameraObjectV1->AngleY = value;
	else cameraObjectV2->AngleY = value;
}

float GetCameraAngleZ()
{
	if (GlobalSettings.config_version == "v1.0") return cameraObjectV1->AngleZ;
	else return cameraObjectV2->AngleZ;
}

void SetCameraAngleZ(float value)
{
	if (GlobalSettings.config_version == "v1.0") cameraObjectV1->AngleZ = value;
	else cameraObjectV2->AngleZ = value;
}

float GetCameraZoom()
{
	if (GlobalSettings.config_version == "v1.0") return cameraObjectV1->Zoom;
	else return cameraObjectV2->Zoom;
}

void SetCameraZoom(float value)
{
	if (GlobalSettings.config_version == "v1.0") cameraObjectV1->Zoom = value;
	else cameraObjectV2->Zoom = value;
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





