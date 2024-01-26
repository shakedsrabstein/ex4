//
// Created by spabl on 1/16/2024.
//

#include <stdexcept>

#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H

class DeckFileInvalidSize : public std::exception{



};

class DeckFileNotFound : public std::exception{

};

class DeckFileFormatError : public std::exception{

};

#endif //EX4_EXCEPTION_H
