//
// Created by spabl on 1/16/2024.
//

#ifndef EX4_WITCH_H
#define EX4_WITCH_H


#include "BattleCard.h"

class Witch : public BattleCard  {
public:
    Witch();
    ~Witch() override = default;
    Witch(const Witch&) = default;
    Witch& operator=(const Witch&) = default;
    void printDetails(std::ostream&);
    void applyEncounter(Player& player) override;
private:
    static const int WITCH_FORCE = 11;
    static const int WITCH_LOOT = 2;
    static const int WITCH_DAMAGE = 10;
    static const int WITCH_POWER_DRAWING = 1;
};


#endif //EX4_WITCH_H
