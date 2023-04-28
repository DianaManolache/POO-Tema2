#ifndef TEMA2_EXCEPTIE_PRENUME_LITERA_H
#define TEMA2_EXCEPTIE_PRENUME_LITERA_H

#include <exception>
#include <string>

class Exceptie_prenume_litera : public std::exception {
public:
    Exceptie_prenume_litera(const std::string& prenume) : m_prenume(prenume) {}

    virtual const char* what() const throw() {
        return ("Exceptie: " + m_prenume + " nu are cel putin o litera").c_str();
    }

private:
    std::string m_prenume;
};
#endif //TEMA2_EXCEPTIE_PRENUME_LITERA_H
