#include "string"
#include "Card.h"
#include "Dragon.h"
#include "Barfight.h"
#include "Mana.h"
#include "Gremlin.h"
#include "Merchant.h"
#include "Well.h"
#include "Treasure.h"
#include "Witch.h"

#include "CardFactory.h"

// Map to associate the strings with the enum values
static std::map<std::string, CardNames> s_mapstr2enumval;
bool CardFactory::initiated = false;

void CardFactory::initiateFactory() {
    s_mapstr2enumval["Dragon"] = CardNames::CN_Dragon;
    s_mapstr2enumval["Barfight"] = CardNames::CN_Barfight;
    s_mapstr2enumval["Mana"] = CardNames::CN_Mana;
    s_mapstr2enumval["Gremlin"] = CardNames::CN_Gremlin;
    s_mapstr2enumval["Merchant"] = CardNames::CN_Merchant;
    s_mapstr2enumval["Well"] = CardNames::CN_Well;
    s_mapstr2enumval["Treasure"] = CardNames::CN_Treasure;
    s_mapstr2enumval["Witch"] = CardNames::CN_Witch;
    CardFactory::initiated = true;

}



Card* CardFactory::createCard(std::string cardStr) {

    if (!initiated) {
        CardFactory::initiateFactory();
    }

    auto it = s_mapstr2enumval.find(cardStr);
    if (it == s_mapstr2enumval.end()) {
        throw DeckFileFormatError();
    }

    switch (s_mapstr2enumval[cardStr]) {
        case CardNames::CN_Dragon:
            return new Dragon();

        case CardNames::CN_Barfight:
            return new Barfight();

        case CardNames::CN_Mana:
            return new Mana();

        case CardNames::CN_Gremlin:
            return new Gremlin();

        case CardNames::CN_Merchant:
            return new Merchant();

        case CardNames::CN_Well:
            return new Well();

        case CardNames::CN_Treasure:
            return new Treasure();

        case CardNames::CN_Witch:
            return new Witch();

        default:
            throw DeckFileFormatError();
    }
    // Code should never get here
    // throw DeckFileFormatError();
}
