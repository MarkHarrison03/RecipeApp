#ifndef INCORRECTINPUTEXCEPTION_H
#define INCORRECTINPUTEXCEPTION_H
#include <iostream>
//programmer defined exception
class IncorrectInputException : public std::exception{
    public:
    char* what();

};

#endif // INCORRECTINPUTEXCEPTION_H
