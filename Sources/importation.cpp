#include "../Headers/importation.h"

// constructeur, destructeur

importation::importation()
{}

importation::~importation()
{}

// méthode retour

int importation::nombreECUE()
{
    return ensembleUEsimple.size();
}

ecue* importation::ecueAuRang( int rang)
{
    ensembleECUE.at(rang) ;
}

int importation::nombreUEsimple()
{
    return ensembleUEsimple.size();
}

uesimple* importation::ueSimpleAuRang( int rang)
{
    ensembleUEsimple.at(rang) ;
}

string importation::recupererNomFichier ()
{
    string nomFichier ;
    cout << "Entrer le nom du fichier à explorer : " ;
    cin >> nomFichier ;
    return nomFichier ;
}

std::ifstream importation::fichierOuvert( string nomFichier)
{
    std::ifstream fichier(nomFichier, std::ios::in);  // on ouvre en lecture
    if(fichier) cout << "Fichier \""<< nomFichier<<"\" ouvert ... " << endl<<endl;
    return fichier ;
}


bool importation::execution()
{
    string nomFichier =  recupererNomFichier() ;
    std::ifstream fichier = fichierOuvert(nomFichier);

    if(fichier)
    {
        string contenu;
        while(getline(fichier, contenu))
        {
            if (!contenu.empty())affichageLigne(contenu) ;
        }

        fichier.close();
        return true ;
    }
    else
    {
        cout << "Le fichier n'existe pas" << endl;
        return false;
    }

}

// méthode modificateur

void importation::affichageUeSimple()
{
     if(nombreUEsimple()>0)cout << "Liste des UEs simples : "<<endl;
    for ( int i =0 ; i< nombreUEsimple() ; i++)
    {
        ueSimpleAuRang(i)->afficher(std::cout);
    }
}

void importation::affichageEcue()
{
    if(nombreECUE()>0)cout << endl<<"Liste des ECUEs simples : "<<endl;
    for ( int i =0 ; i< nombreECUE() ; i++)
    {
        ecueAuRang(i)->afficher(std::cout);
    }
}

void importation::affichageImport()
{
    d_formation.afficher(std::cout);

    affichageUeSimple();

    affichageEcue();

}

void importation::ajoutUE( uesimple ue )
{
    ensembleUEsimple.push_back(ue);
}

void importation::ajoutECUE( ecue ecueTemporaire )
{
    ensembleECUE.push_back(ecueTemporaire);
}

void importation::affichageLigne( string ligne)
{
    string type, matiere, mot, code_matiere, intitule;
    int coefficient, heure_cours, heure_td, heure_tp ,ects;
    std::vector <string> decoupageMot ;

    std::istringstream lectureLigne(ligne);
    while ( std::getline( lectureLigne, mot, ' ' ) )
    {
        decoupageMot.push_back(mot) ;
    }

    type = decoupageMot[0];

    if (type == "Domaine")
    {
        string domaine;
        for (int i =1 ; i<decoupageMot.size() ; i++)
        {
            domaine += decoupageMot.at(i) +" " ;
        }
        d_formation.mettreDomaine(domaine) ;
    }
    else if (type == "Mention")
    {
        string mention;
        for (int i =1 ; i<decoupageMot.size() ; i++)
        {
            mention += decoupageMot.at(i)+" " ;
        }
        d_formation.mettreMention(mention) ;
    }
    else if (type == "Parcours")
    {
        string parcours;
        for (int i =1 ; i<decoupageMot.size() ; i++)
        {
            parcours += decoupageMot.at(i)+" " ;
        }
        d_formation.mettreParcours(parcours) ;

    }
    else if (type == "Année")
    {

        d_formation.mettreAnnee(atoi(decoupageMot.at(1).c_str())) ;
        d_formation.mettreNiveau(decoupageMot.at(2)) ;
        d_formation.mettreAnneeNiveau(atoi(decoupageMot.at(3).c_str())) ;

        semestre semestreTemporaire{atoi(decoupageMot.at(5).c_str()) } ;
        d_formation.mettreSemestre(semestreTemporaire) ;

    }
    else if (type == "2" || type == "1")
    {
        code_matiere = decoupageMot[1] ;
        intitule = decoupageMot[2] ;
        coefficient = atoi(decoupageMot[3].c_str());
    }
    else if (type == "2")
    {
        heure_cours = atoi(decoupageMot[4].c_str()) ;
        heure_td = atoi(decoupageMot[5].c_str()) ;
        heure_tp = atoi(decoupageMot[6].c_str()) ;
        ecue ecueTemporaire {code_matiere,intitule,coefficient,heure_cours, heure_td, heure_tp} ;
        ajoutECUE(ecueTemporaire) ;
    }
    else if (type == "1")
    {
        ects = atoi(decoupageMot[4].c_str());
        heure_cours = atoi(decoupageMot[5].c_str()) ;
        heure_td = atoi(decoupageMot[6].c_str()) ;
        heure_tp = atoi(decoupageMot[7].c_str()) ;
        uesimple ueTemporaire {code_matiere,intitule,coefficient,ects,heure_cours, heure_td, heure_tp};
         ajoutUE(ueTemporaire) ;
    }

}





