//#ifndef EX4_PLAYERFACTORY_H
//#define EX4_PLAYERFACTORY_H

#include <map>
#include <string>
#include "Player.h"

// Value-Defintions of the different String values

enum PlayerTypes {
    PT_Ninga ,
    PT_Warrior,
    PT_Healer
};

// Map to associate the strings with the enum values
static std::map<std::string, PlayerTypes> s_map_pt_str2enumval;

class PlayerFactory {

public:

    PlayerFactory();
    static Player* createPlayer(string playerJob, string playerName);

};




//#endif //EX4_PLAYERFACTORY_H
