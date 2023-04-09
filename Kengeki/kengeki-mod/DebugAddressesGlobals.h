#pragma once

struct DebugAddress {
    std::string nameParent;
    std::string nameChild;
    std::string nameFull;
    Variable value;
};

struct DebugAddressParent {
    std::string nameParent;
    std::vector<DebugAddress> addresses;
};

BasePointer PlayerPositionX;
BasePointer PlayerPositionY;
BasePointer PlayerPositionZ;
BasePointer PlayerHP;
BasePointer PlayerMana;

BasePointer BossHP;

