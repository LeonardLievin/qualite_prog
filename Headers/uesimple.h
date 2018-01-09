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

    // m�thode retour
    int ects() const;
    void mettreEcts(int );

    // m�thode abstraite
    virtual void afficher_UE(std::ostream &ost) const;

private:
    int d_ects;
};

#endif // UESIMPLE_H
