//
// Created by spabl on 1/16/2024.
//

#include "Treasure.h"

/**printDetails: a function that prints the card's details
 * @param os - the output stream where the print will be executed
 * */
void Treasure::printDetails(std::ostream& os) const
{
    string name = "Treasure";
    printCardDetails(os, name);
    printEndOfCardDetails(os);
}

/**applyEncounter: generate an encounter of a player with the treasure card
 * the player will be granted the amount of coins that are in the treasure chest*/
void Treasure::applyEncounter(Player& player)
{
    player.addCoins(this->getCoinAmount());
    printTreasureMessage();
}
