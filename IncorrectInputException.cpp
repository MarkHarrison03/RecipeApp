#include "IncorrectInputException.h"
#include "incorrectinputexceptionwindow.h"
char* IncorrectInputException::what(){
    IncorrectInputExceptionWindow *a = new IncorrectInputExceptionWindow;
    a->show();

    char* arr = "Incorrect Input.";
    return arr;
}
