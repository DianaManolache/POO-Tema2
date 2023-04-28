#ifndef TEMA2_EXCEPTIE_VARSTA_H
#define TEMA2_EXCEPTIE_VARSTA_H

#include <exception>
#include <string>

#include <exception>
#include <string>

class Exceptie_varsta : public std::exception {
public:
    Exceptie_varsta(int varsta);
    virtual const char* what() const throw();

private:
    std::string message;
};

#endif //TEMA2_EXCEPTIE_VARSTA_H
