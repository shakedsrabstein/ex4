//
// Created by spabl on 1/16/2024.
//

#include "Gremlin.h"

/**A default constructor for the gremlin
 * assigns in the default stats of a Gremlin*/
Gremlin::Gremlin(): BattleCard(GREMLIN_FORCE, GREMLIN_DAMAGE, GREMLIM_LOOT)
{}

void Gremlin::printDetails(std::ostream& os)
{
    string Name = "Gremlin";
    this->printBattleCardDetails(os, Name, false);
}