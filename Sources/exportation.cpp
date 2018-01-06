#include "../Headers/exportation.h"

exportation::exportation()
{}

exportation::~exportation()
{}

string exportation::definirNomFichier()
{
    string fichier;
    cout << "Choisir nom du fichier à créer : ";
    cin >> fichier ;
    return fichier ;
}

bool exportation::nomFichierExiste(string nomFichier)
{
    std::ifstream fichier(nomFichier);
    return !fichier.fail();
}

bool exportation::creationFichier( bool fichierExiste, string nomFichier)
{
    if (fichierExiste)
    {
        string reponse ;
        cout << "Le fichier \""<<nomFichier<<"\" existe déjà" <<endl ;
        cout << "Voulez vous le remplacer (oui ou non) ? " <<endl ;
        cin >> reponse ;
        if (reponse == "oui") return true ;
        else return false ;
    }
    else return true;
}



void exportation::execution()
{
    string libelle = "ecue" ;
    string matiere = "maths" ;
    int coefficient = 3 ;
    string libelle2 = "ue" ;
    string matiere2 = "svt" ;
    int coefficient2 = 2 ;
    vector <string> tableauLibelle ;
    vector< string> tableauMatiere;
    vector < int > tableauCoefficient ;
    tableauLibelle.push_back(libelle);
    tableauLibelle.push_back(libelle2);
    tableauMatiere.push_back(matiere);
    tableauMatiere.push_back(matiere2);
    tableauCoefficient.push_back(coefficient);
    tableauCoefficient.push_back(coefficient2);

    string nomFichier ;

    nomFichier = definirNomFichier() ;

    bool creerFichier = creationFichier(nomFichierExiste(nomFichier), nomFichier) ;

    std::ofstream fichier(nomFichier , std::ios::out) ;
    if(fichier && creerFichier)
    {
        for ( int i = 0 ; i < tableauLibelle.size() ; i++)
        {
            fichier << tableauLibelle[i]<<" "<<tableauMatiere[i]<<" "<<tableauCoefficient[i]<<endl;
        }
        fichier.close();
        cout << "Fichier \""<< nomFichier << "\" créé" <<endl;
    }

    else
        cout << "Rien n'a été exporté" << endl;

}
