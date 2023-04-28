#ifndef TEMA2_CONSULTATIE_DERMATO_H
#define TEMA2_CONSULTATIE_DERMATO_H

#include <string>
#include "Consultatie.h"

class Consultatie_Dermato : public Consultatie {
private:
    std::string diagnostic;
//    static int nr_consultatii;
public:
    Consultatie_Dermato();
    Consultatie_Dermato(const std::string& numeMedic, const std::string& prenumeMedic,
                     const std::string& numePacient, const std::string& prenumePacient, int varstaPacient,
                     const std::string& diag, int nr_cons);
    Consultatie_Dermato(const Consultatie_Dermato& c);
    ~Consultatie_Dermato();
    Consultatie_Dermato& operator=(const Consultatie_Dermato& c);
    bool operator==(const Consultatie_Dermato& c) const;
    bool operator!=(const Consultatie_Dermato& c) const;
    friend std::ostream& operator<<(std::ostream& os, const Consultatie_Dermato& c);

    // Metode get si set pentru atributele specifice clasei Consultatie_Dermato
    std::string get_diagnostic() const;
    void set_diagnostic(const std::string& diag);
//    int get_nr_consultatii() const;
//    static void set_nr_consultatii(int nr_cons);


};

#endif //TEMA2_CONSULTATIE_DERMATO_H
