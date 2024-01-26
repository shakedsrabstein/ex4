//
// Created by spabl on 1/16/2024.
//

#ifndef EX4_MANA_H
#define EX4_MANA_H


#include "Card.h"

///Mana: a card that gives magical energy, only the Healer can use the magic
class Mana : public Card {
public:
    Mana() = default;
    ~Mana() override = default;
    Mana(const Mana&) = default;
    Mana& operator=(const Mana&) = default;
    void applyEncounter(Player &player) override;
    void printDetails(std::ostream &) const override;
    //a getter to the card's name
    string getName() const override{
        return "Mana";
    }
private:
    static const int MANA_HEAL_AMOUNT = 10;
};


#endif //EX4_MANA_H
