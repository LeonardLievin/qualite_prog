#include "../Headers/uesimple.h"

// constructeur, destructeur
uesimple::uesimple() :
    ecue(),d_ects{1}
{}

uesimple::uesimple(std::string codeUe, std::string nomUe, int coefficient,
                   int ects, int nombreHeureCours, int nombreHeureTd, int nombreHeureTp):
    ecue(codeUe, nomUe, coefficient, nombreHeureCours, nombreHeureTd, nombreHeureTp )
    ,d_ects{ects}
{}

uesimple::~uesimple(){}

// méthode retour
int uesimple::ects() const
{
    return d_ects;
}

// méthode modificateur
void uesimple::mettreEcts(int ects)
{
    d_ects = ects;
}

void uesimple::afficher_UE(std::ostream &ost) const{
    ost << " " << d_ects ;
}

// méthode abstraite
void uesimple::afficher(std::ostream &ost) const{


    matiere::afficher(ost);
    afficher_UE(ost) ;
    ecue::afficher_Ecue(ost);
}


// surcharge
std::ostream& operator<<(std::ostream& ost, const uesimple &ue){
    ue.afficher(ost);
    return ost;
}


