#include "PlayerFactory.h"
#include "string"
#include "Player.h"
#include "Players.h"
#include <memory>

using namespace std;

// Map to associate the strings with the enum values
static std::map<std::string, PlayerTypes> s_map_pt_str2enumval;
bool PlayerFactory::initiated = false;

void PlayerFactory::initiateFactory() {

    s_map_pt_str2enumval["Ninja"] = PlayerTypes::PT_Ninga;
    s_map_pt_str2enumval["Warrior"] = PlayerTypes:: PT_Warrior;
    s_map_pt_str2enumval["Healer"] = PlayerTypes::PT_Healer;

    initiated = true;
}


shared_ptr<Player> PlayerFactory::createPlayer(std::string playerJob, std::string playerName) {

    if (!initiated) {
        PlayerFactory::initiateFactory();
    }

    auto it = s_map_pt_str2enumval.find(playerJob);
    if (it == s_map_pt_str2enumval.end()) {
        return nullptr;
    }

    switch (s_map_pt_str2enumval[playerJob]) {
        case PlayerTypes::PT_Ninga:
            return make_shared<Ninja>(playerName);

        case PlayerTypes::PT_Warrior:
            return make_shared<Warrior>(playerName);

        case PlayerTypes::PT_Healer:
            return make_shared<Healer>(playerName);

        default:
            return nullptr;
    }
    // Code should never get here
    // throw DeckFileFormatError();
}

