#include "../Headers/uechoix.h"

// constructeur, destructeur
uechoix::uechoix(){}

uechoix::uechoix(std::string code_matiere, std::string intitule, int coefficient, int ects):
    ue{code_matiere, intitule, coefficient , ects},
    d_choixDisponibleUe{}
{}

uechoix::~uechoix(){}

// méthode modificateur
void uechoix::setUe(ue* nouvelleUe)
{
    d_choixDisponibleUe.push_back(nouvelleUe);
}

void uechoix::supprimerUe(int index)
{
    d_choixDisponibleUe[index] = nullptr;
    delete d_choixDisponibleUe[index];
    d_choixDisponibleUe[index] = d_choixDisponibleUe[d_choixDisponibleUe.size()-1];
    d_choixDisponibleUe.pop_back();
}

// méthode retour
std::vector <ue*> uechoix::ueDisponible() const
{
    return d_choixDisponibleUe;
}

// méthode abstraite
void uechoix::afficher(std::ostream& ost) const
{
    for (unsigned int i = 0 ; i <=d_choixDisponibleUe.size() ; i++ )
    {
        d_choixDisponibleUe[i]->afficher(ost);
    }
}

/*
int uechoix::nombreTotalHeure() const
{
    int somme = 0 ;
    for (unsigned int i = 0 ; i <=d_choixDisponibleUe.size() ; i++ )
    {
        somme = somme + d_choixDisponibleUe.at(i)->nombreTotalHeure() ;
    }
    return somme;
}
*/
