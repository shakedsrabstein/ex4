//
// Created by spabl on 1/16/2024.
//

#include "Barfight.h"
#include "../Players/Warrior.h"

/**Handles the encounter of a player with a Barfight
 * the player will win only if he is a warrior
 * if he losses he will be hurt
 *
 * @param player - the player that will encounter the card*/
void Barfight::applyEncounter(Player &player)
{
    //checking if the player is a warrior
    bool isWarrior = (dynamic_cast<Warrior*>(&player) != nullptr);
    //unless he is a warrior he will lose the fight and get hurt
    if(!isWarrior)
    {
        player.damage(BARFIGHT_HEALTH_LOSS);
    }
    //printing the fight result
    printBarfightMessage(isWarrior);
}

/**printDetails: printing the Barfight details
 *
 * @param os - the output stream where the print will be executed*/
void Barfight::printDetails(std::ostream &os) const
{
    printCardDetails(os, this->getName());
    printEndOfCardDetails(os);
}