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

bool GodmodeInit = true;
DebugAddress GodModeHPAddress = DebugAddress();
DebugAddress GodModeMPAddress = DebugAddress();

EXTERN_DLL_EXPORT void ExecuteDebugFunction(DebugFunction* targetFunction)
{
    if (targetFunction->nameFull == "Hacks.Godmode")
    {
        if (GodmodeInit)
        {

        }

        GodmodeInit = !GodmodeInit;
    }

}


