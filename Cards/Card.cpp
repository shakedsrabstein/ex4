#include "Card.h"



/**printDetails: print the merchant card details
* @param os - the output stream*/
void Card::printDetails(std::ostream &os) const
{
    printCardDetails(os, this->getName());
    printEndOfCardDetails(os);
}

