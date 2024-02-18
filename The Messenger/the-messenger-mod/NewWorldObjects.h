#pragma once

int CharacterUsedCurrent = -1;



PlayerObjectV110* playerObjectV110;

void SetPlayerObjectInstance(void* pointer, bool success)
{
	if (!success)
	{
		if (GlobalSettings.config_version == "V1.1.0") playerObjectV110 = (PlayerObjectV110*)0x00;
	}
	else
	{
		if (GlobalSettings.config_version == "V1.1.0") playerObjectV110 = (PlayerObjectV110*)pointer;
	}
}

bool IsPlayerObjectInstance()
{
	if (GlobalSettings.config_version == "V1.1.0") return playerObjectV110 != 0x00;
}

float GetPlayerPositionX()
{
	if (GlobalSettings.config_version == "V1.1.0") return playerObjectV110->Position.x;
}

void SetPlayerPositionX(float value)
{
	if (GlobalSettings.config_version == "V1.1.0") playerObjectV110->Position.x = value;
}

float GetPlayerPositionY()
{
	if (GlobalSettings.config_version == "V1.1.0") return playerObjectV110->Position.y;
}

void SetPlayerPositionY(float value)
{
	if (GlobalSettings.config_version == "V1.1.0") playerObjectV110->Position.y = value;
}

float GetPlayerPositionZ()
{
	if (GlobalSettings.config_version == "V1.1.0") return playerObjectV110->Position.z;
}

void SetPlayerPositionZ(float value)
{
	if (GlobalSettings.config_version == "V1.1.0") playerObjectV110->Position.z = value;
}

int GetPlayerHPCurrent()
{
	if (GlobalSettings.config_version == "V1.1.0") return playerObjectV110->HPCurrent;
}

void SetPlayerHPCurrent(int value)
{
	if (GlobalSettings.config_version == "V1.1.0") playerObjectV110->HPCurrent = value;
}

int GetPlayerHPMax()
{
	if (GlobalSettings.config_version == "V1.1.0") return playerObjectV110->HPMax;
}

void SetPlayerHPMax(int value)
{
	if (GlobalSettings.config_version == "V1.1.0") playerObjectV110->HPMax = value;
}

// Animations
int GetPlayerAnimationIndex()
{
	if (GlobalSettings.config_version == "V1.1.0") return playerObjectV110->AnimationIndex;
}

void SetPlayerAnimationIndex(int value)
{
	if (GlobalSettings.config_version == "V1.1.0") playerObjectV110->AnimationIndex = value;
}

// Timers
double GetPlayerTimeInStage()
{
	if (GlobalSettings.config_version == "V1.1.0") return playerObjectV110->TimeInStage;
}

void SetPlayerTimeInStage(double value)
{
	if (GlobalSettings.config_version == "V1.1.0") playerObjectV110->TimeInStage = value;
}

// Skills
int GetPlayerHealCooldown()
{
	if (GlobalSettings.config_version == "V1.1.0") return playerObjectV110->SkillHealthCooldown;
}

void SetPlayerHealCooldown(int value)
{
	if (GlobalSettings.config_version == "V1.1.0") playerObjectV110->SkillHealthCooldown = value;
}

int GetPlayerBlockCanReset()
{
	if (GlobalSettings.config_version == "V1.1.0") return playerObjectV110->BlockCanReset;
}

void SetPlayerBlockCanReset(int value)
{
	if (GlobalSettings.config_version == "V1.1.0") playerObjectV110->BlockCanReset = value;
}


