#ifndef INCORRECTINPUTEXCEPTION_H
#define INCORRECTINPUTEXCEPTION_H
#include <iostream>
class IncorrectInputException : public std::exception{
    public:
    char* what();

};

#endif // INCORRECTINPUTEXCEPTION_H
