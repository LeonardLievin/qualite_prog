#include "../Headers/ecue.h"

// constructeur, destructeur
ecue::ecue() : matiere {}, d_nombreHeureCours{0}, d_nombreHeureTd{0}, d_nombreHeureTp{0}
{}

ecue::ecue( std::string code_matiere, std::string intitule, int coefficient, int heure_cours, int heure_td, int heure_tp ):
    matiere{code_matiere, intitule, coefficient}, d_nombreHeureCours{heure_cours},
    d_nombreHeureTd{heure_td}, d_nombreHeureTp{heure_tp}
{}
ecue::~ecue()
{}

// metohdes retour
int ecue::nombreHeureCours() const
{
    return d_nombreHeureCours;
}

int ecue::nombreHeureTp() const
{
    return d_nombreHeureTp;
}

int ecue::nombreHeureTd() const
{
    return d_nombreHeureTd;
}

// méthode void
void ecue::setNbCours (int heure_cours)
{
    d_nombreHeureCours = heure_cours ;
}
void ecue::setNbTp (int heure_tp)
{
    d_nombreHeureTp = heure_tp ;
}
void ecue::setNbTd (int heure_td)
{
    d_nombreHeureTd = heure_td ;
}

// méthode abstraite
int ecue::nombreTotalHeure() const
{
    return d_nombreHeureCours + d_nombreHeureTd + d_nombreHeureTp;
}

void ecue::afficher(std::ostream& ost) const
{
    //matiere::afficher();
    ost<<"Nombre d'heure de cours : "<<nombreHeureCours()<<std::endl;
    ost<<"Nombre d'heure de TD : "<<nombreHeureTd()<<std::endl;
    ost<<"Nombre d'heure de TP : "<<nombreHeureTp()<<std::endl;
}
