#include <iostream>
#include <memory>
#include <vector>

#include "Medic.h"
#include "Consultatie.h"
#include "Consultatie_ochi.h"
#include "Consultatie_inima.h"
#include "Consultatie_dermato.h"

int main() {
    std::vector<std::unique_ptr<Consultatie>> consultatii;
    std::vector<std::unique_ptr<Medic>> medici;
    std::string input;
    int option;

    do {
        std::cout << "1. Adauga consultatie\n";
        std::cout << "2. Sterge consultatie\n";
        std::cout << "3. Afiseaza consultatii\n";
        std::cout << "4. Adauga medic\n";
        std::cout << "5. Sterge medic\n";
        std::cout << "6. Afiseaza medici\n";
        std::cout << "7. Iesire\n";
        std::cout << "Introduceti optiunea: ";
        std::getline(std::cin, input);
        option = std::stoi(input);

        switch (option) {
            case 1: {
                std::string nume;
                int varsta;
                std::cout << "Introduceti numele pacientului: ";
                std::getline(std::cin, nume);
                std::cout << "Introduceti varsta pacientului: ";
                std::getline(std::cin, input);
                varsta = std::stoi(input);

                std::cout << "Ce tip de consultatie doriti sa adaugati?\n";
                std::cout << "1. Consultatie generala\n";
                std::cout << "2. Consultatie oftalmologica\n";
                std::cout << "3. Consultatie cardiologica\n";
                std::cout << "4. Consultatie dermatologica\n";
                std::cout << "Introduceti optiunea: ";
                std::getline(std::cin, input);
                option = std::stoi(input);

                switch (option) {
                    case 1: {
                        std::unique_ptr<Consultatie> consultatie = std::make_unique<Consultatie>(nume, varsta);
                        consultatii.push_back(std::move(consultatie));
                        break;
                    }
                    case 2: {
                        std::unique_ptr<Consultatie> consultatie = std::make_unique<Consultatie_Ochi>(nume, varsta);
                        consultatii.push_back(std::move(consultatie));
                        break;
                    }
                    case 3: {
                        std::unique_ptr<Consultatie> consultatie = std::make_unique<Consultatie_Inima>(nume, varsta);
                        consultatii.push_back(std::move(consultatie));
                        break;
                    }
                    case 4: {
                        std::unique_ptr<Consultatie> consultatie = std::make_unique<Consultatie_Dermato>(nume, varsta);
                        consultatii.push_back(std::move(consultatie));
                        break;
                    }
                    default: {
                        std::cout << "Optiune invalida\n";
                        break;
                    }
                }
                break;
            }
            case 2: {
                std::cout << "Introduceti indexul consultatiei de sters: ";
                std::getline(std::cin, input);
                int index = std::stoi(input);

                if (index >= 0 && index < consultatii.size()) {
                    consultatii.erase(consultatii.begin() + index);
                }
            }
            case 3: {
                std::cout << "1. Afisare medici\n";
                std::cout << "2. Afisare consultatii\n";
                std::cout << "Introduceti optiunea: ";
                std::getline(std::cin, input);
                option = std::stoi(input);

                if (option == 1) {
                    std::cout << "Lista medici:\n";
                    for (const auto &medic: medici) {
                        std::cout << medic->getNumeMedic() << " - " << medic->getPrenumeMedic() << std::endl;
                    }
                } else if (option == 2) {
                    std::cout << "Lista consultatii:\n";
                    for (const auto &consultatie: consultatii) {
                        std::cout << "Pacient: " << consultatie->getNumePacient() << ", Varsta: "
                                  << consultatie->getVarstaPacient() << ", Tip consultatie: ";

                        if (dynamic_cast<Consultatie_Ochi *>(consultatie.get())) {
                            std::cout << "Consultatie oftalmologica";
                        } else if (dynamic_cast<Consultatie_Inima *>(consultatie.get())) {
                            std::cout << "Consultatie cardiologica";
                        } else if (dynamic_cast<Consultatie_Dermato *>(consultatie.get())) {
                            std::cout << "Consultatie dermatologica";
                        } else {
                            std::cout << "Consultatie generala";
                        }
                        std::cout << std::endl;
                    }
                } else {
                    std::cout << "Optiune invalida\n";
                }
                break;
            }
            case 4: {
                std::string nume, prenume, specializare;
                std::cout << "Introduceti numele medicului: ";
                std::getline(std::cin, nume);
                std::cout << "Introduceti prenumele medicului: ";
                std::getline(std::cin, prenume);
                std::cout << "Introduceti specializarea medicului: ";
                std::getline(std::cin, specializare);

                std::unique_ptr<Medic> medic = std::make_unique<Medic>(nume, prenume, specializare);
                medici.push_back(std::move(medic));
                break;
            }
            case 5: {
                std::cout << "Introduceti indexul medicului de sters: ";
                std::getline(std::cin, input);
                int index = std::stoi(input);

                if (index >= 0 && index < medici.size()) {
                    medici.erase(medici.begin() + index);
                } else {
                    std::cout << "Index invalid\n";
                }
                break;
            }
            case 6: {
                std::cout << "Medici:\n";
                for (const auto &medic: medici) {
                    std::cout << "Nume: " << medic->getNumeMedic() << ", Prenume: " << medic->getPrenumeMedic()
                              << std::endl;
                }
                break;
            }
            case 7: {
                std::cout << "La revedere!\n";
                break;
            }
            default: {
                std::cout << "Optiune invalida\n";
                break;
            }
        }
    } while (option != 7);

    return 0;
}