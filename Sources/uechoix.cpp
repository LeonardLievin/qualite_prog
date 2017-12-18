#include "../Headers/uechoix.h"

// constructeur, destructeur
uechoix::uechoix(){}

uechoix::uechoix(std::string code_matiere, std::string intitule, int coefficient, int ects):
    ue{code_matiere, intitule, coefficient , ects},
    d_choix_disponible_ue{}
{}

uechoix::~uechoix(){}

// méthode void
void uechoix::setUe(ue* newUe)
{
    d_choix_disponible_ue.push_back(newUe);
}

void uechoix::supprimerUe(int index)
{
    d_choix_disponible_ue[index] = nullptr;
    delete d_choix_disponible_ue[index];
    d_choix_disponible_ue[index] = d_choix_disponible_ue[d_choix_disponible_ue.size()-1];
    d_choix_disponible_ue.pop_back();
}

// méthode retour
std::vector <ue*> uechoix::ueDisponible() const
{
    return d_choix_disponible_ue;
}

// méthode abstraite
void uechoix::afficher(std::ostream& ost) const
{
    for (unsigned int i = 0 ; i <=d_choix_disponible_ue.size() ; i++ )
    {
        d_choix_disponible_ue[i]->afficher(ost);
    }
}

int uechoix::nombreTotalHeure() const
{
    int somme = 0 ;
    for (unsigned int i = 0 ; i <=d_choix_disponible_ue.size() ; i++ )
    {
        somme = somme + d_choix_disponible_ue.at(i)->nombreTotalHeure() ;
    }
    return somme;
}
