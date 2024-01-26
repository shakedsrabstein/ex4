//
// Created by spabl on 1/16/2024.
//

#include "Merchant.h"

void Merchant::applyEncounter(Player &player)
{
    printMerchantInitialMessageForInteractiveEncounter(cout, player.getMName(), player.getMCoins());
    int choice = getValidMerchantChoice(player);
    executeMerchantBuying(player, choice);
}

/**getValidMerchantChoice: this function reads the player choice and wont stop until he gets a valid one
 *
 * @param player - the player that encounter the merchant
 * @returns the choice*/
int Merchant::getValidMerchantChoice(Player& player)
{
    bool isValid = false;
    string input;
    int choice;
    while (!isValid)
    {
        isValid = true;
        //trying to read the choice
        getline(cin, input);
        try {
            choice = stoi(input);
        }
        catch (exception& e){
            isValid = false;
            printInvalidInput();
            continue;
        }
        if (choice < 0 || choice > 2){
            isValid = false;
            printInvalidInput();
            continue;
        }
        if (getMerchantCost(choice) > player.getMCoins()){
            printMerchantInsufficientCoins(cout);
            isValid = false;
            continue;
        }
    }
    return choice;
}

/**executeMerchantBuying: perform the transaction of the purchase and printing the outcome
 *
 * @param player - the player that encounter the merchant
 * @param choice - the player chosen product*/
void Merchant::executeMerchantBuying(Player& player, int choice)
{
    switch (choice) {
        case DONOTHING:
            break;
        case HEALTH_SPELL:
            player.heal(HEALTH_SPELL_HEAL_AMOUNT);
            break;
        case FORCE_BOOST:
            player.buff(FORCE_BOOST_BUFF);
            break;
        //should never get here
        default:
            break;
    }
    player.pay(getMerchantCost(choice));
    printMerchantSummary(cout, player.getMName(), choice, getMerchantCost(choice));
}



/**getMerchantCost: calculate the cost of a product in the merchant according to the given choice
 *
 * @param choice - the chosen product
 * @return how much the product costs
 * */
int Merchant::getMerchantCost(int choice)
{
    if (choice == Merchant::DONOTHING){
        return 0;
    }
    if (choice == HEALTH_SPELL){
        return HEATH_SPELL_COST;
    }
    if (choice == FORCE_BOOST){
        return FORCE_BOOST_COST;
    }
    return -1;
}
