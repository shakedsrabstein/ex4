CC = g++
CFLAGS = -std=c++11

SRCDIR = .
SRC = $(SRCDIR)/Mtmchkin.cpp \
      $(SRCDIR)/Players/Player.cpp \
      $(SRCDIR)/utilities.cpp \
      $(SRCDIR)/Exception.h \
      $(SRCDIR)/Cards/Card.cpp \
      $(SRCDIR)/Cards/BattleCard.cpp \
      $(SRCDIR)/Cards/Barfight.cpp \
      $(SRCDIR)/Cards/Dragon.cpp \
      $(SRCDIR)/Cards/Mana.cpp \
      $(SRCDIR)/Cards/Gremlin.cpp \
      $(SRCDIR)/Cards/Merchant.cpp \
      $(SRCDIR)/Cards/Well.cpp \
      $(SRCDIR)/Cards/Treasure.cpp \
      $(SRCDIR)/Cards/Witch.cpp \
      $(SRCDIR)/Players/Ninja.cpp \
      $(SRCDIR)/Players/Warrior.cpp \
      $(SRCDIR)/Players/Healer.cpp \
      $(SRCDIR)/Players/Leaderboard.cpp \
      $(SRCDIR)/Cards/CardFactory.cpp \
      $(SRCDIR)/Players/PlayerFactory.cpp \
      $(SRCDIR)/fileTests/testsMain.cpp

INC = -I.

EXEC = FileTester

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $(EXEC) $(SRC) $(INC)

clean:
	rm -f $(EXEC)
