//
// Created by along on 1/22/2024.
//
#include "Gremlin.h"
#include "Witch.h"
#include "Dragon.h"
#include "Well.h"
#include "Treasure.h"
#include "Barfight.h"
#include "Mana.h"
#include "../Players/Player.h"
#include "../Players/Ninja.h"
#include "../Players/Warrior.h"
#include "Merchant.h"

int main()
{
    Player player("a");
    player.damage(10);
    cout << player.getForce() << endl;
    Merchant merchant;
    merchant.applyEncounter(player);
    cout << player.getForce()<< endl;
    return 0;
}
