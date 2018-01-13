#ifndef STOCKAGEDONNEES_H
#define STOCKAGEDONNEES_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "ecue.h"
#include "uesimple.h"
#include "uechoix.h"
#include "uecompose.h"
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

    	void afficherListeUEchoix(std::ostream & ost) const;
    	void afficherListeUEcomposes(std::ostream & ost) const;

    	void ajouterECUE(ecue* ecueAAjouter);
    	void ajouterUE(uesimple* ueAAjouter);
    	void ajouterFormation(formation* formationAAjouter);
        void ajouterUEchoix(uechoix* ueAAjouter);
    	void ajouterUEcompose(uecompose* ueAAjouter);

    	void supprimerECUE(int indiceASupprimer);
    	void supprimerUE(int indiceASupprimer);
    	void supprimerUEcompose(int indiceASupprimer);
    	void supprimerUEchoix(int indiceASupprimer);
    	void supprimerFormation(int indiceASupprimer);

    // méthode retour
    	formation* formationIndice(int i);
    	uesimple* ueIndice(int i);
    	uecompose* ueComposeIndice(int i);
    	uechoix* ueChoixIndice(int i);
    	ecue* ecueIndice(int i);

    	int trouverIndiceECUE() const;
    	int trouverIndiceUE() const;
    	int trouverIndiceUEchoix() const;
    	int trouverIndiceUEcompose() const;
    	int trouverIndiceFormation() const;

    	vector<ecue*> listeECUEs() const ;
		vector<uesimple*> listeUEs() const;
		vector<uecompose*> listeUEcomposes() const;
		vector<uechoix*> listeUEchoix() const;
		vector<formation*> listeFormations() const;

    protected:
    private:
    	vector<ecue*> d_listeECUEs;
		vector<uesimple*> d_listeUEs;
		vector<uecompose*> d_listeUEcomposes;
		vector<uechoix*> d_listeUEchoix;
		vector<formation*> d_listeFormations;
};

#endif
