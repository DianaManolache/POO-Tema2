#ifndef TEMA2_CONSULTATIE_OCHI_H
#define TEMA2_CONSULTATIE_OCHI_H

#include <string>
#include "Consultatie.h"

class Consultatie_Ochi : public Consultatie {
private:
    std::string diagnostic;
//    static int nr_consultatii;

public:
    Consultatie_Ochi();
    Consultatie_Ochi(const std::string& numeMedic, const std::string& prenumeMedic,
                     const std::string& numePacient, const std::string& prenumePacient, int varstaPacient,
                     const std::string& diag, int nr_cons);
    Consultatie_Ochi(const Consultatie_Ochi& c);
    ~Consultatie_Ochi();
    Consultatie_Ochi& operator=(const Consultatie_Ochi& c);
    bool operator==(const Consultatie_Ochi& c) const;
    bool operator!=(const Consultatie_Ochi& c) const;
    friend std::ostream& operator<<(std::ostream& os, const Consultatie_Ochi& c);


    std::string get_diagnostic() const;
    void set_diagnostic(const std::string& diag);
//    int get_nr_consultatii() const;
//    static void set_nr_consultatii(int nr_cons);
};

#endif //TEMA2_CONSULTATIE_OCHI_H
