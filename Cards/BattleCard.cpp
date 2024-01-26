//
// Created by along on 1/22/2024.
//

#include "BattleCard.h"

void BattleCard::printDetails(std::ostream &os) const
{
    printCardDetails(os, this->getName());
    printMonsterDetails(os, m_force, m_damage, m_loot, this->isDragon());
    printEndOfCardDetails(os);
}

/**applyEncounter: performing a battle between a monster and a player
 *
 * @param player - the player that will fight the monster
 * */
void BattleCard::applyEncounter(Player& player)
{
    //checking who won the fight
    //if the player lost he will lose health
    if (m_force > player.getAttackStrength())
    {
        player.damage(m_damage);
        //printing the battle outcome
        printLossBattle(player.getMName(), this->getName());
    }
    //is the player won he will gain loot and will level up
    else
    {
        player.addCoins(m_loot);
        player.levelUp();
        //printing the battle outcome
        printWinBattle(player.getMName(), this->getName());
    }
}