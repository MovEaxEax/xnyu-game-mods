#pragma once

struct DebugFunction {
    std::string nameParent;
    std::string nameChild;
    std::string nameFull;
    bool rapid;
    std::vector<Variable> parameter;
};

struct DebugFunctionParent {
    std::string nameParent;
    std::vector<DebugFunction> functions;
};

std::vector<DebugFunctionParent> debugFunctions;

bool GodmodeActivated = false;

float PlayerPositionXLocked = 0.0;
float PlayerPositionYLocked = 0.0;
float PlayerPositionZLocked = 0.0;
float PlayerSpeedFactorXLocked = 0.0;
float PlayerSpeedFactorYLocked = 0.0;
float PlayerSpeedFactorZLocked = 0.0;
float PlayerDirectionLocked = 0.0;
int PlayerAnimationIndexLocked = 0.0;

bool LockPositions = false;
bool LockPositionX = false;
bool LockPositionY = false;
bool LockPositionZ = false;
bool LockDirection = false;
bool LockSpeedFactors = false;
bool LockSpeedFactorX = false;
bool LockSpeedFactorY = false;
bool LockSpeedFactorZ = false;
bool LockAnimationIndex = false;

float CameraPositionXLocked = 0.0;
float CameraPositionYLocked = 0.0;
float CameraPositionZLocked = 0.0;
float CameraAngleXLocked = 0.0;
float CameraAngleYLocked = 0.0;
float CameraAngleZLocked = 0.0;
float CameraZoomLocked = 0.0;

bool LockCameraPositions = false;
bool LockCameraPositionX = false;
bool LockCameraPositionY = false;
bool LockCameraPositionZ = false;
bool LockCameraAngles = false;
bool LockCameraAngleX = false;
bool LockCameraAngleY = false;
bool LockCameraAngleZ = false;
bool LockCameraZoom = false;


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
		if (name == "player.sethp" && vaild) SetPlayerHP(GetVariableInt32(&targetFunction->parameter[0]));
		if (name == "player.setenergy" && vaild) SetPlayerEnergy(GetVariableInt32(&targetFunction->parameter[0]));
		if (name == "player.setspellcardbar" && vaild) SetPlayerSpellcardBar(GetVariableInt32(&targetFunction->parameter[0]));
		if (name == "player.setspeedfactor" && vaild)
		{
			SetPlayerSpeedFactorX(GetVariableFloat(&targetFunction->parameter[0]));
			SetPlayerSpeedFactorY(GetVariableFloat(&targetFunction->parameter[1]));
			SetPlayerSpeedFactorZ(GetVariableFloat(&targetFunction->parameter[2]));
			if (LockSpeedFactorX) PlayerSpeedFactorXLocked = GetPlayerSpeedFactorX();
			if (LockSpeedFactorY) PlayerSpeedFactorYLocked = GetPlayerSpeedFactorY();
			if (LockSpeedFactorZ) PlayerSpeedFactorZLocked = GetPlayerSpeedFactorZ();
		}
		if (name == "player.changespeedfactorx" && vaild)
		{
			SetPlayerSpeedFactorX(GetPlayerSpeedFactorX() + GetVariableFloat(&targetFunction->parameter[0]));
			if (LockSpeedFactorX) PlayerSpeedFactorXLocked = GetPlayerSpeedFactorX();
		}
		if (name == "player.changespeedfactory" && vaild)
		{
			SetPlayerSpeedFactorY(GetPlayerSpeedFactorY() + GetVariableFloat(&targetFunction->parameter[0]));
			if (LockSpeedFactorY) PlayerSpeedFactorYLocked = GetPlayerSpeedFactorY();
		}
		if (name == "player.changespeedfactorz" && vaild)
		{
			SetPlayerSpeedFactorZ(GetPlayerSpeedFactorZ() + GetVariableFloat(&targetFunction->parameter[0]));
			if (LockSpeedFactorZ) PlayerSpeedFactorZLocked = GetPlayerSpeedFactorZ();
		}
		if (name == "player.setanimationindex" && vaild)
		{
			SetPlayerAnimationIndex(GetVariableInt32(&targetFunction->parameter[0]));
			if (LockAnimationIndex) PlayerAnimationIndexLocked = GetPlayerAnimationIndex();
		}
		if (name == "player.setdirection" && vaild)
		{
			SetPlayerDirection(GetVariableFloat(&targetFunction->parameter[0]));
			if (LockDirection) PlayerDirectionLocked = GetPlayerDirection();
		}
		if (name == "player.changedirection" && vaild)
		{
			SetPlayerDirection(GetPlayerDirection() + GetVariableFloat(&targetFunction->parameter[0]));
			if (LockDirection) PlayerDirectionLocked = GetPlayerDirection();
		}

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

		if (name == "player.lockspeedfactor")
		{
			bool trigger = !LockSpeedFactors;
			if (vaild)
			{
				trigger = GetVariableBool(&targetFunction->parameter[0]);
			}
			LockSpeedFactors = trigger;
			LockSpeedFactorX = trigger;
			LockSpeedFactorY = trigger;
			LockSpeedFactorZ = trigger;
			if (trigger)
			{
				PlayerSpeedFactorXLocked = GetPlayerSpeedFactorX();
				PlayerSpeedFactorYLocked = GetPlayerSpeedFactorY();
				PlayerSpeedFactorZLocked = GetPlayerSpeedFactorZ();
			}
		}
		if (name == "player.lockspeedfactorx")
		{
			bool triggerX = !LockSpeedFactorX;
			if (vaild) triggerX = GetVariableBool(&targetFunction->parameter[0]);
			LockSpeedFactorX = triggerX;
			if (triggerX) PlayerSpeedFactorXLocked = GetPlayerSpeedFactorX();
		}
		if (name == "player.lockspeedfactory")
		{
			bool triggerY = !LockSpeedFactorY;
			if (vaild) triggerY = GetVariableBool(&targetFunction->parameter[0]);
			LockSpeedFactorY = triggerY;
			if (triggerY) PlayerSpeedFactorYLocked = GetPlayerSpeedFactorY();
		}
		if (name == "player.lockspeedfactorz")
		{
			bool triggerZ = !LockSpeedFactorZ;
			if (vaild) triggerZ = GetVariableBool(&targetFunction->parameter[0]);
			LockSpeedFactorZ = triggerZ;
			if (triggerZ) PlayerSpeedFactorZLocked = GetPlayerSpeedFactorZ();
		}

		if (name == "player.lockdirection")
		{
			bool trigger = !LockDirection;
			if (vaild) trigger = GetVariableBool(&targetFunction->parameter[0]);
			LockDirection = trigger;
			if (trigger) PlayerDirectionLocked = GetPlayerDirection();
		}

		if (name == "player.lockanimationindex")
		{
			bool trigger = !LockAnimationIndex;
			if (vaild) trigger = GetVariableBool(&targetFunction->parameter[0]);
			LockAnimationIndex = trigger;
			if (trigger) PlayerAnimationIndexLocked = GetPlayerAnimationIndex();
		}

		if (name == "squirrel.sharedsetposition" && vaild)
		{
			float position[3] = { GetVariableFloat(&targetFunction->parameter[0]), GetVariableFloat(&targetFunction->parameter[1]), GetVariableFloat(&targetFunction->parameter[2]) };
			pSharedSetPosition(playerObjectV1, position);
		}

	}

	if (IsCameraObjectInstance())
	{
		if (name == "camera.setposition" && vaild)
		{
			SetCameraPositionX(GetVariableFloat(&targetFunction->parameter[0]));
			SetCameraPositionY(GetVariableFloat(&targetFunction->parameter[1]));
			SetCameraPositionZ(GetVariableFloat(&targetFunction->parameter[2]));
			if (LockCameraPositionX) CameraPositionXLocked = GetCameraPositionX();
			if (LockCameraPositionY) CameraPositionYLocked = GetCameraPositionY();
			if (LockCameraPositionZ) CameraPositionZLocked = GetCameraPositionZ();
		}
		if (name == "camera.changeposition" && vaild)
		{
			SetCameraPositionX(GetCameraPositionX() + GetVariableFloat(&targetFunction->parameter[0]));
			SetCameraPositionY(GetCameraPositionY() + GetVariableFloat(&targetFunction->parameter[1]));
			SetCameraPositionZ(GetCameraPositionZ() + GetVariableFloat(&targetFunction->parameter[2]));
			if (LockCameraPositionX) CameraPositionXLocked = GetCameraPositionX();
			if (LockCameraPositionY) CameraPositionYLocked = GetCameraPositionY();
			if (LockCameraPositionZ) CameraPositionZLocked = GetCameraPositionZ();
		}
		if (name == "camera.changepositionx" && vaild)
		{
			SetCameraPositionX(GetCameraPositionX() + GetVariableFloat(&targetFunction->parameter[0]));
			if (LockCameraPositionX) CameraPositionXLocked = GetCameraPositionX();
		}
		if (name == "camera.changepositiony" && vaild)
		{
			SetCameraPositionY(GetCameraPositionY() + GetVariableFloat(&targetFunction->parameter[0]));
			if (LockCameraPositionY) CameraPositionYLocked = GetCameraPositionY();
		}
		if (name == "camera.changepositionz" && vaild)
		{
			SetCameraPositionZ(GetCameraPositionZ() + GetVariableFloat(&targetFunction->parameter[0]));
			if (LockCameraPositionZ) CameraPositionZLocked = GetCameraPositionZ();
		}
		if (name == "camera.lockposition")
		{
			bool trigger = !LockCameraPositions;
			if (vaild)
			{
				trigger = GetVariableBool(&targetFunction->parameter[0]);
			}
			LockCameraPositions = trigger;
			LockCameraPositionX = trigger;
			LockCameraPositionY = trigger;
			LockCameraPositionZ = trigger;
			if (trigger)
			{
				CameraPositionXLocked = GetCameraPositionX();
				CameraPositionYLocked = GetCameraPositionY();
				CameraPositionZLocked = GetCameraPositionZ();
			}
		}
		if (name == "camera.lockpositionx")
		{
			bool triggerX = !LockCameraPositionX;
			if (vaild) triggerX = GetVariableBool(&targetFunction->parameter[0]);
			LockCameraPositionX = triggerX;
			if (triggerX) CameraPositionXLocked = GetCameraPositionX();
		}
		if (name == "camera.lockpositiony")
		{
			bool triggerY = !LockCameraPositionY;
			if (vaild) triggerY = GetVariableBool(&targetFunction->parameter[0]);
			LockCameraPositionY = triggerY;
			if (triggerY) CameraPositionYLocked = GetCameraPositionY();
		}
		if (name == "camera.lockpositionz")
		{
			bool triggerZ = !LockCameraPositionZ;
			if (vaild) triggerZ = GetVariableBool(&targetFunction->parameter[0]);
			LockCameraPositionZ = triggerZ;
			if (triggerZ) CameraPositionZLocked = GetCameraPositionZ();
		}

		if (name == "camera.setangle" && vaild)
		{
			SetCameraAngleX(GetVariableFloat(&targetFunction->parameter[0]));
			SetCameraAngleY(GetVariableFloat(&targetFunction->parameter[1]));
			SetCameraAngleZ(GetVariableFloat(&targetFunction->parameter[2]));
			if (LockCameraAngleX) CameraAngleXLocked = GetCameraAngleX();
			if (LockCameraAngleY) CameraAngleYLocked = GetCameraAngleY();
			if (LockCameraAngleZ) CameraAngleZLocked = GetCameraAngleZ();
		}
		if (name == "camera.changeangle" && vaild)
		{
			SetCameraAngleX(GetCameraAngleX() + GetVariableFloat(&targetFunction->parameter[0]));
			SetCameraAngleY(GetCameraAngleY() + GetVariableFloat(&targetFunction->parameter[1]));
			SetCameraAngleZ(GetCameraAngleZ() + GetVariableFloat(&targetFunction->parameter[2]));
			if (LockCameraAngleX) CameraAngleXLocked = GetCameraAngleX();
			if (LockCameraAngleY) CameraAngleYLocked = GetCameraAngleY();
			if (LockCameraAngleZ) CameraAngleZLocked = GetCameraAngleZ();
		}
		if (name == "camera.changeanglex" && vaild)
		{
			SetCameraAngleX(GetCameraAngleX() + GetVariableFloat(&targetFunction->parameter[0]));
			if (LockCameraAngleX) CameraAngleXLocked = GetCameraAngleX();
		}
		if (name == "camera.changeangley" && vaild)
		{
			SetCameraAngleY(GetCameraAngleY() + GetVariableFloat(&targetFunction->parameter[0]));
			if (LockCameraAngleY) CameraAngleYLocked = GetCameraAngleY();
		}
		if (name == "camera.changeanglez" && vaild)
		{
			SetCameraAngleZ(GetCameraAngleZ() + GetVariableFloat(&targetFunction->parameter[0]));
			if (LockCameraAngleZ) CameraAngleZLocked = GetCameraAngleZ();
		}
		if (name == "camera.lockangle")
		{
			bool trigger = !LockCameraAngles;
			if (vaild)
			{
				trigger = GetVariableBool(&targetFunction->parameter[0]);
			}
			LockCameraAngles = trigger;
			LockCameraAngleX = trigger;
			LockCameraAngleY = trigger;
			LockCameraAngleZ = trigger;
			if (trigger)
			{
				CameraAngleXLocked = GetCameraAngleX();
				CameraAngleYLocked = GetCameraAngleY();
				CameraAngleZLocked = GetCameraAngleZ();
			}
		}
		if (name == "camera.lockanglex")
		{
			bool triggerX = !LockCameraAngleX;
			if (vaild) triggerX = GetVariableBool(&targetFunction->parameter[0]);
			LockCameraAngleX = triggerX;
			if (triggerX) CameraAngleXLocked = GetCameraAngleX();
		}
		if (name == "camera.lockangley")
		{
			bool triggerY = !LockCameraAngleY;
			if (vaild) triggerY = GetVariableBool(&targetFunction->parameter[0]);
			LockCameraAngleY = triggerY;
			if (triggerY) CameraAngleYLocked = GetCameraAngleY();
		}
		if (name == "camera.lockanglez")
		{
			bool triggerZ = !LockCameraAngleZ;
			if (vaild) triggerZ = GetVariableBool(&targetFunction->parameter[0]);
			LockCameraAngleZ = triggerZ;
			if (triggerZ) CameraAngleZLocked = GetCameraAngleZ();
		}
		if (name == "camera.setzoom" && vaild)
		{
			SetCameraZoom(GetVariableFloat(&targetFunction->parameter[0]));
			if (LockCameraZoom) CameraZoomLocked = GetCameraZoom();
		}
		if (name == "camera.changezoom" && vaild)
		{
			SetCameraZoom(GetCameraZoom() + GetVariableFloat(&targetFunction->parameter[0]));
			if (LockCameraZoom) CameraZoomLocked = GetCameraZoom();
		}
		if (name == "camera.lockzoom")
		{
			bool triggerX = !LockCameraZoom;
			if (vaild) triggerX = GetVariableBool(&targetFunction->parameter[0]);
			LockCameraZoom = triggerX;
			if (triggerX) CameraZoomLocked = GetCameraZoom();
		}

	}

	if (IsGameGlobalsInstance())
	{
		if (name == "objects.setobjectscounter" && vaild)
		{
			SetAllObjects(GetVariableInt32(&targetFunction->parameter[0]));
		}
	}

	// Game
	if (name == "game.setgamepaused")
	{
		if (vaild) DbgWriteBool(IsGamePausedAddress, GetVariableBool(&targetFunction->parameter[0]));
		else DbgWriteBool(IsGamePausedAddress, !DbgReadBool(IsGamePausedAddress));
	}
	



}


