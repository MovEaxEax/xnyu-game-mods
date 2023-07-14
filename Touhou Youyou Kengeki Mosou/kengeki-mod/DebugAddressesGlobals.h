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

BasePointer PlayerObjectBasepointer;
BasePointer CameraObjectBasepointer;
BasePointer GameGlobalsBasepointer;
BasePointer BossObjectBasepointer;

void* IsGamePausedAddress;
