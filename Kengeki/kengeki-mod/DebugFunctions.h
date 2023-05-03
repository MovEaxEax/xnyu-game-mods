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
	bool vaild = parameterValid(targetFunction);

	if (IsPlayerObjectInstance())
	{
		if (targetFunction->nameFull == "Hacks.Godmode") GodmodeActivated = !GodmodeActivated;
		if (targetFunction->nameFull == "Player.SetPosition" && vaild)
		{
			SetPlayerPositionX(GetVariableFloat(&targetFunction->parameter[0]));
			SetPlayerPositionY(GetVariableFloat(&targetFunction->parameter[1]));
			SetPlayerPositionZ(GetVariableFloat(&targetFunction->parameter[2]));
			if (LockPositionX) PlayerPositionXLocked = GetPlayerPositionX();
			if (LockPositionY) PlayerPositionYLocked = GetPlayerPositionY();
			if (LockPositionZ) PlayerPositionZLocked = GetPlayerPositionZ();
		}
		if (targetFunction->nameFull == "Player.ChangePosition" && vaild)
		{
			SetPlayerPositionX(GetPlayerPositionX() + GetVariableFloat(&targetFunction->parameter[0]));
			SetPlayerPositionY(GetPlayerPositionY() + GetVariableFloat(&targetFunction->parameter[1]));
			SetPlayerPositionZ(GetPlayerPositionZ() + GetVariableFloat(&targetFunction->parameter[2]));
			if (LockPositionX) PlayerPositionXLocked = GetPlayerPositionX();
			if (LockPositionY) PlayerPositionYLocked = GetPlayerPositionY();
			if (LockPositionZ) PlayerPositionZLocked = GetPlayerPositionZ();
		}
		if (targetFunction->nameFull == "Player.ChangePositionX" && vaild)
		{
			SetPlayerPositionX(GetPlayerPositionX() + GetVariableFloat(&targetFunction->parameter[0]));
			if (LockPositionX) PlayerPositionXLocked = GetPlayerPositionX();
		}
		if (targetFunction->nameFull == "Player.ChangePositionY" && vaild)
		{
			SetPlayerPositionY(GetPlayerPositionY() + GetVariableFloat(&targetFunction->parameter[0]));
			if (LockPositionY) PlayerPositionYLocked = GetPlayerPositionY();
		}
		if (targetFunction->nameFull == "Player.ChangePositionZ" && vaild)
		{
			SetPlayerPositionZ(GetPlayerPositionZ() + GetVariableFloat(&targetFunction->parameter[0]));
			if (LockPositionZ) PlayerPositionZLocked = GetPlayerPositionZ();
		}
		if (targetFunction->nameFull == "Player.SetHP" && vaild) SetPlayerHP(GetVariableInt32(&targetFunction->parameter[0]));
		if (targetFunction->nameFull == "Player.SetEnergy" && vaild) SetPlayerEnergy(GetVariableInt32(&targetFunction->parameter[0]));
		if (targetFunction->nameFull == "Player.SetSpellcardBar" && vaild) SetPlayerSpellcardBar(GetVariableInt32(&targetFunction->parameter[0]));
		if (targetFunction->nameFull == "Player.SetSpeedFactor" && vaild)
		{
			SetPlayerSpeedFactorX(GetVariableFloat(&targetFunction->parameter[0]));
			SetPlayerSpeedFactorY(GetVariableFloat(&targetFunction->parameter[1]));
			SetPlayerSpeedFactorZ(GetVariableFloat(&targetFunction->parameter[2]));
			if (LockSpeedFactorX) PlayerSpeedFactorXLocked = GetPlayerSpeedFactorX();
			if (LockSpeedFactorY) PlayerSpeedFactorYLocked = GetPlayerSpeedFactorY();
			if (LockSpeedFactorZ) PlayerSpeedFactorZLocked = GetPlayerSpeedFactorZ();
		}
		if (targetFunction->nameFull == "Player.ChangeSpeedFactorX" && vaild)
		{
			SetPlayerSpeedFactorX(GetPlayerSpeedFactorX() + GetVariableFloat(&targetFunction->parameter[0]));
			if (LockSpeedFactorX) PlayerSpeedFactorXLocked = GetPlayerSpeedFactorX();
		}
		if (targetFunction->nameFull == "Player.ChangeSpeedFactorY" && vaild)
		{
			SetPlayerSpeedFactorY(GetPlayerSpeedFactorY() + GetVariableFloat(&targetFunction->parameter[0]));
			if (LockSpeedFactorY) PlayerSpeedFactorYLocked = GetPlayerSpeedFactorY();
		}
		if (targetFunction->nameFull == "Player.ChangeSpeedFactorZ" && vaild)
		{
			SetPlayerSpeedFactorZ(GetPlayerSpeedFactorZ() + GetVariableFloat(&targetFunction->parameter[0]));
			if (LockSpeedFactorZ) PlayerSpeedFactorZLocked = GetPlayerSpeedFactorZ();
		}
		if (targetFunction->nameFull == "Player.SetAnimationIndex" && vaild)
		{
			SetPlayerAnimationIndex(GetVariableInt32(&targetFunction->parameter[0]));
			if (LockAnimationIndex) PlayerAnimationIndexLocked = GetPlayerAnimationIndex();
		}
		if (targetFunction->nameFull == "Player.SetDirection" && vaild)
		{
			SetPlayerDirection(GetVariableFloat(&targetFunction->parameter[0]));
			if (LockDirection) PlayerDirectionLocked = GetPlayerDirection();
		}
		if (targetFunction->nameFull == "Player.ChangeDirection" && vaild)
		{
			SetPlayerDirection(GetPlayerDirection() + GetVariableFloat(&targetFunction->parameter[0]));
			if (LockDirection) PlayerDirectionLocked = GetPlayerDirection();
		}

		if (targetFunction->nameFull == "Player.LockPosition")
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
		if (targetFunction->nameFull == "Player.LockPositionX")
		{
			bool triggerX = !LockPositionX;
			if (vaild) triggerX = GetVariableBool(&targetFunction->parameter[0]);
			LockPositionX = triggerX;
			if (triggerX) PlayerPositionXLocked = GetPlayerPositionX();
		}
		if (targetFunction->nameFull == "Player.LockPositionY")
		{
			bool triggerY = !LockPositionY;
			if (vaild) triggerY = GetVariableBool(&targetFunction->parameter[0]);
			LockPositionY = triggerY;
			if (triggerY) PlayerPositionYLocked = GetPlayerPositionY();
		}
		if (targetFunction->nameFull == "Player.LockPositionZ")
		{
			bool triggerZ = !LockPositionZ;
			if (vaild) triggerZ = GetVariableBool(&targetFunction->parameter[0]);
			LockPositionZ = triggerZ;
			if (triggerZ) PlayerPositionZLocked = GetPlayerPositionZ();
		}

		if (targetFunction->nameFull == "Player.LockSpeedFactor")
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
		if (targetFunction->nameFull == "Player.LockSpeedFactorX")
		{
			bool triggerX = !LockSpeedFactorX;
			if (vaild) triggerX = GetVariableBool(&targetFunction->parameter[0]);
			LockSpeedFactorX = triggerX;
			if (triggerX) PlayerSpeedFactorXLocked = GetPlayerSpeedFactorX();
		}
		if (targetFunction->nameFull == "Player.LockSpeedFactorY")
		{
			bool triggerY = !LockSpeedFactorY;
			if (vaild) triggerY = GetVariableBool(&targetFunction->parameter[0]);
			LockSpeedFactorY = triggerY;
			if (triggerY) PlayerSpeedFactorYLocked = GetPlayerSpeedFactorY();
		}
		if (targetFunction->nameFull == "Player.LockSpeedFactorZ")
		{
			bool triggerZ = !LockSpeedFactorZ;
			if (vaild) triggerZ = GetVariableBool(&targetFunction->parameter[0]);
			LockSpeedFactorZ = triggerZ;
			if (triggerZ) PlayerSpeedFactorZLocked = GetPlayerSpeedFactorZ();
		}

		if (targetFunction->nameFull == "Player.LockDirection")
		{
			bool trigger = !LockDirection;
			if (vaild) trigger = GetVariableBool(&targetFunction->parameter[0]);
			LockDirection = trigger;
			if (trigger) PlayerDirectionLocked = GetPlayerDirection();
		}

		if (targetFunction->nameFull == "Player.LockAnimationIndex")
		{
			bool trigger = !LockAnimationIndex;
			if (vaild) trigger = GetVariableBool(&targetFunction->parameter[0]);
			LockAnimationIndex = trigger;
			if (trigger) PlayerAnimationIndexLocked = GetPlayerAnimationIndex();
		}

		if (targetFunction->nameFull == "Squirrel.SharedSetPosition" && vaild)
		{
			float position[3] = { GetVariableFloat(&targetFunction->parameter[0]), GetVariableFloat(&targetFunction->parameter[1]), GetVariableFloat(&targetFunction->parameter[2]) };
			pSharedSetPosition(playerObjectV1, position);
		}

	}

	if (IsCameraObjectInstance())
	{
		if (targetFunction->nameFull == "Camera.SetPosition" && vaild)
		{
			SetCameraPositionX(GetVariableFloat(&targetFunction->parameter[0]));
			SetCameraPositionY(GetVariableFloat(&targetFunction->parameter[1]));
			SetCameraPositionZ(GetVariableFloat(&targetFunction->parameter[2]));
			if (LockCameraPositionX) CameraPositionXLocked = GetCameraPositionX();
			if (LockCameraPositionY) CameraPositionYLocked = GetCameraPositionY();
			if (LockCameraPositionZ) CameraPositionZLocked = GetCameraPositionZ();
		}
		if (targetFunction->nameFull == "Camera.ChangePosition" && vaild)
		{
			SetCameraPositionX(GetCameraPositionX() + GetVariableFloat(&targetFunction->parameter[0]));
			SetCameraPositionY(GetCameraPositionY() + GetVariableFloat(&targetFunction->parameter[1]));
			SetCameraPositionZ(GetCameraPositionZ() + GetVariableFloat(&targetFunction->parameter[2]));
			if (LockCameraPositionX) CameraPositionXLocked = GetCameraPositionX();
			if (LockCameraPositionY) CameraPositionYLocked = GetCameraPositionY();
			if (LockCameraPositionZ) CameraPositionZLocked = GetCameraPositionZ();
		}
		if (targetFunction->nameFull == "Camera.ChangePositionX" && vaild)
		{
			SetCameraPositionX(GetCameraPositionX() + GetVariableFloat(&targetFunction->parameter[0]));
			if (LockCameraPositionX) CameraPositionXLocked = GetCameraPositionX();
		}
		if (targetFunction->nameFull == "Camera.ChangePositionY" && vaild)
		{
			SetCameraPositionY(GetCameraPositionY() + GetVariableFloat(&targetFunction->parameter[0]));
			if (LockCameraPositionY) CameraPositionYLocked = GetCameraPositionY();
		}
		if (targetFunction->nameFull == "Camera.ChangePositionZ" && vaild)
		{
			SetCameraPositionZ(GetCameraPositionZ() + GetVariableFloat(&targetFunction->parameter[0]));
			if (LockCameraPositionZ) CameraPositionZLocked = GetCameraPositionZ();
		}
		if (targetFunction->nameFull == "Camera.LockPosition")
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
		if (targetFunction->nameFull == "Camera.LockPositionX")
		{
			bool triggerX = !LockCameraPositionX;
			if (vaild) triggerX = GetVariableBool(&targetFunction->parameter[0]);
			LockCameraPositionX = triggerX;
			if (triggerX) CameraPositionXLocked = GetCameraPositionX();
		}
		if (targetFunction->nameFull == "Camera.LockPositionY")
		{
			bool triggerY = !LockCameraPositionY;
			if (vaild) triggerY = GetVariableBool(&targetFunction->parameter[0]);
			LockCameraPositionY = triggerY;
			if (triggerY) CameraPositionYLocked = GetCameraPositionY();
		}
		if (targetFunction->nameFull == "Camera.LockPositionZ")
		{
			bool triggerZ = !LockCameraPositionZ;
			if (vaild) triggerZ = GetVariableBool(&targetFunction->parameter[0]);
			LockCameraPositionZ = triggerZ;
			if (triggerZ) CameraPositionZLocked = GetCameraPositionZ();
		}

		if (targetFunction->nameFull == "Camera.SetAngle" && vaild)
		{
			SetCameraAngleX(GetVariableFloat(&targetFunction->parameter[0]));
			SetCameraAngleY(GetVariableFloat(&targetFunction->parameter[1]));
			SetCameraAngleZ(GetVariableFloat(&targetFunction->parameter[2]));
			if (LockCameraAngleX) CameraAngleXLocked = GetCameraAngleX();
			if (LockCameraAngleY) CameraAngleYLocked = GetCameraAngleY();
			if (LockCameraAngleZ) CameraAngleZLocked = GetCameraAngleZ();
		}
		if (targetFunction->nameFull == "Camera.ChangeAngle" && vaild)
		{
			SetCameraAngleX(GetCameraAngleX() + GetVariableFloat(&targetFunction->parameter[0]));
			SetCameraAngleY(GetCameraAngleY() + GetVariableFloat(&targetFunction->parameter[1]));
			SetCameraAngleZ(GetCameraAngleZ() + GetVariableFloat(&targetFunction->parameter[2]));
			if (LockCameraAngleX) CameraAngleXLocked = GetCameraAngleX();
			if (LockCameraAngleY) CameraAngleYLocked = GetCameraAngleY();
			if (LockCameraAngleZ) CameraAngleZLocked = GetCameraAngleZ();
		}
		if (targetFunction->nameFull == "Camera.ChangeAngleX" && vaild)
		{
			SetCameraAngleX(GetCameraAngleX() + GetVariableFloat(&targetFunction->parameter[0]));
			if (LockCameraAngleX) CameraAngleXLocked = GetCameraAngleX();
		}
		if (targetFunction->nameFull == "Camera.ChangeAngleY" && vaild)
		{
			SetCameraAngleY(GetCameraAngleY() + GetVariableFloat(&targetFunction->parameter[0]));
			if (LockCameraAngleY) CameraAngleYLocked = GetCameraAngleY();
		}
		if (targetFunction->nameFull == "Camera.ChangeAngleZ" && vaild)
		{
			SetCameraAngleZ(GetCameraAngleZ() + GetVariableFloat(&targetFunction->parameter[0]));
			if (LockCameraAngleZ) CameraAngleZLocked = GetCameraAngleZ();
		}
		if (targetFunction->nameFull == "Camera.LockAngle")
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
		if (targetFunction->nameFull == "Camera.LockAngleX")
		{
			bool triggerX = !LockCameraAngleX;
			if (vaild) triggerX = GetVariableBool(&targetFunction->parameter[0]);
			LockCameraAngleX = triggerX;
			if (triggerX) CameraAngleXLocked = GetCameraAngleX();
		}
		if (targetFunction->nameFull == "Camera.LockAngleY")
		{
			bool triggerY = !LockCameraAngleY;
			if (vaild) triggerY = GetVariableBool(&targetFunction->parameter[0]);
			LockCameraAngleY = triggerY;
			if (triggerY) CameraAngleYLocked = GetCameraAngleY();
		}
		if (targetFunction->nameFull == "Camera.LockAngleZ")
		{
			bool triggerZ = !LockCameraAngleZ;
			if (vaild) triggerZ = GetVariableBool(&targetFunction->parameter[0]);
			LockCameraAngleZ = triggerZ;
			if (triggerZ) CameraAngleZLocked = GetCameraAngleZ();
		}
		if (targetFunction->nameFull == "Camera.SetZoom" && vaild)
		{
			SetCameraZoom(GetVariableFloat(&targetFunction->parameter[0]));
			if (LockCameraZoom) CameraZoomLocked = GetCameraZoom();
		}
		if (targetFunction->nameFull == "Camera.ChangeZoom" && vaild)
		{
			SetCameraZoom(GetCameraZoom() + GetVariableFloat(&targetFunction->parameter[0]));
			if (LockCameraZoom) CameraZoomLocked = GetCameraZoom();
		}
		if (targetFunction->nameFull == "Camera.LockZoom")
		{
			bool triggerX = !LockCameraZoom;
			if (vaild) triggerX = GetVariableBool(&targetFunction->parameter[0]);
			LockCameraZoom = triggerX;
			if (triggerX) CameraZoomLocked = GetCameraZoom();
		}

	}

	if (IsGameGlobalsInstance())
	{
		if (targetFunction->nameFull == "Objects.SetObjectsCounter" && vaild)
		{
			SetAllObjects(GetVariableInt32(&targetFunction->parameter[0]));
		}
	}

	// Game
	if (targetFunction->nameFull == "Game.SetGamePaused")
	{
		if (vaild) DbgWriteBool(IsGamePausedAddress, GetVariableBool(&targetFunction->parameter[0]));
		else DbgWriteBool(IsGamePausedAddress, !DbgReadBool(IsGamePausedAddress));
	}
	



}


