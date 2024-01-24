//
// Created by spabl on 1/16/2024.
//

#include "Dragon.h"

/**Default constructor to the dragon*/
Dragon::Dragon(): BattleCard(DRAGON_FORCE, INT_MAX, 1000)
{}

/**printDetails: prints the details/stats of the dragon card
 *
 * @param os - the output stream
 * */
void Dragon::printDetails(std::ostream &os)
{
    string name = "Dragon";
    this->printBattleCardDetails(os, name, true);
}

/**applyEnounter: perform a battle between a player and a dragon
 *
 * @param player - the brave player to fight the dragon*/
void Dragon::applyEncounter(Player &player)
{
    //checking who win the battle
    if (m_force > player.getAttackStrength())
    {
        //if the player lost he would be burned alive
        player.setHp(0);
    }
    else
    {
        //if he won he will gain the dragon's fortune
        BattleCard* card = this;
        card->applyEncounter(player);
    }
}