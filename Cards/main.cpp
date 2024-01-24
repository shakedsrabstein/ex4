//
// Created by along on 1/22/2024.
//
#include "Gremlin.h"
#include "Witch.h"
#include "Dragon.h"

int main()
{
    Gremlin gremlin;
    gremlin.printDetails(std::cout);
    Witch witch;
    witch.printDetails(std::cout);
    Dragon dragon;
    dragon.printDetails(std::cerr);
    std::cerr << "test";
    return 0;
}
