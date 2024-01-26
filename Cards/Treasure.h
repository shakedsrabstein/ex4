//
// Created by spabl on 1/16/2024.
//

#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H


#include "Card.h"

class Treasure : public Card  {
public:
    explicit Treasure(int coinsAmount = TREASURE_DEF_COIN_AMOUNT): m_coinAmount(coinsAmount) {};
    ~Treasure() = default;
    Treasure(const Treasure&) = default;
    Treasure& operator=(const Treasure&) = default;
    void applyEncounter(Player& player) override;
    //a getter to the coin amount in the treasure chest
    int getCoinAmount() const
    {
        return m_coinAmount;
    }
    //A getter to the Card's name (Treasure)
    string getName() const override{
        return "Treasure";
    }
private:
    static const int TREASURE_DEF_COIN_AMOUNT = 10;
    int m_coinAmount;
};


#endif //EX4_TREASURE_H
