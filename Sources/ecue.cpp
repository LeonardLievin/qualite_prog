#include "../Headers/ecue.h"

// constructeur, destructeur
ecue::ecue() : matiere {}, d_nombreHeureCours{0}, d_nombreHeureTd{0}, d_nombreHeureTp{0}
{}

ecue::ecue( std::string code_matiere, std::string intitule, int coefficient, int heure_cours, int heure_td, int heure_tp ):
    matiere{code_matiere, intitule, coefficient}, d_nombreHeureCours{heure_cours},
    d_nombreHeureTd{heure_td}, d_nombreHeureTp{heure_tp}
{
    d_dansUeCompose = false ;
}
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
bool ecue::dansUeCompose() const
{
    return d_dansUeCompose;
}

// méthode void
void ecue::mettreNombreHeureCours (int heure_cours)
{
    d_nombreHeureCours = heure_cours ;
}
void ecue::mettreNombreHeureTp (int heure_tp)
{
    d_nombreHeureTp = heure_tp ;
}
void ecue::mettreNombreHeureTd (int heure_td)
{
    d_nombreHeureTd = heure_td ;
}
void ecue::mettreDansUeCompose(bool reponse)
{
    d_dansUeCompose = reponse;
}

void ecue::afficher_Ecue(std::ostream& ost) const
{
    ost<<" "<<nombreHeureCours()<<" "<<nombreHeureTd()<<" "<<nombreHeureTp()<<std::endl;
}


// méthode abstraite

int ecue::heureCours() const
{
    return nombreHeureCours() ;
}
int ecue::heureTd() const
{
    return nombreHeureTd() ;
}
int ecue::heureTp() const
{
    return nombreHeureTp() ;
}


void ecue::afficher(std::ostream& ost) const
{
    matiere::afficher(ost);
    afficher_Ecue(ost) ;
}
