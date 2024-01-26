//
// Created by spabl on 1/16/2024.
//

#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H


#include "Card.h"

/**Barfight: a card that hurt the player by 8 hp unless he is a ninja*/
class Barfight : public Card {
public:
    Barfight() = default;
    ~Barfight() override = default;
    Barfight(const Barfight&) = default;
    Barfight& operator=(const Barfight&) = default;
    void applyEncounter(Player &player) override;
    void printDetails(std::ostream &) const override;
    string getName() const override{
        return "Barfight";
    }
private:
    static const int BARFIGHT_HEALTH_LOSS = 10;
};


#endif //EX4_BARFIGHT_H
