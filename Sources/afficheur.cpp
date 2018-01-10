#include "../Headers/afficheur.h"

afficheur::afficheur(){}

afficheur::~afficheur(){}

void saisirEntierEntreDeuxBornes(int borneInferieur, int borneSuperieur, int &choixUtilisateur)
{
	cin >> choixUtilisateur;
	while (choixUtilisateur < borneInferieur || choixUtilisateur > borneSuperieur)
	{
		cout << "Votre choix doit etre compris entre " << borneInferieur << " et " << borneSuperieur << ". Veuillez saisir un entier correct : ";
		cin >> choixUtilisateur;
	}
}

void saisirDonneesCommunesECUEetUE(std::string &codeMatiere, std::string &intitule, int &coefficient, int &heure_cours, int &heure_td, int &heure_tp)
{
	cout << "Entrez le code : ";
	cin >> codeMatiere;
	cout << endl;
	cout << "Entrez l'intitule : ";
	cin >> intitule;
	cout << endl;
	cout << "Entrez le coefficient : ";
	cin >> coefficient;
	cout << endl;
	cout << "Entrez le nombre d'heures de cours : ";
	cin >> heure_cours;
	cout << endl;
	cout << "Entrez le nombre d'heures de TD : ";
	cin >> heure_td;
	cout << endl;
	cout << "Entrez le nombre d'heures de TP : ";
	cin >> heure_tp;
}

void afficheur::menuPrincipal()
{
	int choixUtilisateur = -1;
	while (choixUtilisateur != 0)
	{
		cout << "MENU PRINCIPAL" << endl;
		cout << "Que voulez-vous faire ? " << endl;
		cout << "[1] Modifier les ECUEs." << endl;
		cout << "[2] Modifier les UEs." << endl;
		cout << "[3] Modifier les formations." << endl;
		cout << "[4] Importer les donnees." << endl;
		cout << "[5] Exporter les donnees." << endl;
		cout << "[0] Quitter." << endl;
		saisirEntierEntreDeuxBornes(0,5,choixUtilisateur);
		switch (choixUtilisateur)
		{
			case 1:
				menuECUEs();
				break;
			case 2:
				menuUEs();
				break;
			case 3:
				menuFormations();
				break;
			case 4:
				if(elementImport.execution(&donneesMaquettes))
                    elementImport.affichageImport() ;
				break;
			case 5:
				elementExport.ueAexporter(donneesMaquettes.listeUEs()) ;
                elementExport.ecueAexporter(donneesMaquettes.listeECUEs()) ;
                elementExport.mettreFormation(*donneesMaquettes.formationIndice(0)) ;
                elementExport.execution();
				break;
			default:
				break;
		}
	}
}

void afficheur::menuECUEs()
{
	int choixUtilisateur = -1;
	while (choixUtilisateur != 0)
	{
		cout << "MENU DES ECUES" << endl;
		cout << "Que voulez-vous faire ? " << endl;
		cout << "[1] Afficher les ECUEs." << endl;
		cout << "[2] Ajouter une ECUE." << endl;
		cout << "[3] Supprimer une ECUE." << endl;
		cout << "[0] Quitter." << endl;
		saisirEntierEntreDeuxBornes(0,3,choixUtilisateur);
		switch (choixUtilisateur)
		{
			case 1:
				donneesMaquettes.afficherListeECUEs(cout);
				break;
			case 2:
				menuAjouterUneECUE();
				break;
			case 3:
				menuSupprimerUneECUE();
				break;
			default:
				break;
		}
	}
}

void afficheur::menuUEs()
{
	int choixUtilisateur = -1;
	while (choixUtilisateur != 0)
	{
		cout << "MENU DES UES" << endl;
		cout << "Que voulez-vous faire ? " << endl;
		cout << "[1] Afficher les UEs." << endl;
		cout << "[2] Ajouter une UE." << endl;
		cout << "[3] Supprimer une UE." << endl;
		cout << "[0] Quitter." << endl;
		saisirEntierEntreDeuxBornes(0,3,choixUtilisateur);
		switch (choixUtilisateur)
		{
			case 1:
				donneesMaquettes.afficherListeUEs(cout);
				break;
			case 2:
				menuAjouterUneUE();
				break;
			case 3:
				menuSupprimerUneUE();
				break;
			default:
				break;
		}
	}
}

void afficheur::menuFormations()
{
	int choixUtilisateur = -1;
	while (choixUtilisateur != 0)
	{
		cout << "MENU DES FORMATIONS" << endl;
		cout << "Que voulez-vous faire ? " << endl;
		cout << "[1] Afficher les formations." << endl;
		cout << "[2] Ajouter une formation." << endl;
		cout << "[3] Supprimer une formation." << endl;
		cout << "[4] Modifier une formation (ajouter/supprimer UE)." << endl;
		cout << "[0] Quitter." << endl;
		saisirEntierEntreDeuxBornes(0,4,choixUtilisateur);
		switch (choixUtilisateur)
		{
			case 1:
				donneesMaquettes.afficherListeFormations(cout);
				break;
			case 2:
				menuAjouterUneFormation();
				break;
			case 3:
				menuSupprimerUneFormation();
				break;
			case 4:
				menuModifierFormations();
				break;
			default:
				break;
		}
	}
}

void afficheur::menuModifierFormations()
{
	int choixUtilisateur = -1;
	int indiceFormationaModifier = -1;
	while (choixUtilisateur != 0)
	{
		cout << "MENU DES MODIFICATIONS D'UNE FORMATION'" << endl;
		cout << "Que voulez-vous faire ? " << endl;
		cout << "[1] Selectionner la formation a modifier." << endl;
		cout << "[2] Ajouter une UE." << endl;
		cout << "[3] Supprimer une UE." << endl;
		cout << "[0] Quitter." << endl;
		saisirEntierEntreDeuxBornes(0,3,choixUtilisateur);
		switch (choixUtilisateur)
		{
			case 1:
				indiceFormationaModifier = donneesMaquettes.trouverIndiceFormation();
				break;
			case 2:
				if (indiceFormationaModifier == -1)
				{
					cout << "Veuillez selectionner une formation d'abord." << endl;
				}
				else
				{
					// menuAjouterUEaFormation(indice formation)
				}
				break;
			case 3:
				if (indiceFormationaModifier == -1)
				{
					cout << "Veuillez selectionner une formation d'abord." << endl;
				}
				else
				{
					// menuSupprimerUEaFormation(indice formation)
				}
				break;
			default:
				break;
		}
	}
}

uesimple* nouvelleUEaCreer()
{
	std::string codeMatiere, intitule;
	int coefficient, ects, heure_cours, heure_td, heure_tp;
	saisirDonneesCommunesECUEetUE(codeMatiere, intitule, coefficient, heure_cours, heure_td, heure_tp);
	cout << endl;
	cout << "Entrez le nombre d'ECTS : ";
	cin >> ects;
	cout << endl;
	uesimple *nouvelleUE = new uesimple{codeMatiere, intitule, coefficient, ects, heure_cours, heure_td, heure_tp};
	return nouvelleUE;
}

ecue* nouvelleECUEaCreer()
{
	std::string codeMatiere, intitule;
	int coefficient, heure_cours, heure_td, heure_tp;
	saisirDonneesCommunesECUEetUE(codeMatiere, intitule, coefficient, heure_cours, heure_td, heure_tp);
	cout << endl;
	ecue *nouvelleECUE = new ecue{codeMatiere, intitule, coefficient, heure_cours, heure_td, heure_tp};
	return nouvelleECUE;
}

formation* nouvelleFormationaCreer()
{
	std::string domaine, mention, parcours, niveau ;
    int annee, anneeNiveau, semestreInt ;
    cout << "Entrez le nom de domaine : ";
    cin >> domaine;
    cout << endl;
    cout << "Entrez le nom de la mention : ";
    cin >> mention;
    cout << endl;
    cout << "Entrez le nom du parcours : ";
    cin >> parcours;
    cout << endl;
    cout << "Entrez l'annee de debut de la formation : ";
    cin >> annee;
    cout << endl;
    cout << "Entrez le niveau : ";
    cin >> niveau;
    cout << endl;
    cout << "Entrez l'annee d'étude : ";
    cin >> anneeNiveau;
    cout << endl;
    cout << "Entrez le numéro du semestre : ";
    cin >> semestreInt;
    cout << endl;

    semestre semestreTemporaire{semestreInt} ;
    formation *nouvelleFormation = new formation{ domaine, mention, parcours, annee,
    niveau, anneeNiveau, semestreTemporaire};
    return nouvelleFormation;
}

void afficheur::menuAjouterUneECUE()
{
	ecue *ecueAAjouter;
	int choixUtilisateur = -1;
	while (choixUtilisateur != 0 && choixUtilisateur != 1)
	{
		ecueAAjouter = nouvelleECUEaCreer();
		cout << "Confirmez vous la creation de l'ECUE : " << endl;
		ecueAAjouter->afficher(std::cout);
		cout << "[1] Oui." << endl;
		cout << "[2] Non je veux en creer une autre." << endl;
		cout << "[0] Quitter sans la creer." << endl;
		saisirEntierEntreDeuxBornes(0,2,choixUtilisateur);
		switch (choixUtilisateur)
		{
			case 1:
				donneesMaquettes.ajouterECUE(ecueAAjouter);
				break;
			default:
				break;
		}
	}
}

void afficheur::menuAjouterUneUE()
{
	uesimple *ueAAjouter;
	int choixUtilisateur = -1;
	while (choixUtilisateur != 0 && choixUtilisateur != 1)
	{
		ueAAjouter = nouvelleUEaCreer();
		cout << "Confirmez vous la creation de l'UE : " << endl;
		ueAAjouter->afficher(std::cout);
		cout << "[1] Oui." << endl;
		cout << "[2] Non je veux en creer une autre." << endl;
		cout << "[0] Quitter sans la creer." << endl;
		saisirEntierEntreDeuxBornes(0,2,choixUtilisateur);
		switch (choixUtilisateur)
		{
			case 1:
				donneesMaquettes.ajouterUE(ueAAjouter);
				break;
            case 2:
                break;
			default:
				break;
		}
	}
}

void afficheur::menuAjouterUneFormation()
{
	formation *formationAAjouter;
	int choixUtilisateur = -1;
	while (choixUtilisateur != 0 && choixUtilisateur != 1)
	{
		formationAAjouter = nouvelleFormationaCreer();
		cout << "Confirmez vous la creation de la formation : " << endl;
		formationAAjouter->afficher(std::cout);
		cout << "[1] Oui." << endl;
		cout << "[2] Non je veux en creer une autre." << endl;
		cout << "[0] Quitter sans la creer." << endl;
		saisirEntierEntreDeuxBornes(0,2,choixUtilisateur);
		switch (choixUtilisateur)
		{
			case 1:
				donneesMaquettes.ajouterFormation(formationAAjouter);
				break;
			default:
				break;
		}
	}
}

void afficheur::menuSupprimerUneECUE()
{
	int choixUtilisateur = -1;
	int indiceECUEaSupprimer;
	indiceECUEaSupprimer = donneesMaquettes.trouverIndiceECUE();
	while (choixUtilisateur != 0 && choixUtilisateur != 1)
	{
		cout << "Voulez vous supprimer l'ECUE suivante : " << endl;
		//cout << listeECUEs.afficherECUENumero(indiceECUEaSupprimer) << endl;
		cout << "[1] Oui." << endl;
		cout << "[2] Non je veux en choisir une autre." << endl;
		cout << "[0] Quitter sans la supprimer." << endl;
		saisirEntierEntreDeuxBornes(0,2,choixUtilisateur);
		switch (choixUtilisateur)
		{
			case 1:
				donneesMaquettes.supprimerECUE(indiceECUEaSupprimer);
				break;
			case 2:
				indiceECUEaSupprimer = donneesMaquettes.trouverIndiceECUE();
				break;
			default:
				break;
		}
	}
}

void afficheur::menuSupprimerUneUE()
{
	int choixUtilisateur = -1;
	int indiceUEaSupprimer;
	indiceUEaSupprimer = donneesMaquettes.trouverIndiceUE();
	while (choixUtilisateur != 0 && choixUtilisateur != 1)
	{
		cout << "Voulez vous supprimer l'UE suivante : " << endl;
		//cout << listeUEs.afficherECUENumero(indiceUEaSupprimer) << endl;
		cout << "[1] Oui." << endl;
		cout << "[2] Non je veux en choisir une autre." << endl;
		cout << "[0] Quitter sans la supprimer." << endl;
		saisirEntierEntreDeuxBornes(0,2,choixUtilisateur);
		switch (choixUtilisateur)
		{
			case 1:
				donneesMaquettes.supprimerUE(indiceUEaSupprimer);
				break;
			case 2:
				indiceUEaSupprimer = donneesMaquettes.trouverIndiceUE();
				break;
			default:
				break;
		}
	}
}

void afficheur::menuSupprimerUneFormation()
{
	int choixUtilisateur = -1;
	int indiceFormationaSupprimer;
	indiceFormationaSupprimer = donneesMaquettes.trouverIndiceFormation();
	while (choixUtilisateur != 0 && choixUtilisateur != 1)
	{
		cout << "Voulez vous supprimer la formation suivante : " << endl;
		//cout << listeFormations.afficherFormationNumero(indiceFormationaSupprimer) << endl;
		cout << "[1] Oui." << endl;
		cout << "[2] Non je veux en choisir une autre." << endl;
		cout << "[0] Quitter sans la supprimer." << endl;
		saisirEntierEntreDeuxBornes(0,2,choixUtilisateur);
		switch (choixUtilisateur)
		{
			case 1:
				donneesMaquettes.supprimerFormation(indiceFormationaSupprimer);
				break;
			case 2:
				indiceFormationaSupprimer = donneesMaquettes.trouverIndiceFormation();
				break;
			default:
				break;
		}
	}
}
