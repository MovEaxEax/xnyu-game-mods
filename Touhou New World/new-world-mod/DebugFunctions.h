#pragma once

struct DebugFunction {
    std::string nameParent;
    std::string nameChild;
    std::string nameFull;
	std::vector<std::string> description;
	std::string placeholder;
	bool rapid;
    std::vector<Variable> parameter;
};

struct DebugFunctionParent {
	std::string nameParent;
	std::vector<std::string> description;
	std::vector<DebugFunction> functions;
};

std::vector<DebugFunctionParent> debugFunctions;

bool GodmodeActivated = false;

float PlayerPositionXLocked = 0.0;
float PlayerPositionYLocked = 0.0;
float PlayerPositionZLocked = 0.0;
int PlayerAnimationIndexLocked = 0.0;

bool LockPositions = false;
bool LockPositionX = false;
bool LockPositionY = false;
bool LockPositionZ = false;
bool LockAnimationIndex = false;



bool parameterValid(DebugFunction* targetFunction)
{
	bool parameterValid = true;
	for (int i = 0; i < targetFunction->parameter.size(); i++)
	{
		if (targetFunction->parameter[i].value == "none")
		{
			return false;
		}
	}
	return true;
}

EXTERN_DLL_EXPORT void ExecuteDebugFunction(DebugFunction* targetFunction)
{
	std::string name = targetFunction->nameFull;
	std::transform(name.begin(), name.end(), name.begin(), ::tolower);

	bool vaild = parameterValid(targetFunction);

	if (IsPlayerObjectInstance())
	{
		if (name == "hacks.godmode") GodmodeActivated = !GodmodeActivated;
		if (name == "player.setposition" && vaild)
		{
			SetPlayerPositionX(GetVariableFloat(&targetFunction->parameter[0]));
			SetPlayerPositionY(GetVariableFloat(&targetFunction->parameter[1]));
			SetPlayerPositionZ(GetVariableFloat(&targetFunction->parameter[2]));
			if (LockPositionX) PlayerPositionXLocked = GetPlayerPositionX();
			if (LockPositionY) PlayerPositionYLocked = GetPlayerPositionY();
			if (LockPositionZ) PlayerPositionZLocked = GetPlayerPositionZ();
		}
		if (name == "player.changePosition" && vaild)
		{
			SetPlayerPositionX(GetPlayerPositionX() + GetVariableFloat(&targetFunction->parameter[0]));
			SetPlayerPositionY(GetPlayerPositionY() + GetVariableFloat(&targetFunction->parameter[1]));
			SetPlayerPositionZ(GetPlayerPositionZ() + GetVariableFloat(&targetFunction->parameter[2]));
			if (LockPositionX) PlayerPositionXLocked = GetPlayerPositionX();
			if (LockPositionY) PlayerPositionYLocked = GetPlayerPositionY();
			if (LockPositionZ) PlayerPositionZLocked = GetPlayerPositionZ();
		}
		if (name == "player.changepositionx" && vaild)
		{
			SetPlayerPositionX(GetPlayerPositionX() + GetVariableFloat(&targetFunction->parameter[0]));
			if (LockPositionX) PlayerPositionXLocked = GetPlayerPositionX();
		}
		if (name == "player.changepositiony" && vaild)
		{
			SetPlayerPositionY(GetPlayerPositionY() + GetVariableFloat(&targetFunction->parameter[0]));
			if (LockPositionY) PlayerPositionYLocked = GetPlayerPositionY();
		}
		if (name == "player.changepositionz" && vaild)
		{
			SetPlayerPositionZ(GetPlayerPositionZ() + GetVariableFloat(&targetFunction->parameter[0]));
			if (LockPositionZ) PlayerPositionZLocked = GetPlayerPositionZ();
		}
		if (name == "player.sethpcurrent" && vaild) SetPlayerHPCurrent(GetVariableInt32(&targetFunction->parameter[0]));
		if (name == "player.sethpmax" && vaild) SetPlayerHPMax(GetVariableInt32(&targetFunction->parameter[0]));
		if (name == "player.setanimationindex" && vaild)
		{
			SetPlayerAnimationIndex(GetVariableInt32(&targetFunction->parameter[0]));
			if (LockAnimationIndex) PlayerAnimationIndexLocked = GetPlayerAnimationIndex();
		}
		if (name == "player.settimeinstage" && vaild) SetPlayerTimeInStage(GetVariableDouble(&targetFunction->parameter[0]));
		if (name == "player.setskillhealcooldown" && vaild) SetPlayerHealCooldown(GetVariableInt32(&targetFunction->parameter[0]));
		if (name == "player.setblockcanreset" && vaild) SetPlayerBlockCanReset(GetVariableInt32(&targetFunction->parameter[0]));

		if (name == "player.lockposition")
		{
			bool trigger = !LockPositions;
			if (vaild)
			{
				trigger = GetVariableBool(&targetFunction->parameter[0]);
			}
			LockPositions = trigger;
			LockPositionX = trigger;
			LockPositionY = trigger;
			LockPositionZ = trigger;
			if (trigger)
			{
				PlayerPositionXLocked = GetPlayerPositionX();
				PlayerPositionYLocked = GetPlayerPositionY();
				PlayerPositionZLocked = GetPlayerPositionZ();
			}
		}
		if (name == "player.lockpositionx")
		{
			bool triggerX = !LockPositionX;
			if (vaild) triggerX = GetVariableBool(&targetFunction->parameter[0]);
			LockPositionX = triggerX;
			if (triggerX) PlayerPositionXLocked = GetPlayerPositionX();
		}
		if (name == "player.lockpositiony")
		{
			bool triggerY = !LockPositionY;
			if (vaild) triggerY = GetVariableBool(&targetFunction->parameter[0]);
			LockPositionY = triggerY;
			if (triggerY) PlayerPositionYLocked = GetPlayerPositionY();
		}
		if (name == "player.lockpositionz")
		{
			bool triggerZ = !LockPositionZ;
			if (vaild) triggerZ = GetVariableBool(&targetFunction->parameter[0]);
			LockPositionZ = triggerZ;
			if (triggerZ) PlayerPositionZLocked = GetPlayerPositionZ();
		}

		if (name == "player.lockanimationindex")
		{
			bool trigger = !LockAnimationIndex;
			if (vaild) trigger = GetVariableBool(&targetFunction->parameter[0]);
			LockAnimationIndex = trigger;
			if (trigger) PlayerAnimationIndexLocked = GetPlayerAnimationIndex();
		}
	}



}


