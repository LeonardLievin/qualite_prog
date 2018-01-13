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

    // méthode retour

        uesimple* nouvelleUEaCreer();
        ecue* nouvelleECUEaCreer();
        uecompose* nouvelleUEcomposeaCreer();
        uechoix* nouvelleUEchoixaCreer();
        formation* nouvelleFormationaCreer();

    // méthode modificateur
        void menuPrincipal();
        void menuECUEs();
        void menuUEs();
        void menuFormations();
        void menuImporter();
        void menuExporter();
        void menuUEchoix();
        void menuUEcomposes();

		void menuAjouterUneECUE();
		void menuSupprimerUneECUE();
		void menuAjouterUneUE();
		void menuSupprimerUneUE();

		void menuAjouterUneUEcompose();
		void menuSupprimerUneUEcompose();

		void menuModifierUEcompose();

		void menuAjouterECUEDansUEcompose(int indiceUEaModifier);
		void menuSupprimerECUEDansUEcompose(int indiceUEaModifier);

		void menuAjouterUneUEchoix();
		void menuSupprimerUneUEchoix();


		void menuAjouterUneFormation();
		void menuSupprimerUneFormation();
		void menuModifierFormations();

		void menuAjouterUEDansFormation(int indiceFormation);
		void menuSupprimerUEDansFormation(int indiceFormation);


    private:
    	stockageDonnees donneesMaquettes;
    	importation elementImport ;
    	exportation elementExport ;

};

void saisirEntierEntreDeuxBornes(int borneInferieur, int borneSuperieur, int &choixUtilisateur);
void saisirDonneesCommunesECUEetUE(std::string &codeMatiere, std::string &intitule, int &coefficient, int &heure_cours, int &heure_td, int &heure_tp);
void saisirDonneesMatiere(std::string &codeMatiere, std::string &intitule, int &coefficient);




#endif // AFFICHEUR_H


