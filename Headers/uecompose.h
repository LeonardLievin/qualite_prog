#ifndef UECOMPOSE_H
#define UECOMPOSE_H

#include "ue.h"
#include "ecue.h"

class uecompose : public ue
{
public:
    //constructeur, destructeur
    uecompose();
    uecompose(std::string code_matiere, std::string intitule, int coefficient, int ects);
    ~uecompose();

    // méthode retour
    std::vector < ecue* > ensembleEcue() const ;
    int trouverEcue(std::string);

    // méthode modificateur
    void ajouterEcue(ecue*);
    void supprimerEcue(int );
    void menuSupprimerEcue();

    // methode abstraite
    virtual void afficher(std::ostream &ost) const override;
    virtual int nombreTotalHeure() const override;

private:
    std::vector < ecue* > d_ensemble_ecue ;

};

#endif // UECOMPOSE_H
