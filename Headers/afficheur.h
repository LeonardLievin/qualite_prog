#ifndef AFFICHEUR_H
#define AFFICHEUR_H

#include "stockageDonnees.h"
#include "importation.h"
#include "exportation.h"

class afficheur
{
    public:

    // constructeur, destructeur
        afficheur();
        ~afficheur();

    // méthode modificateur
        void menuPrincipal();
        void menuECUEs();
        void menuUEs();
        void menuFormations();
        void menuImporter();
        void menuExporter();
		void menuAjouterUneECUE();
		void menuSupprimerUneECUE();
		void menuAjouterUneUE();
		void menuSupprimerUneUE();
		void menuAjouterUneFormation();
		void menuSupprimerUneFormation();
		void menuModifierFormations();

    private:
    	stockageDonnees donneesMaquettes;
    	importation elementImport ;
    	exportation elementExport ;

};

void saisirEntierEntreDeuxBornes(int borneInferieur, int borneSuperieur, int &choixUtilisateur);
void saisirDonneesCommunesECUEetUE(std::string &codeMatiere, std::string &intitule, int &coefficient, int &heure_cours, int &heure_td, int &heure_tp);

uesimple* nouvelleUEaCreer();
ecue* nouvelleECUEaCreer();
formation* nouvelleFormationaCreer();

#endif // AFFICHEUR_H


