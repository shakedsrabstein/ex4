cmake_minimum_required(VERSION 3.21)
project(ex4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex4
        Mtmchkin.h
        Mtmchkin.cpp
        Players/Player.cpp
        Players/Player.h
        test.cpp
        utilities.cpp
        utilities.h
        Exception.h
        Cards/Card.h
        Cards/Card.cpp
        Cards/BattleCard.h
        Cards/BattleCard.cpp
        Cards/Barfight.cpp
        Cards/Barfight.h
        Cards/Dragon.cpp
        Cards/Dragon.h
        Cards/Mana.cpp
        Cards/Mana.h
        Cards/Gremlin.cpp
        Cards/Gremlin.h
        Cards/Merchant.cpp
        Cards/Merchant.h
        Cards/Well.cpp
        Cards/Well.h
        Cards/Treasure.cpp
        Cards/Treasure.h
        Cards/Witch.cpp
        Cards/Witch.h
        Players/Ninja.cpp
        Players/Ninja.h
        Players/Warrior.cpp
        Players/Warrior.h
        Players/Healer.cpp
        Players/Healer.h
        Players/Leaderboard.cpp
        Players/Leaderboard.h Cards/CardFactory.cpp Cards/CardFactory.h Players/PlayerFactory.cpp Players/PlayerFactory.h Players/Players.h)
