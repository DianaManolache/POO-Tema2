#ifndef TEMA2_MEDIC_H
#define TEMA2_MEDIC_H

#include <string>

class Medic {
private:
    std::string numeMedic;
    std::string prenumeMedic;

public:
    Medic();
    Medic(const std::string& nume, const std::string& prenume);
    Medic(const Medic& medic);
    virtual ~Medic();

    Medic& operator=(const Medic& medic);
    bool operator==(const Medic& medic) const;
    bool operator!=(const Medic& medic) const;
    friend std::ostream& operator<<(std::ostream& os, const Medic& medic);

    std::string getNumeMedic() const;
    void setNumeMedic(const std::string& nume);
    std::string getPrenumeMedic() const;
    void setPrenumeMedic(const std::string& prenume);
};

#endif //TEMA2_MEDIC_H
