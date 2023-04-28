#ifndef TEMA2_CONSULTATIE_INIMA_H
#define TEMA2_CONSULTATIE_INIMA_H

#include <string>
#include "Consultatie.h"

class Consultatie_Inima : public Consultatie {
private:
    std::string diagnostic;
//    static int nr_consultatii;

public:
    Consultatie_Inima();
    Consultatie_Inima(const std::string& numeMedic, const std::string& prenumeMedic,
                     const std::string& numePacient, const std::string& prenumePacient, int varstaPacient,
                     const std::string& diag, int nr_cons);
    Consultatie_Inima(const Consultatie_Inima& c);
    ~Consultatie_Inima();
    Consultatie_Inima& operator=(const Consultatie_Inima& c);
    bool operator==(const Consultatie_Inima& c) const;
    bool operator!=(const Consultatie_Inima& c) const;
    friend std::ostream& operator<<(std::ostream& os, const Consultatie_Inima& c);


    // Metode get si set pentru atributele specifice clasei Consultatie_Inima
    std::string get_diagnostic() const;
    void set_diagnostic(const std::string& diag);
//    int get_nr_consultatii() const;
//    static void set_nr_consultatii(int nr_cons);


};

#endif //TEMA2_CONSULTATIE_INIMA_H
