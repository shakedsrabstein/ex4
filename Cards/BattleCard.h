//
// Created by along on 1/21/2024.
//

#ifndef EX4_BATTLECARD_H
#define EX4_BATTLECARD_H

#include "Card.h"


class BattleCard : public Card{
public:
    BattleCard(int force, int damage, int loot): m_force(force), m_damage(damage), m_loot(loot) {}
    BattleCard(const BattleCard&) = default;
    virtual ~BattleCard() = default;
    void printBattleCardDetails(std::ostream&, const string& name, bool isDragon) const;
    void applyEncounter(Player& player) override;
protected:
    int m_force;
    int m_damage;
    int m_loot;
};

#endif //EX4_BATTLECARD_H
