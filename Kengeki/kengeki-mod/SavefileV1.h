#pragma once

struct SavefileV1
{
	int magicBytes;
	int unknownValue_001[15];
	int score;
	int scoreLap;
	int unknownValue_002;
	int unknownValue_003;
	int missionID;
	int unknownValue_004;
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

