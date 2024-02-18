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

std::string scopedFile;

EXTERN_DLL_EXPORT void __cdecl GetSavefiles(char* saveFilesBuffer)
{
    //
    // This function returns identifier for all the available savefiles
    //

}

EXTERN_DLL_EXPORT void __cdecl ScopeSavefile(std::string filename)
{

    //
    // before savefile data get's manipulated, the scoped file get's selected
    // 

}

EXTERN_DLL_EXPORT void __cdecl LoadSavefile(SavefileParent* savefileParent)
{

    //
    // This function returns the current data of the savefile
    // It can be called multiple times, after reloading
    // 

}

EXTERN_DLL_EXPORT void __cdecl UpdateSavefile(SavefileParent* savefileParent)
{

    //
    // This function takes the new savefile data from a single parent and saves it
    // 

}


