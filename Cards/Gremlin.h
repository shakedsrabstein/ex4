#ifndef EX4_GREMLIN_H
#define EX4_GREMLIN_H


#include "Card.h"
#include "BattleCard.h"

class Gremlin  : public BattleCard  {
public:
    Gremlin();
    ~Gremlin() override = default;
    Gremlin(const Gremlin&) = default;
    Gremlin& operator=(const Gremlin&) = default;
    //a getter to the monster's name
    string getName() const override {
        return "Gremlin";
    }
private:
    static const int GREMLIN_FORCE = 5;
    static const int GREMLIN_LOOT = 2;
    static const int GREMLIN_DAMAGE = 10;
};


#endif //EX4_GREMLIN_H
