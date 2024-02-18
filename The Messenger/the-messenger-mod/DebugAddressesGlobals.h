#pragma once

struct DebugAddress {
    std::string nameParent;
    std::string nameChild;
    std::string nameFull;
    std::vector<std::string> description;
    Variable value;
};

struct DebugAddressParent {
    std::string nameParent;
    std::vector<std::string> description;
    std::vector<DebugAddress> addresses;
};

BasePointer PlayerObjectBasepointer;
