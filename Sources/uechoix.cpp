#include "../Headers/uechoix.h"

// constructeur, destructeur
uechoix::uechoix(){}

uechoix::uechoix(std::string code_matiere, std::string intitule, int coefficient):
    matiere{code_matiere, intitule, coefficient },
    d_choixDisponibleEcue{}
{}

uechoix::~uechoix(){}

// méthode modificateur
void uechoix::mettreUe(ecue* nouvelleEcue)
{
    d_choixDisponibleEcue.push_back(nouvelleEcue);
}

void uechoix::supprimerEcue(int index)
{
    d_choixDisponibleEcue[index] = nullptr;
    delete d_choixDisponibleEcue[index];
    d_choixDisponibleEcue[index] = d_choixDisponibleEcue[d_choixDisponibleEcue.size()-1];
    d_choixDisponibleEcue.pop_back();
}

// méthode retour
std::vector <ecue*> uechoix::ecueDisponible() const
{
    return d_choixDisponibleEcue;
}

// méthode abstraite
void uechoix::afficher(std::ostream& ost) const
{
    for (unsigned int i = 0 ; i <d_choixDisponibleEcue.size() ; i++ )
    {
        cout << " --------- affichage"<<endl;
        d_choixDisponibleEcue.at(i)->afficher(ost);
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
