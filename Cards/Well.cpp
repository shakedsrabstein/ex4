//
// Created by spabl on 1/16/2024.
//

#include "Well.h"
#include "../Players/Ninja.h"

/**printDetails: prints the details of the well card
 * @param os - the output stream*/
void Well::printDetails(ostream& os) const
{
    printCardDetails(os, this->getName());
    printEndOfCardDetails(os);
}

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
