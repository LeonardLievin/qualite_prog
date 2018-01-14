#include "../Headers/uecompose.h"

// constructeru destructeur
uecompose::uecompose()
{}
uecompose::~uecompose()
{}
uecompose::uecompose(std::string code_matiere, std::string intitule, int coefficient, int ects):
    ue{code_matiere, intitule, coefficient , ects}
{}

// méthode retour
std::vector < ecue*> uecompose::ensembleEcue() const
{
    return d_ensemble_ecue;
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
    nouvelleEcue->mettreDansUeCompose(true);
    d_ensemble_ecue.push_back(nouvelleEcue);
}
void uecompose::supprimerEcue(int index){
    d_ensemble_ecue[index] = nullptr;
    delete d_ensemble_ecue[index];
    d_ensemble_ecue[index] = d_ensemble_ecue[d_ensemble_ecue.size()-1];
    d_ensemble_ecue.pop_back();
}

void uecompose::menuSupprimerEcue()
{
	int choix = -1;
	while (choix =! 0 && d_ensemble_ecue.size() != 0)
	{
		std::cout << "Choisissez la matiere a supprimer : " << std::endl;
		afficher(std::cout);
		std::cout << "[0] Quitter." << std::endl;
		std::cin >> choix;
		if (choix != 0)
		{
			supprimerEcue(choix-1);
		}
	}
}


int uecompose::heureCours() const
{
    int total = 0 ;
    for(int i = 0  ; i< d_ensemble_ecue.size() ; i++)
    {
        total += d_ensemble_ecue.at(i)->nombreHeureCours();
	}
	return total ;
}

void uecompose::afficher(std::ostream &ost) const{
	matiere::afficher(ost);
	ost << " ";
	ue::afficher(ost);
	ost<<std::endl;
	std::cout << "------------"<< d_ensemble_ecue.size()  <<std::endl;
    for(int i = 0  ; i< d_ensemble_ecue.size() ; i++)
    {
    	ost << "[" << i+1 << "] ";
        d_ensemble_ecue.at(i)->afficher(ost);
	}
}
