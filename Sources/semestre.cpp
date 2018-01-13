#include "../Headers/semestre.h"

// constructeur, destructeur
semestre::semestre(){}
semestre::semestre(int numero):d_numero{numero}
{}
semestre::~semestre(){}

// méthode retour
int semestre::numero() const{
    return d_numero;
}
std::vector<matiere*> semestre::listeMatieres() const
{
    return d_listeMatieres;
}


void semestre::ajouterMatiere(matiere* nouvelleMatiere)
{
	d_listeMatieres.push_back(nouvelleMatiere);
}

void semestre::supprimerMatiere(int i)
{
	d_listeMatieres[i] = d_listeMatieres[d_listeMatieres.size()-1];
	d_listeMatieres.pop_back();
}

void semestre::afficher(std::ostream &ost) const
{
	ost << "Semestre " << numero() << std::endl;
	ost << "Matieres du semestre : " << std::endl;
	for (int i = 0; i < listeMatieres().size(); i++)
	{
		ost << "[" << i+1 << "]";
		listeMatieres()[i]->afficher(ost);
	}
}

void semestre::menuSupprimerMatiere()
{
	int choix = -1;
	while (choix =! 0 && d_listeMatieres.size() != 0)
	{
		std::cout << "Choisissez la matiere a supprimer : " << std::endl;
		afficher(std::cout);
		std::cout << "[0] Quitter." << std::endl;
		std::cin >> choix;
		if (choix != 0)
		{
			supprimerMatiere(choix-1);
		}
	}
}

std::ostream& operator<<(std::ostream& ost, const semestre &sem)
{
	sem.afficher(ost);
	return ost;
}
