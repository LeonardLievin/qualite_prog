#ifndef UESIMPLE_H
#define UESIMPLE_H

#include "ecue.h"

class uesimple : public ecue
{
public:
    // constructeur, destructeur
    uesimple();
    uesimple(std::string codeUe, std::string nomUe, int coefficient, int ects,
             int nombreHeureCours, int nombreHeureTd, int nombreHeureTp);
    ~uesimple() ;

    // méthode retour
    int ects() const;
    void mettreEcts(int );

    // méthode abstraite
    virtual void afficher_UE(std::ostream &ost) const;

private:
    int d_ects;
};

#endif // UESIMPLE_H
