//
// Created by spabl on 1/16/2024.
//

#include "Well.h"
#include "../Players/Ninja.h"


/**applyEncounter: handles the encounter of a player with the well card
 * if he is a ninja nothing will happen
 * otherwise he will lose HealthPoints*/
void Well::applyEncounter(Player& player)
{
    //checking if the player is a ninja
    const Ninja* ninja = dynamic_cast<const Ninja*>(&player);
    bool isNinja = (ninja != nullptr);
    if (!isNinja)
    {
        player.damage(WELL_HEALTH_LOSS);
    }
    //printing the outcome
    printWellMessage(isNinja);

}
