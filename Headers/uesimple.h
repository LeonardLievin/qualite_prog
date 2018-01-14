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
    //int ects() const;

    // méthode modificateur
    void mettreEcts(int );
    void afficher_UE(std::ostream &ost) const;

    // méthode abstraite
    virtual void afficher(std::ostream &ost) const;
    virtual int heureCours() const ;
    virtual int heureTd() const ;
    virtual int heureTp() const ;
    virtual int ects() const ;

private:
    int d_ects;
};

#endif // UESIMPLE_H
