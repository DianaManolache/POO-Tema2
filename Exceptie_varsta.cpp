#include "Exceptie_varsta.h"

Exceptie_varsta::Exceptie_varsta(int varsta) {
    message = "Varsta pacientului trebuie sa fie mai mare sau egala cu 0. Valoarea data: " + std::to_string(varsta);
}

const char* Exceptie_varsta::what() const throw() {
    return message.c_str();
}