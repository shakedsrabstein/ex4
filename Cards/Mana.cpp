//
// Created by spabl on 1/16/2024.
//

#include "Mana.h"
#include "../Players/Healer.h"

/**applyEncounter: handles the player interaction with the Mana card
 * the mana card can heal you but only if you know how to use its mysterious energy
 *
 * @param player the player that interacts with the card*/
void Mana::applyEncounter(Player &player)
{
    bool isHealer = (dynamic_cast<const Healer*>(&player) != nullptr);
    //only a healer knows how to use the magic energy
    if (isHealer)
    {
        player.heal(MANA_HEAL_AMOUNT);
    }
    //printing what happened
    printManaMessage(!isHealer);
}

