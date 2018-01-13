#include "../Headers/stockageDonnees.h"

stockageDonnees::stockageDonnees(){}

stockageDonnees::~stockageDonnees()
{
	for (int i = 0; i < d_listeECUEs.size(); i++)
	{
        delete d_listeECUEs[i];
	}
	for (int i = 0; i < d_listeUEs.size(); i++)
	{
        delete d_listeUEs[i];
	}
	for (int i = 0; i < d_listeFormations.size(); i++)
	{
        delete d_listeFormations[i];
	}
	for (int i = 0; i < d_listeUEchoix.size(); i++)
	{
        delete d_listeUEchoix[i];
	}
	for (int i = 0; i < d_listeUEcomposes.size(); i++)
	{
        delete d_listeUEcomposes[i];
	}
}

void stockageDonnees::afficherListeECUEs(std::ostream & ost) const
{
	for (int i = 0; i < d_listeECUEs.size(); i++)
	{
		ost << "[" << i+1 << "]";
		d_listeECUEs[i]->afficher(ost);
		cout << endl;
	}
}

void stockageDonnees::afficherListeUEs(std::ostream & ost) const
{
	for (int i = 0; i < d_listeUEs.size(); i++)
	{
		ost << "[" << i+1 << "]";
		d_listeUEs[i]->afficher(ost);
		cout << endl;
	}
}

void stockageDonnees::afficherListeFormations(std::ostream & ost) const
{
	for (int i = 0; i < d_listeFormations.size(); i++)
	{
		ost << "[" << i+1 << "]";
		d_listeFormations[i]->afficher(ost);
		cout << endl;
	}
}

void stockageDonnees::afficherListeUEchoix(std::ostream & ost) const
{
	for (int i = 0; i < d_listeUEchoix.size(); i++)
	{
		ost << "[" << i+1 << "]";
		d_listeUEchoix[i]->afficher(ost);
		cout << endl;
	}
}

void stockageDonnees::afficherListeUEcomposes(std::ostream & ost) const
{
	for (int i = 0; i < d_listeUEcomposes.size(); i++)
	{
		ost << "[" << i+1 << "]";
		d_listeUEcomposes[i]->afficher(ost);
		cout << endl;
	}
}

void stockageDonnees::ajouterECUE(ecue* ecueAAjouter)
{
	d_listeECUEs.push_back(ecueAAjouter);
}

void stockageDonnees::ajouterUE(uesimple* ueAAjouter)
{
	d_listeUEs.push_back(ueAAjouter);
}

void stockageDonnees::ajouterFormation(formation* formationAAjouter)
{
	d_listeFormations.push_back(formationAAjouter);
}

void stockageDonnees::ajouterUEchoix(uechoix* ueAAjouter)
{
	d_listeUEchoix.push_back(ueAAjouter);
}

void stockageDonnees::ajouterUEcompose(uecompose* ueAAjouter)
{
	d_listeUEcomposes.push_back(ueAAjouter);
}

int stockageDonnees::trouverIndiceECUE() const
{
	int choixUtilisateur;
	afficherListeECUEs(cout);
	cout << "Choisissez une ECUE :" << endl;
	cin >> choixUtilisateur;
	if (d_listeECUEs.size() == 0)
	{
		return -1;
	}
	while (choixUtilisateur < 1 || choixUtilisateur > d_listeECUEs.size())
	{
		cout << "Choix invalide, recommencez : ";
		cin >> choixUtilisateur;
	}
	return choixUtilisateur-1;
}

int stockageDonnees::trouverIndiceUE() const
{
	int choixUtilisateur;
	afficherListeUEs(cout);
	cout << "Choisissez une UE :" << endl;
	cin >> choixUtilisateur;
	if (d_listeUEs.size() == 0)
	{
		return -1;
	}
	while (choixUtilisateur < 1 || choixUtilisateur > d_listeUEs.size())
	{
		cout << "Choix invalide, recommencez : ";
		cin >> choixUtilisateur;
	}
	return choixUtilisateur-1;
}


int stockageDonnees::trouverIndiceUEchoix() const
{
	int choixUtilisateur;
	afficherListeUEchoix(cout);
	cout << "Choisissez une UE a choix :" << endl;
	cin >> choixUtilisateur;
	if (d_listeUEchoix.size() == 0)
	{
		return -1;
	}
	while (choixUtilisateur < 1 || choixUtilisateur > d_listeUEchoix.size())
	{
		cout << "Choix invalide, recommencez : ";
		cin >> choixUtilisateur;
	}
	return choixUtilisateur-1;
}

int stockageDonnees::trouverIndiceUEcompose() const
{
	int choixUtilisateur;
	afficherListeUEcomposes(cout);
	cout << "Choisissez une UE composee :" << endl;
	cin >> choixUtilisateur;
	if (d_listeUEcomposes.size() == 0)
	{
		return -1;
	}
	while (choixUtilisateur < 1 || choixUtilisateur > d_listeUEcomposes.size())
	{
		cout << "Choix invalide, recommencez : ";
		cin >> choixUtilisateur;
	}
	return choixUtilisateur-1;
}


int stockageDonnees::trouverIndiceFormation() const
{
	int choixUtilisateur;
	afficherListeFormations(cout);
	cout << "Choisissez une ECUE :" << endl;
	cin >> choixUtilisateur;
	if (d_listeFormations.size() == 0)
	{
		return -1;
	}
	while (choixUtilisateur < 1 || choixUtilisateur > d_listeFormations.size())
	{
		cout << "Choix invalide, recommencez : ";
		cin >> choixUtilisateur;
	}
	return choixUtilisateur-1;
}

void stockageDonnees::supprimerECUE(int indiceASupprimer)
{
	if (indiceASupprimer != -1)
	{
		delete d_listeECUEs[indiceASupprimer];
		d_listeECUEs[indiceASupprimer] = d_listeECUEs[d_listeECUEs.size()-1];
		d_listeECUEs.pop_back();
	}
}

void stockageDonnees::supprimerUE(int indiceASupprimer)
{
	if (indiceASupprimer != -1)
	{
		delete d_listeUEs[indiceASupprimer];
		d_listeUEs[indiceASupprimer] = d_listeUEs[d_listeUEs.size()-1];
		d_listeUEs.pop_back();
	}
}


void stockageDonnees::supprimerUEcompose(int indiceASupprimer)
{
	if (indiceASupprimer != -1)
	{
		delete d_listeUEcomposes[indiceASupprimer];
		d_listeUEcomposes[indiceASupprimer] = d_listeUEcomposes[d_listeUEcomposes.size()-1];
		d_listeUEcomposes.pop_back();
	}
}

void stockageDonnees::supprimerUEchoix(int indiceASupprimer)
{
	if (indiceASupprimer != -1)
	{
		delete d_listeUEchoix[indiceASupprimer];
		d_listeUEchoix[indiceASupprimer] = d_listeUEchoix[d_listeUEchoix.size()-1];
		d_listeUEchoix.pop_back();
	}
}


void stockageDonnees::supprimerFormation(int indiceASupprimer)
{
	if (indiceASupprimer != -1)
	{
		delete d_listeFormations[indiceASupprimer];
		d_listeFormations[indiceASupprimer] = d_listeFormations[d_listeFormations.size()-1];
		d_listeFormations.pop_back();
	}
}

ecue* stockageDonnees::ecueIndice(int i)
{
	return d_listeECUEs[i];
}

formation* stockageDonnees::formationIndice(int i)
{
	return d_listeFormations[i];
}

uesimple* stockageDonnees::ueIndice(int i)
{
	return d_listeUEs[i];
}

uecompose* stockageDonnees::ueComposeIndice(int i)
{
	return d_listeUEcomposes[i];
}

uechoix* stockageDonnees::ueChoixIndice(int i)
{
	return d_listeUEchoix[i];
}


vector<ecue*> stockageDonnees::listeECUEs() const
{
    return d_listeECUEs;
}

vector<uesimple*> stockageDonnees::listeUEs() const
{
    return d_listeUEs ;
}

vector<uechoix*> stockageDonnees::listeUEchoix() const
{
    return d_listeUEchoix ;
}
vector<uecompose*> stockageDonnees::listeUEcomposes() const
{
    return d_listeUEcomposes ;
}

vector<formation*> stockageDonnees::listeFormations() const
{
    return d_listeFormations ;
}
