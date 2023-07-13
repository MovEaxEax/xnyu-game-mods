#pragma once

std::vector<FeatureSettingParent> editorModeSettings;

EXTERN_DLL_EXPORT void InitEditorModeSettings(const std::vector<FeatureSettingParent>& settingParent)
{

    //
    // Take the initial loaded settings from the file
    //

    editorModeSettings = settingParent;
}

EXTERN_DLL_EXPORT void GetEditorModeSettings(FeatureSettingParent* settingParent)
{

    //
    // Write the current settings into the pointer
    //

}

EXTERN_DLL_EXPORT void UpdateEditorModeSettings(FeatureSettingParent* settingParent)
{

    //
    // Take the settings and update them for this mod
    //

}

EXTERN_DLL_EXPORT void ToggleEditorModeRoutine(bool isEnabled)
{

    //
    // Routine for editormode
    // 

}


