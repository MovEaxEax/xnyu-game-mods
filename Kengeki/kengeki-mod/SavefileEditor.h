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



EXTERN_DLL_EXPORT void __cdecl GetSavefiles(char* saveFiles)
{
    //
    // This function returns identifier for all the available savefiles
    //

    std::string file = AppdataRoamingPath + "AnnkakeSpa\\Kengeki\\save.dat";

    if (file.length() > 0)
    {
        pDebugConsoleOutput(file, false, "purple");
        std::memcpy(saveFiles, file.c_str(), file.length());
        char term = 0x00;
        std::memcpy(saveFiles + file.length(), &term, 1);
    }
}

EXTERN_DLL_EXPORT void ScopeSavefile(std::string filename)
{

    //
    // before savefile data get's manipulated, the scoped file get's selected
    // 

}

EXTERN_DLL_EXPORT void LoadSavefile(SavefileParent* savefileParent)
{

    //
    // This function returns the current data of the savefile
    // It can be called multiple times, after reloading
    // 

}

EXTERN_DLL_EXPORT void SaveSavefile(SavefileParent* savefileParent)
{

    //
    // This function takes the new savefile data from a single parent and saves it
    // 

}


