#include <stdexcept>
#include "string"
#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H

class MtmchkinBaseException : public std::exception {

public:

    MtmchkinBaseException() = default;

    // Override the what() function to provide a description of the exception
    const char* what() const noexcept override {
        return errorMessage.c_str();
    }
protected:
    std::string errorMessage;
};


class DeckFileInvalidSize : public MtmchkinBaseException {

public:
    // Constructor that takes a custom error message
    DeckFileInvalidSize() { errorMessage = "Deck File Error: Deck size is invalid"; }
};


class DeckFileNotFound: public MtmchkinBaseException {
public:
    // Constructor that takes a custom error message
    DeckFileNotFound() { errorMessage = "Deck File Error: File not found"; }

};

class DeckFileFormatError : public MtmchkinBaseException{

public:
    DeckFileFormatError() = default;

    // Constructor that takes a custom error message
    DeckFileFormatError(int lineNumber) {

       errorMessage = "Deck File Error: File format error in line " +std::to_string(lineNumber) ;
    }

};

#endif //EX4_EXCEPTION_H
