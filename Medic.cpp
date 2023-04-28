#include "Medic.h"

//constructor initializare
Medic::Medic() {
    numeMedic = "";
    prenumeMedic = "";
}

//constructor initializare cu parametri
Medic::Medic(const std::string& nume, const std::string& prenume)
        : numeMedic(nume), prenumeMedic(prenume) {}

//constructor de copiere
Medic::Medic(const Medic& medic)
        : numeMedic(medic.numeMedic), prenumeMedic(medic.prenumeMedic) {}

//destructor
Medic::~Medic() {}

//operatorul =
Medic& Medic::operator=(const Medic& medic) {
    if (this != &medic) {
        numeMedic = medic.numeMedic;
        prenumeMedic = medic.prenumeMedic;
    }
    return *this;
}


//operatorul ==
bool Medic::operator==(const Medic& medic) const {
    return numeMedic == medic.numeMedic && prenumeMedic == medic.prenumeMedic;
}

std::ostream& operator<<(std::ostream& os, const Medic& medic) {
    if (medic.getNumeMedic() == "" || medic.getPrenumeMedic() == "") {
        os << "Nu este initializat\n";
        return os;
    }

    os << "Nume Medic: " << medic.numeMedic << '\n' << "Prenume: " << medic.getPrenumeMedic() << '\n';

    return os;
}

//operatorul !=
bool Medic::operator!=(const Medic& medic) const {
    return !(*this == medic);
}

std::string Medic::getNumeMedic() const {
    return numeMedic;
}

void Medic::setNumeMedic(const std::string& nume) {
    numeMedic = nume;
}

std::string Medic::getPrenumeMedic() const {
    return prenumeMedic;
}

void Medic::setPrenumeMedic(const std::string& prenume) {
    prenumeMedic = prenume;
}