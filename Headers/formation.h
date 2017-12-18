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
    formation(string domaine, string mention, string parcours, int annee);
    ~formation();

    // methode retour
    string getDomaine() const;
    string getMention() const;
    string getParcours() const;
    int getAnnee() const;
    vector <semestre*> getSemestres() const;

private:
    string d_domaine ;
    string d_mention ;
    string d_parcours ;
    int d_annee ;
    vector <semestre*> d_semestre ;

};

#endif // FORMATION_H
