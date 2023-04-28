#ifndef TEMA2_CONSULTATIE_H
#define TEMA2_CONSULTATIE_H

#include <string>
#include "Medic.h"

class Consultatie : public Medic {
private:
    std::string numePacient;
    std::string prenumePacient;
    int varstaPacient;
    static int nr_consultatii;

public:
    Consultatie();
    Consultatie(const std::string& numeMedic, const std::string& prenumeMedic, const std::string& numePacient, const std::string& prenumePacient, int varstaPacient);
    Consultatie(const Consultatie& consultatie);
    virtual ~Consultatie();

    Consultatie& operator=(const Consultatie& consultatie);
    bool operator==(const Consultatie& consultatie) const;
    bool operator!=(const Consultatie& consultatie) const;
    friend std::ostream &operator<<(std::ostream &os, const Consultatie& c);

    std::string getNumePacient() const;
    void setNumePacient(const std::string& nume);
    std::string getPrenumePacient() const;
    void setPrenumePacient(const std::string& prenume);
    int getVarstaPacient() const;
    void setVarstaPacient(int varsta);

    virtual void adaugaConsultatie() = 0;
    friend std::ostream& operator<<(std::ostream& os, const Consultatie& c);
};

#endif //TEMA2_CONSULTATIE_H
