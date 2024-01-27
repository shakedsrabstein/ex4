#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H


#include "Card.h"

///Merchant: a card that allow players to buy upgrades
class Merchant : public Card  {
public:
    enum option{DONOTHING = 0, HEALTH_SPELL = 1, FORCE_BOOST = 2};
    Merchant() = default;
    Merchant(const Merchant&) = default;
    Merchant& operator=(const Merchant&) = default;
    void applyEncounter(Player &player) override;
    //a getter to the card's name
    string getName() const override
    {
        return "Merchant";
    }


private:
    static const int HEATH_SPELL_COST  = 5;
    static const int HEALTH_SPELL_HEAL_AMOUNT = 1;
    static const int FORCE_BOOST_COST = 10;
    static const int FORCE_BOOST_BUFF = 1;
    static int getValidMerchantChoice(Player& player);
    static void executeMerchantBuying(Player& player, int choice);
    static int getMerchantCost(int choice);
};


#endif //EX4_MERCHANT_H
