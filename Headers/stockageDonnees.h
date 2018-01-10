#ifndef STOCKAGEDONNEES_H
#define STOCKAGEDONNEES_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "ecue.h"
#include "uesimple.h"
#include "formation.h"


using std::cout ;
using std::string;
using std::cin;
using std::endl;
using std::vector;

class stockageDonnees
{
    public:
    // constructeur, destructeur
    	stockageDonnees();
    	~stockageDonnees();

    // méthode modificateur
    	void afficherListeECUEs(std::ostream & ost) const;
    	void afficherListeUEs(std::ostream & ost) const;
    	void afficherListeFormations(std::ostream & ost) const;
    	void ajouterECUE(ecue* ecueAAjouter);
    	void ajouterUE(uesimple* ueAAjouter);
    	void ajouterFormation(formation* formationAAjouter);
        void supprimerECUE(int indiceASupprimer);
    	void supprimerUE(int indiceASupprimer);
    	void supprimerFormation(int indiceASupprimer);

    // méthode retour
    	formation* formationIndice(int i);
    	uesimple* ueIndice(int i);
    	int trouverIndiceECUE() const;
    	int trouverIndiceUE() const;
    	int trouverIndiceFormation() const;
    	vector<ecue*> listeECUEs() const ;
		vector<uesimple*> listeUEs() const;

    protected:
    private:
    	vector<ecue*> d_listeECUEs;
		vector<uesimple*> d_listeUEs;
		vector<formation*> d_listeFormations;
};

#endif
