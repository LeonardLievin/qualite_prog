#ifndef UECOMPOSE_H
#define UECOMPOSE_H

#include "ue.h"
#include "ecue.h"


class uecompose : public ue
{
public:
    //constructeur, destructeur
    uecompose();
    ~uecompose();

    // m�thode retour
    std::vector < ecue* > ensembleEcue() const ;
    int trouverEcue(std::string codeUe);

    // m�thode modificateur
    void ajouterEcue(ecue *nouvelleEcue);
    void supprimerEcue(int index);

    // methode abstraite
    virtual void afficher(std::ostream &ost) const override;
    virtual int nombreTotalHeure() const override;

private:
    std::vector < ecue* > d_ensemble_ecue ;

};

#endif // UECOMPOSE_H
