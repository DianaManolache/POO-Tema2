#include "Consultatie.h"

Consultatie::Consultatie() : Medic() {
    numePacient = "";
    prenumePacient = "";
    varstaPacient = 0;
}

Consultatie::Consultatie(const std::string& numeMedic, const std::string& prenumeMedic, const std::string& numePacient, const std::string& prenumePacient, int varstaPacient)
        : Medic(numeMedic, prenumeMedic), numePacient(numePacient), prenumePacient(prenumePacient), varstaPacient(varstaPacient) {}

Consultatie::Consultatie(const Consultatie& consultatie)
        : Medic(consultatie), numePacient(consultatie.numePacient), prenumePacient(consultatie.prenumePacient), varstaPacient(consultatie.varstaPacient) {}

Consultatie::~Consultatie() {}

Consultatie& Consultatie::operator=(const Consultatie& consultatie) {
    if (this != &consultatie) {
        Medic::operator=(consultatie);
        numePacient = consultatie.numePacient;
        prenumePacient = consultatie.prenumePacient;
        varstaPacient = consultatie.varstaPacient;
    }
    return *this;
}


bool Consultatie::operator==(const Consultatie& consultatie) const {
    return static_cast<const Medic&>(*this) == static_cast<const Medic&>(consultatie) &&
           numePacient == consultatie.numePacient && prenumePacient == consultatie.prenumePacient &&
           varstaPacient == consultatie.varstaPacient;
}

bool Consultatie::operator!=(const Consultatie& c) const {
    return !(*this == c);
}

std::ostream& operator<<(std::ostream& os, const Consultatie& c) {
    if (c.getNumeMedic() == "" || c.getPrenumeMedic() == "" || c.getNumePacient() == "" || c.getPrenumePacient() == "") {
        os << "Nu este initializat\n";
        return os;
    }

    os << "Nume Medic: " << c.getNumeMedic() << '\n' << "Prenume: " << c.getPrenumeMedic() << '\n'
       << "Nume Pacient: " << c.getNumePacient() << '\n' << "Prenume Pacient: " << c.getPrenumePacient() << '\n'
       << "Varsta: " << c.getVarstaPacient() << '\n';

    return os;
}

std::string Consultatie::getNumePacient() const {
    return numePacient;
}

void Consultatie::setNumePacient(const std::string& nume) {
    numePacient = nume;
}

std::string Consultatie::getPrenumePacient() const {
    return prenumePacient;
}

void Consultatie::setPrenumePacient(const std::string& prenume) {
    prenumePacient = prenume;
}

int Consultatie::getVarstaPacient() const {
    return varstaPacient;
}

void Consultatie::setVarstaPacient(int varsta) {
    varstaPacient = varsta;
}

int Consultatie::nr_consultatii = 0;

void Consultatie::adaugaConsultatie() {
    nr_consultatii++;
}