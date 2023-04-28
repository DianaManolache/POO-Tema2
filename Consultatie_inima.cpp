#include "Consultatie_Inima.h"

int Consultatie_Inima::nr_consultatii = 0;

Consultatie_Inima::Consultatie_Inima()
        : Consultatie(), diagnostic("")
{
}

Consultatie_Inima::Consultatie_Inima(const std::string& numeMedic, const std::string& prenumeMedic,
                                   const std::string& numePacient, const std::string& prenumePacient, int varstaPacient,
                                   const std::string& diag, int nr_cons)
        : Consultatie(numeMedic, prenumeMedic, numePacient, prenumePacient, varstaPacient),
          diagnostic(diag)
{
    nr_consultatii += nr_cons;
}

Consultatie_Inima::Consultatie_Inima(const Consultatie_Inima& c)
        : Consultatie(c), diagnostic(c.diagnostic)
{
}

Consultatie_Inima::~Consultatie_Inima()
{
}

Consultatie_Inima& Consultatie_Inima::operator=(const Consultatie_Inima& c)
{
    if (this != &c) {
        Consultatie::operator=(c);
        diagnostic = c.diagnostic;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Consultatie_Inima& c) {
    if (c.getNumeMedic() == "" || c.getPrenumeMedic() == "" || c.getNumePacient() == "" || c.getPrenumePacient() == "") {
        os << "Nu este initializat\n";
        return os;
    }

    os << "Nume Medic: " << c.getNumeMedic() << '\n' << "Prenume: " << c.getPrenumeMedic() << '\n'
       << "Nume Pacient: " << c.getNumePacient() << '\n' << "Prenume Pacient: " << c.getPrenumePacient() << '\n'
       << "Varsta: " << c.getVarstaPacient() << '\n' << "Diagnostic: " << c.get_diagnostic() <<'\n'<<"Numar total consultatii: "<< Consultatie_Inima::nr_consultatii << '\n';

    return os;
}

bool Consultatie_Inima::operator==(const Consultatie_Inima& c) const
{
    return (Consultatie::operator==(c) && diagnostic == c.diagnostic);
}

bool Consultatie_Inima::operator!=(const Consultatie_Inima& c) const
{
    return !(*this == c);
}

std::string Consultatie_Inima::get_diagnostic() const
{
    return diagnostic;
}

void Consultatie_Inima::set_diagnostic(const std::string& diag)
{
    diagnostic = diag;
}

//int Consultatie_Inima::get_nr_consultatii() const
//{
//    return nr_consultatii;
//}
//
//void Consultatie_Inima::set_nr_consultatii(int nr_cons)
//{
//    nr_consultatii = nr_cons;
//}