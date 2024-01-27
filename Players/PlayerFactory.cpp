#include "PlayerFactory.h"

#include "string"
#include "Player.h"


PlayerFactory::PlayerFactory() {
    s_map_pt_str2enumval["Ninja"] = PlayerTypes::PT_Ninga;

}



Player* PlayerFactory::createPlayer(std::string playerStr) {

    switch (s_map_pt_str2enumval[playerStr]) {
        case PlayerTypes::PT_Ninga:
            return nullptr;

        default:
            return nullptr;
    }
    // Code should never get here
    // throw DeckFileFormatError();
}

