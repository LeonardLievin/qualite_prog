#ifndef FORMATION_H
#define FORMATION_H
#include <iostream>
#include <vector>
#include "semestre.h"

using namespace std;

class formation
{
public:
    // constructeur, destructeur
    formation();
    formation(string domaine, string mention, string parcours, int annee,
    string niveau,int anneeNiveau, semestre semestreParametre);
    ~formation();

    // methode retour
    string domaine() const;
    string mention() const;
    string parcours() const;
    int annee() const;
    string niveau() const;
    int anneeNiveau() const;
    semestre semestreValeur() const;

    void setDomaine(string) ;
    void setMention(string) ;
    void setParcours(string);
    void setNiveau(string) ;
    void setAnnee(int) ;
    void setAnneeNiveau(int) ;
    void setSemestre (semestre);

    void afficher(std::ostream &ost) const;


private:
    string d_domaine ;
    string d_mention ;
    string d_parcours ;
    string d_niveau ;
    int d_anneeNiveau ;

    int d_annee ;
    semestre d_semestre ;

};

#endif // FORMATION_H
