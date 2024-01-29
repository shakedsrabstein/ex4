#include "Dragon.h"
#include "limits.h"

/**Default constructor to the dragon*/
Dragon::Dragon(): BattleCard(DRAGON_FORCE, INT_MAX, 1000)
{}

/**printDetails: prints the details/stats of the dragon card
 *
 * @param os - the output stream
 * */

void Dragon::applyEncounter(Player &player)
{
    applyBattleCardEncounter(player);
}
