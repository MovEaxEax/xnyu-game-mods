#pragma once

std::vector<FeatureSettingParent> superVisionSettings;

EXTERN_DLL_EXPORT void InitSupervisionSettings(const std::vector<FeatureSettingParent>& settingParent)
{

    //
    // Take the initial loaded settings from the file
    //

    superVisionSettings = settingParent;
}

EXTERN_DLL_EXPORT void GetSupervisionSettings(FeatureSettingParent* settingParent)
{

    //
    // Write the current settings into the pointer
    //

}

EXTERN_DLL_EXPORT void UpdateSupervisionSettings(FeatureSettingParent* settingParent)
{

    //
    // Take the settings and update them for this mod
    //

}

EXTERN_DLL_EXPORT void ToggleSupervisionRoutine(bool isEnabled)
{

    //
    // Routine for supervision
    // 

}


