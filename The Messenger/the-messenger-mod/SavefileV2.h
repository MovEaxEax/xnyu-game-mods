#pragma once

struct SavefileV2
{
	int magicBytes;
	int unknownValue_001[15];
	int score;
	int scoreLap;
	int missionID;
	int unknownValue_002;
	int maxHits;
	int relicts;
	int damageDealt;
	int damageReceived;
	int deaths;
	int enemiesKilled;
	int falls;
	int brokenUrns;
	int level;
};

