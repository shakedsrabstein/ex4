#ifndef EX4_BATTLECARD_H
#define EX4_BATTLECARD_H

#include "Card.h"


class BattleCard : public Card {
public:
    BattleCard(int force, int damage, int loot): m_force(force), m_damage(damage), m_loot(loot) {}
    BattleCard(const BattleCard&) = default;
    virtual ~BattleCard() = default;
    virtual void applyEncounter(Player& player) override;
    virtual string getName() const = 0;
    //a method that checks if the card is a dragon card
    bool isDragon() const {
        return (this->getName() == "Dragon");
    }
protected:
    int m_force;
    int m_damage;
    int m_loot;
};

#endif // EX4_BATTLECARD_H

