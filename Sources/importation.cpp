#include "../Headers/importation.h"

importation::importation()
{}

importation::~importation()
{}

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
    return fichier ;
}

void importation::affichageImport()
{
    cout << "Liste des UEs simples : "<<endl;
    for ( int i =0 ; i< nombreUEsimple() ; i++)
    {
        ueSimpleAuRang(i)->afficher(std::cout);
    }

    cout << endl<<"Liste des ECUEs simples : "<<endl;
    for ( int i =0 ; i< nombreECUE() ; i++)
    {
        ecueAuRang(i)->afficher(std::cout);
    }
}

void importation::creerUE(string code_matiere,string intitule, int coefficient, int ects, int heure_cours, int heure_td, int heure_tp )
{
    uesimple UEtemporaire{code_matiere,intitule, coefficient, ects, heure_cours, heure_td, heure_tp };
    ensembleUEsimple.push_back(UEtemporaire);
    cout << "L'UE : "<< intitule << " a été créée" << endl ;
}

void importation::creerECUE(string code_matiere,string intitule, int coefficient, int heure_cours, int heure_td, int heure_tp )
{
    ecue ECUEtemporaire{code_matiere,intitule, coefficient, heure_cours, heure_td, heure_tp };
    ensembleECUE.push_back(ECUEtemporaire);
    cout << "L'ECUE : "<< intitule << " a été créée" << endl ;
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
    code_matiere = decoupageMot[1] ;
    intitule = decoupageMot[2] ;
    coefficient = atoi(decoupageMot[3].c_str());

    if (type == "ecue")
    {
        heure_cours = atoi(decoupageMot[4].c_str()) ;
        heure_td = atoi(decoupageMot[5].c_str()) ;
        heure_tp = atoi(decoupageMot[6].c_str()) ;
        creerECUE(code_matiere,intitule,coefficient,heure_cours, heure_td, heure_tp) ;
    }
    if (type == "uesimple")
    {
        ects = atoi(decoupageMot[4].c_str());
        heure_cours = atoi(decoupageMot[5].c_str()) ;
        heure_td = atoi(decoupageMot[6].c_str()) ;
        heure_tp = atoi(decoupageMot[7].c_str()) ;
        creerUE(code_matiere,intitule,coefficient,ects,heure_cours, heure_td, heure_tp) ;
    }
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
            affichageLigne(contenu) ;
            cout << endl ;
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


