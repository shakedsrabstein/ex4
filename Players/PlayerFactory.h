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


class PlayerFactory {

    static bool initiated;

public:

    static void initiateFactory();
    static Player* createPlayer(string playerJob, string playerName);

};




//#endif //EX4_PLAYERFACTORY_H
