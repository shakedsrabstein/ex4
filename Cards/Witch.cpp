//
// Created by spabl on 1/16/2024.
//

#include "Witch.h"

/**A default constructor for witch*/
Witch::Witch(): BattleCard(WITCH_FORCE, WITCH_DAMAGE, WITCH_LOOT)
{}


/**applyEncounter: perform a fight with a witch
 * except the normal fighting rules when you lose to a witch you lose one power unit
 *
 * @param player - the player that fights the witch*/
void Witch::applyEncounter(Player& player)
{
    //if the player has lost the fight his will lose a power unit
    if (player.getAttackStrength() < m_force)
    {
        if(player.getForce() - WITCH_POWER_DRAWING >= 0){
            player.setForce(player.getForce() - WITCH_POWER_DRAWING);
        }

    }
    this->applyBattleCardEncounter(player);
    //its not a problem doing this after we reduced from the player's force - if he loosed he will lose now anyway
    //card->applyEncounter(player);


}
