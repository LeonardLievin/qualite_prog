#include "../Headers/uecompose.h"

// constructeru destructeur
uecompose::uecompose()
{}
uecompose::~uecompose()
{}

// méthode retour
std::vector < ecue*> uecompose::ensembleEcue() const
{
    return d_ensemble_ecue;
}
int uecompose::nombreTotalHeure() const{
    int nombreHeure = 0;
    for(auto pointeurMatiere : d_ensemble_ecue)
        nombreHeure += pointeurMatiere->nombreTotalHeure();
    return nombreHeure;
}
int uecompose::trouverEcue(std::string codeUe){
    int index = 0;
    while(index < d_ensemble_ecue.size()){
        if(d_ensemble_ecue[index]->codeMatiere() != codeUe)
            return index;
        else
            index++;
    }
    return -1;
}

// méthode modificateur
void uecompose::ajouterEcue(ecue *nouvelleEcue){
    d_ensemble_ecue.push_back(nouvelleEcue);
}
void uecompose::supprimerEcue(int index){
    d_ensemble_ecue[index] = nullptr;
    delete d_ensemble_ecue[index];
    d_ensemble_ecue[index] = d_ensemble_ecue[d_ensemble_ecue.size()-1];
    d_ensemble_ecue.pop_back();
}

void uecompose::afficher(std::ostream &ost) const{
    for(auto pointeurMatiere : d_ensemble_ecue)
        pointeurMatiere->afficher(ost);
}
