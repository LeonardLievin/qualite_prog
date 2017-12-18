#ifndef UECHOIX_H
#define UECHOIX_H

#include "ue.h"

class uechoix : public ue
{
public:
    // constructeur destructeur
    uechoix();
    uechoix(std::string code_matiere, std::string intitule, int coefficient, int ects);
    ~uechoix();

    // méthode void
    void setUe(ue* newUe);
    void supprimerUe(int index);

    // méthode retour
    std::vector <ue*> ueDisponible() const ;

    // méthode abstraite
    virtual void afficher(std::ostream& ost) const override;
    virtual int nombreTotalHeure() const override;

private:
    std::vector <ue*> d_choix_disponible_ue;
};

#endif // UECHOIX_H
