#include "PlayerFactory.h"

#include "string"
#include "Player.h"
#include "Players.h"


PlayerFactory::PlayerFactory() {

    s_map_pt_str2enumval["Ninja"] = PlayerTypes::PT_Ninga;
    s_map_pt_str2enumval["Warrior"] = PlayerTypes:: PT_Warrior;
    s_map_pt_str2enumval["Healer"] = PlayerTypes::PT_Healer;

}



Player* PlayerFactory::createPlayer(std::string playerJob, std::string playerName) {

    switch (s_map_pt_str2enumval[playerJob]) {
        case PlayerTypes::PT_Ninga:
            return new Ninja(playerName);

        case PlayerTypes::PT_Warrior:
            return new Warrior(playerName);

        case PlayerTypes::PT_Healer:
            return new Healer(playerName);

        default:
            return nullptr;
    }
    // Code should never get here
    // throw DeckFileFormatError();
}

