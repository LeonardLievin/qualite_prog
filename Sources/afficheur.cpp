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

void saisirDonneesMatiere(std::string &codeMatiere, std::string &intitule, int &coefficient)
{
	cout << "Entrez le code : ";
	cin >> codeMatiere;
	cout << endl;
	cout << "Entrez l'intitule : ";
	cin >> intitule;
	cout << endl;
	cout << "Entrez le coefficient : ";
	cin >> coefficient;
}

void saisirDonneesCommunesECUEetUE(std::string &codeMatiere, std::string &intitule, int &coefficient, int &heure_cours, int &heure_td, int &heure_tp)
{
	saisirDonneesMatiere(codeMatiere, intitule, coefficient);
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
		cout << "[2] Modifier les UEs simples." << endl;
		cout << "[3] Modifier les UEs composees." << endl;
		cout << "[1] Modifier les ECUEs." << endl;
		//cout << "[4] Modifier les UEs choix." << endl;
		cout << "[4] Modifier les formations." << endl;
		cout << "[5] Importer les donnees." << endl;
		cout << "[6] Exporter les donnees." << endl;
		cout << "[0] Quitter." << endl;
		saisirEntierEntreDeuxBornes(0,7,choixUtilisateur);
		switch (choixUtilisateur)
		{
			case 1:
				menuUEs();
				break;
			case 2:
				menuUEcomposes();
				break;
			case 3:
				menuECUEs();
				break;
			case 8:
				//menuUEchoix();
				break;

			case 4:
				menuFormations();
				break;
			case 5:
				if(elementImport.execution(&donneesMaquettes))
                    elementImport.affichageImport() ;
				break;
			case 6:

				elementExport.ueAexporter(donneesMaquettes.listeUEs()) ;
                elementExport.ecueAexporter(donneesMaquettes.listeECUEs()) ;

                elementExport.uecomposeAexporter(donneesMaquettes.listeUEcomposes()) ;

                elementExport.mettreFormation(donneesMaquettes.listeFormations()) ;
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


void afficheur::menuUEcomposes()
{
	int choixUtilisateur = -1;
	while (choixUtilisateur != 0)
	{
		cout << "MENU DES UES COMPOSEES" << endl;
		cout << "Que voulez-vous faire ? " << endl;
		cout << "[1] Afficher les UEs composees." << endl;
		cout << "[2] Ajouter une UE composee." << endl;
		cout << "[3] Supprimer une UE composee." << endl;
		cout << "[4] Modifier une UE composee (ajouter/supprimer des UE)." << endl;
		cout << "[0] Quitter." << endl;
		saisirEntierEntreDeuxBornes(0,4,choixUtilisateur);
		switch (choixUtilisateur)
		{
			case 1:
				donneesMaquettes.afficherListeUEcomposes(cout);
				break;
			case 2:
				menuAjouterUneUEcompose();
				break;
			case 3:
				menuSupprimerUneUEcompose();
				break;
			case 4:
				menuModifierUEcompose();
			default:
				break;
		}
	}
}

void afficheur::menuModifierUEcompose()
{
	int choixUtilisateur = -1;
	int indiceUEaModifier = -1;
	while (choixUtilisateur != 0)
	{
		cout << "MENU DES MODIFICATIONS D'UNE UE COMPOSEE" << endl;
		cout << "Que voulez-vous faire ? " << endl;
		cout << "[1] Selectionner l'UE composee a modifier." << endl;
		cout << "[2] Ajouter une UE." << endl;
		cout << "[3] Supprimer une UE." << endl;
		cout << "[0] Quitter." << endl;
		saisirEntierEntreDeuxBornes(0,3,choixUtilisateur);
		switch (choixUtilisateur)
		{
			case 1:
				indiceUEaModifier = donneesMaquettes.trouverIndiceUEcompose();
				break;
			case 2:
				if (indiceUEaModifier == -1)
				{
					cout << "Veuillez selectionner une UE d'abord d'abord." << endl;
				}
				else
				{
					menuAjouterECUEDansUEcompose(indiceUEaModifier);
				}
				break;
			case 3:
				if (indiceUEaModifier == -1)
				{
					cout << "Veuillez selectionner une UE d'abord." << endl;
				}
				else
				{
					menuSupprimerECUEDansUEcompose(indiceUEaModifier);
				}
				break;
			default:
				break;
		}
	}
}


void afficheur::menuAjouterECUEDansUEcompose(int indiceUEaModifier)
{
	int indiceECUE;
	int choixUtilisateur = -1;
	while (choixUtilisateur != 2)
	{
		cout << "Que voulez vous ajouter a l'UE composee : " << endl;
		indiceECUE = donneesMaquettes.trouverIndiceECUE();
		donneesMaquettes.ueComposeIndice(indiceUEaModifier)->ajouterEcue(donneesMaquettes.ecueIndice(indiceECUE));
		cout << "Ajouter une autre UE ? " << endl;
		cout << "[1] Oui." << endl;
		cout << "[2] Non." << endl;
		saisirEntierEntreDeuxBornes(1,2,choixUtilisateur);
	}
}

void afficheur::menuSupprimerECUEDansUEcompose(int indiceUEaModifier)
{
	int choixUtilisateur = -1;
	while (choixUtilisateur != 2)
	{
		cout << "Choisi l'ECUE a supprimer' " << endl;
		donneesMaquettes.ueComposeIndice(indiceUEaModifier)->menuSupprimerEcue();
		cout << "Supprimer une autre UE ? " << endl;
		cout << "[1] Oui." << endl;
		cout << "[2] Non." << endl;
		saisirEntierEntreDeuxBornes(1,2,choixUtilisateur);
	}
}

void afficheur::menuUEchoix()
{
	int choixUtilisateur = -1;
	while (choixUtilisateur != 0)
	{
		cout << "MENU DES UES CHOIX" << endl;
		cout << "Que voulez-vous faire ? " << endl;
		cout << "[1] Afficher les UE choix." << endl;
		cout << "[2] Ajouter une UE choix." << endl;
		cout << "[3] Supprimer une UE choix." << endl;
		cout << "[0] Quitter." << endl;
		saisirEntierEntreDeuxBornes(0,3,choixUtilisateur);
		switch (choixUtilisateur)
		{
			case 1:
				donneesMaquettes.afficherListeUEchoix(cout);
				break;
			case 2:
				menuAjouterUneUEchoix();
				break;
			case 3:
				menuSupprimerUneUEchoix();
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
					menuAjouterUEDansFormation(indiceFormationaModifier);
				}
				break;
			case 3:
				if (indiceFormationaModifier == -1)
				{
					cout << "Veuillez selectionner une formation d'abord." << endl;
				}
				else
				{
					menuSupprimerUEDansFormation(indiceFormationaModifier);
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


void afficheur::menuAjouterUEDansFormation(int indiceFormation)
{
	int semestreChoisi = -1;
	cout << "Choisissez le semestre dans le quel vous voulez ajouter l'UE : " << endl;
	cout << "[1] Le premier semestre." << endl;
	cout << "[2] Le deuxieme semestre." << endl;
	cout << "[0] Quitter." << endl;
	saisirEntierEntreDeuxBornes(0,2,semestreChoisi);
	if (semestreChoisi != 0)
	{
		semestreChoisi--;
		int indiceUE;
		int choixUtilisateur = -1;
		while (choixUtilisateur != 0)
		{
			cout << "Que voulez vous ajouter au semestre " << semestreChoisi+1 << " ? " << endl;
			cout << "[1] Une UE simple." << endl;
			cout << "[2] Une UE composee." << endl;
			cout << "[3] Une UE choix." << endl;
			cout << "[0] Quitter." << endl;
			saisirEntierEntreDeuxBornes(0,3,choixUtilisateur);
			switch (choixUtilisateur)
			{
				case 1:
					indiceUE = donneesMaquettes.trouverIndiceUE();
					donneesMaquettes.formationIndice(indiceFormation)->semestreNumero(semestreChoisi)->ajouterMatiere(donneesMaquettes.ueIndice(indiceUE));
					break;
				case 2:
					indiceUE = donneesMaquettes.trouverIndiceUEcompose();
					donneesMaquettes.formationIndice(indiceFormation)->semestreNumero(semestreChoisi)->ajouterMatiere(donneesMaquettes.ueComposeIndice(indiceUE));
					break;
				case 3:
					indiceUE = donneesMaquettes.trouverIndiceUEchoix();
					donneesMaquettes.formationIndice(indiceFormation)->semestreNumero(semestreChoisi)->ajouterMatiere(donneesMaquettes.ueChoixIndice(indiceUE));
					break;
				default:
					break;
			}
		}
	}
}

void afficheur::menuSupprimerUEDansFormation(int indiceFormation)
{
	int semestreChoisi = -1;
	cout << "Choisissez le semestre dans le quel vous voulez supprimer une UE : " << endl;
	cout << "[1] Le premier semestre." << endl;
	cout << "[2] Le deuxieme semestre." << endl;
	cout << "[0] Quitter." << endl;
	saisirEntierEntreDeuxBornes(0,2,semestreChoisi);
	if (semestreChoisi != 0)
	{
		semestreChoisi--;
		donneesMaquettes.formationIndice(indiceFormation)->semestreNumero(semestreChoisi)->menuSupprimerMatiere();
	}
}

uesimple* afficheur::nouvelleUEaCreer()
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


ecue* afficheur::nouvelleECUEaCreer()
{
	std::string codeMatiere, intitule;
	int coefficient, heure_cours, heure_td, heure_tp;
	saisirDonneesCommunesECUEetUE(codeMatiere, intitule, coefficient, heure_cours, heure_td, heure_tp);
	cout << endl;
	ecue *nouvelleECUE = new ecue{codeMatiere, intitule, coefficient, heure_cours, heure_td, heure_tp};
	return nouvelleECUE;
}


uecompose* afficheur::nouvelleUEcomposeaCreer()
{
	std::string codeMatiere, intitule;
	int coefficient, ects;
	saisirDonneesMatiere(codeMatiere, intitule, coefficient);
	cout << endl;
	cout << "Entrez le nombre d'ECTS : ";
	cin >> ects;
	uecompose *nouvelleUE = new uecompose{codeMatiere, intitule, coefficient, ects};
	return nouvelleUE;
}

uechoix* afficheur::nouvelleUEchoixaCreer()
{
	std::string codeMatiere, intitule;
	int coefficient, ects;
	saisirDonneesMatiere(codeMatiere, intitule, coefficient);
	cout << endl;
	cout << "Entrez le nombre d'ECTS : ";
	cin >> ects;
	uechoix *nouvelleUE = new uechoix{codeMatiere, intitule, coefficient, ects};
	return nouvelleUE;
}

formation* afficheur::nouvelleFormationaCreer()
{
	std::string domaine, mention, parcours, niveau ;
    int annee, anneeNiveau, semestreInt ;
    cout << "Entrez le nom de la domaine : ";
    cin >> std::ws;
    getline(cin,domaine);
    cout << endl;
    cout << "Entrez le nom de la mention : ";
    cin >> std::ws;
    getline(cin,mention);
    cout << endl;
    cout << "Entrez le nom du parcours : ";
    cin >> std::ws;
    getline(cin,parcours);
    cout << endl;
    cout << "Entrez l'annee de debut de la formation : ";
    cin >> annee;
    cout << endl;
    cout << "Entrez le niveau : ";
    cin >> std::ws;
    getline(cin,niveau);
    cout << endl;
    cout << "Entrez l'annee d'étude : ";
    cin >> anneeNiveau;
    cout << endl;
    semestreInt = anneeNiveau*2-1;
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


void afficheur::menuAjouterUneUEchoix()
{
	uechoix *ueAAjouter;
	int choixUtilisateur = -1;
	while (choixUtilisateur != 0 && choixUtilisateur != 1)
	{
		ueAAjouter = nouvelleUEchoixaCreer();
		cout << "Confirmez vous la creation de l'UE : " << endl;
		ueAAjouter->afficher(std::cout);
		cout << "[1] Oui." << endl;
		cout << "[2] Non je veux en creer une autre." << endl;
		cout << "[0] Quitter sans la creer." << endl;
		saisirEntierEntreDeuxBornes(0,2,choixUtilisateur);
		switch (choixUtilisateur)
		{
			case 1:
				donneesMaquettes.ajouterUEchoix(ueAAjouter);
				break;
            case 2:
                break;
			default:
				break;
		}
	}
}

void afficheur::menuAjouterUneUEcompose()
{
	uecompose *ueAAjouter;
	int choixUtilisateur = -1;
	while (choixUtilisateur != 0 && choixUtilisateur != 1)
	{
		ueAAjouter = nouvelleUEcomposeaCreer();
		cout << "Confirmez vous la creation de l'UE : " << endl;
		ueAAjouter->afficher(std::cout);
		cout << "[1] Oui." << endl;
		cout << "[2] Non je veux en creer une autre." << endl;
		cout << "[0] Quitter sans la creer." << endl;
		saisirEntierEntreDeuxBornes(0,2,choixUtilisateur);
		switch (choixUtilisateur)
		{
			case 1:
				donneesMaquettes.ajouterUEcompose(ueAAjouter);
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


void afficheur::menuSupprimerUneUEchoix()
{
	int choixUtilisateur = -1;
	int indiceUEaSupprimer;
	indiceUEaSupprimer = donneesMaquettes.trouverIndiceUEchoix();
	while (choixUtilisateur != 0 && choixUtilisateur != 1)
	{
		cout << "Voulez vous supprimer l'UE : " << endl;
		cout << "[1] Oui." << endl;
		cout << "[2] Non je veux en choisir une autre." << endl;
		cout << "[0] Quitter sans la supprimer." << endl;
		saisirEntierEntreDeuxBornes(0,2,choixUtilisateur);
		switch (choixUtilisateur)
		{
			case 1:
				donneesMaquettes.supprimerUEchoix(indiceUEaSupprimer);
				break;
			case 2:
				indiceUEaSupprimer = donneesMaquettes.trouverIndiceUEchoix();
				break;
			default:
				break;
		}
	}
}

void afficheur::menuSupprimerUneUEcompose()
{
	int choixUtilisateur = -1;
	int indiceUEaSupprimer;
	indiceUEaSupprimer = donneesMaquettes.trouverIndiceUEcompose();
	while (choixUtilisateur != 0 && choixUtilisateur != 1)
	{
		cout << "Voulez vous supprimer l'UE : " << endl;
		cout << "[1] Oui." << endl;
		cout << "[2] Non je veux en choisir une autre." << endl;
		cout << "[0] Quitter sans la supprimer." << endl;
		saisirEntierEntreDeuxBornes(0,2,choixUtilisateur);
		switch (choixUtilisateur)
		{
			case 1:
				donneesMaquettes.supprimerUEcompose(indiceUEaSupprimer);
				break;
			case 2:
				indiceUEaSupprimer = donneesMaquettes.trouverIndiceUEcompose();
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
