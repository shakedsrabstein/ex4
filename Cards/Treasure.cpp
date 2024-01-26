//
// Created by spabl on 1/16/2024.
//

#include "Treasure.h"


/**applyEncounter: generate an encounter of a player with the treasure card
 * the player will be granted the amount of coins that are in the treasure chest*/
void Treasure::applyEncounter(Player& player)
{
    player.addCoins(this->getCoinAmount());
    printTreasureMessage();
}
