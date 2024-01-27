#ifndef  EX4_DRAGON_H
#define  EX4_DRAGON_H

#include "BattleCard.h"

class Dragon: public BattleCard {
public:
    Dragon();
    ~Dragon() override = default;
    Dragon(const Dragon&) = default;
    Dragon& operator=(const Dragon&) = default;
    virtual string getName() const override {
        return "Dragon";
    }
private:
    static const int DRAGON_FORCE = 25;
    static const int DRAGON_LOOT = 1000;
};


#endif //EX4_DRAGON_H
