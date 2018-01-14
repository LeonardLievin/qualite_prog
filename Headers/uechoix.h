#ifndef UECHOIX_H
#define UECHOIX_H

#include "ue.h"

class uechoix : public ue
{
public:
    // constructeur, destructeur
    uechoix();
    uechoix(std::string , std::string , int coeficient, int );
    ~uechoix();

    // m�thode modificateur
    void setUe(ue*);
    void supprimerUe(int);

    // m�thode retour
    std::vector <ue*> ueDisponible() const ;

    // m�thode abstraite
    virtual void afficher(std::ostream&) const override;
//    virtual int nombreTotalHeure() const override;

private:
    std::vector <ue*> d_choixDisponibleUe;
};

#endif // UECHOIX_H
