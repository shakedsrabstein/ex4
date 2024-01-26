//
// Created by spabl on 1/16/2024.
//

#ifndef EX4_WELL_H
#define EX4_WELL_H


#include "Card.h"

/**Well Card: when encountering a player will lose 10 health points unless he is a ninja*/
class Well : public Card  {
public:
    Well() = default;
    ~Well() = default;
    Well(const Well&) = default;
    Well& operator=(const Well&) = default;
    void printDetails(ostream& os) const override;
    void applyEncounter(Player& player) override;
    //a getter to the card's name (Well)
    string getName() const override{
        return "Well";
    }
private:
    static const int WELL_HEALTH_LOSS = 10;
};


#endif //EX4_WELL_H
