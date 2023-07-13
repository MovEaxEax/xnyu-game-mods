#pragma once

struct SavefileField {
    std::string nameParent;
    std::string nameChild;
    std::string nameFull;
    Variable value;
};

struct SavefileParent {
    std::string nameParent;
    std::vector<SavefileField> fields;
};

SavefileV1 savefileV1;
SavefileV2 savefileV2;
std::string scopedFile;

EXTERN_DLL_EXPORT void __cdecl GetSavefiles(char* saveFilesBuffer)
{
    //
    // This function returns identifier for all the available savefiles
    //

    //std::string file = AppdataRoamingPath + "AnnkakeSpa\\Kengeki\\save.dat";
    std::string file = "save.dat";

    if (file.length() > 0)
    {
        pDebugConsoleOutput(file, true, "purple");
        std::memcpy(saveFilesBuffer, file.c_str(), file.length());
        char term = 0x00;
        std::memcpy(saveFilesBuffer + file.length(), &term, 1);
    }
}

EXTERN_DLL_EXPORT void __cdecl ScopeSavefile(std::string filename)
{

    //
    // before savefile data get's manipulated, the scoped file get's selected
    // 

    savefileV1 = SavefileV1();
    scopedFile = AppdataRoamingPath + "AnnkakeSpa\\Kengeki\\" + filename;
    std::ifstream  dataFile(scopedFile);
    if (dataFile.is_open()) {
        char* fileBuffer = (char*) malloc(sizeof(savefileV1));
        dataFile.read(fileBuffer, sizeof(savefileV1));
        dataFile.close();
        for (int i = 0; i < sizeof(savefileV1); i++) fileBuffer[i] = fileBuffer[i] ^ 0x46;
        std::memcpy(&savefileV1, fileBuffer, sizeof(savefileV1));
        free(fileBuffer);
    }
}

EXTERN_DLL_EXPORT void __cdecl LoadSavefile(SavefileParent* savefileParent)
{

    //
    // This function returns the current data of the savefile
    // It can be called multiple times, after reloading
    // 

    for (int i = 0; i < savefileParent->fields.size(); i++)
    {
        if (savefileParent->fields[i].nameChild == "Score") SetVariable(&savefileParent->fields[i].value, savefileV1.score);
        else if (savefileParent->fields[i].nameChild == "ScoreLap") SetVariable(&savefileParent->fields[i].value, savefileV1.scoreLap);
        else if (savefileParent->fields[i].nameChild == "MissionID") SetVariable(&savefileParent->fields[i].value, savefileV1.missionID);
        else if (savefileParent->fields[i].nameChild == "MaxHits") SetVariable(&savefileParent->fields[i].value, savefileV1.maxHits);
        else if (savefileParent->fields[i].nameChild == "Relicts") SetVariable(&savefileParent->fields[i].value, savefileV1.relicts);
        else if (savefileParent->fields[i].nameChild == "DamageDealt") SetVariable(&savefileParent->fields[i].value, savefileV1.damageDealt);
        else if (savefileParent->fields[i].nameChild == "DamageReceived") SetVariable(&savefileParent->fields[i].value, savefileV1.damageReceived);
        else if (savefileParent->fields[i].nameChild == "Deaths") SetVariable(&savefileParent->fields[i].value, savefileV1.deaths);
        else if (savefileParent->fields[i].nameChild == "EnemiesKilled") SetVariable(&savefileParent->fields[i].value, savefileV1.enemiesKilled);
        else if (savefileParent->fields[i].nameChild == "Falls") SetVariable(&savefileParent->fields[i].value, savefileV1.falls);
        else if (savefileParent->fields[i].nameChild == "BrokenUrns") SetVariable(&savefileParent->fields[i].value, savefileV1.brokenUrns);
        else if (savefileParent->fields[i].nameChild == "Level") SetVariable(&savefileParent->fields[i].value, savefileV1.level);
    }
}

EXTERN_DLL_EXPORT void __cdecl UpdateSavefile(SavefileParent* savefileParent)
{

    //
    // This function takes the new savefile data from a single parent and saves it
    // 

    for (int i = 0; i < savefileParent->fields.size(); i++)
    {
        if (savefileParent->fields[i].nameChild == "Score") savefileV1.score = GetVariableInt32(&savefileParent->fields[i].value);
        else if (savefileParent->fields[i].nameChild == "ScoreLap") savefileV1.scoreLap = GetVariableInt32(&savefileParent->fields[i].value);
        else if (savefileParent->fields[i].nameChild == "MissionID") savefileV1.missionID = GetVariableInt32(&savefileParent->fields[i].value);
        else if (savefileParent->fields[i].nameChild == "MaxHits") savefileV1.maxHits = GetVariableInt32(&savefileParent->fields[i].value);
        else if (savefileParent->fields[i].nameChild == "Relicts") savefileV1.relicts = GetVariableInt32(&savefileParent->fields[i].value);
        else if (savefileParent->fields[i].nameChild == "DamageDealt") savefileV1.damageDealt = GetVariableInt32(&savefileParent->fields[i].value);
        else if (savefileParent->fields[i].nameChild == "DamageReceived") savefileV1.damageReceived = GetVariableInt32(&savefileParent->fields[i].value);
        else if (savefileParent->fields[i].nameChild == "Deaths") savefileV1.deaths = GetVariableInt32(&savefileParent->fields[i].value);
        else if (savefileParent->fields[i].nameChild == "EnemiesKilled") savefileV1.enemiesKilled = GetVariableInt32(&savefileParent->fields[i].value);
        else if (savefileParent->fields[i].nameChild == "Falls") savefileV1.falls = GetVariableInt32(&savefileParent->fields[i].value);
        else if (savefileParent->fields[i].nameChild == "BrokenUrns") savefileV1.brokenUrns = GetVariableInt32(&savefileParent->fields[i].value);
        else if (savefileParent->fields[i].nameChild == "Level") savefileV1.level = GetVariableInt32(&savefileParent->fields[i].value);
    }

    char* fileBuffer = (char*)malloc(sizeof(savefileV1));
    std::memcpy(fileBuffer, &savefileV1, sizeof(savefileV1));
    for (int i = 0; i < sizeof(savefileV1); i++) fileBuffer[i] = fileBuffer[i] ^ 0x46;
    std::fstream dataFile(scopedFile, std::ios::in | std::ios::out | std::ios::binary);
    dataFile.write(fileBuffer, sizeof(savefileV1));
    dataFile.close();
    free(fileBuffer);
}


