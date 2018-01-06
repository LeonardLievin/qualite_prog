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

void exportation::ueAexporter( std::vector <uesimple> listeUE )
{
    for (int i =0 ; i < listeUE.size() ; i++)
    {
        ensembleUEsimple.push_back(listeUE.at(i)) ;
    }
}

void exportation::ecueAexporter( std::vector <ecue> listeECUE )
{
    for (int i =0 ; i < listeECUE.size() ; i++)
    {
        ensembleECUE.push_back(listeECUE.at(i)) ;
    }
}

void exportation::execution()
{

    string nomFichier ;

    nomFichier = definirNomFichier() ;

    bool creerFichier = creationFichier(nomFichierExiste(nomFichier), nomFichier) ;

    std::ofstream fichier(nomFichier , std::ios::out) ;
    if(fichier && creerFichier)
    {
        fichier << "Liste UEs simples : " <<endl;
        for ( int i = 0 ; i < ensembleUEsimple.size() ; i++)
        {
            uesimple ueTemporaire = ensembleUEsimple.at(i) ;
            fichier     << ueTemporaire.codeMatiere()<<" "<<ueTemporaire.intitule()<<" "
                        << ueTemporaire.coefficient()<<" "<<ueTemporaire.ects()<<" "
                        << ueTemporaire.nombreHeureCours()<<" "<<ueTemporaire.nombreHeureTd()<<" "
                        << ueTemporaire.nombreHeureTp()
                        <<endl;
        }

        fichier <<endl<< "Liste ECUEs : " <<endl;
        for ( int i = 0 ; i < ensembleECUE.size() ; i++)
        {
            ecue ecueTemporaire = ensembleECUE.at(i) ;
            fichier     << ecueTemporaire.codeMatiere()<<" "<<ecueTemporaire.intitule()<<" "
                        << ecueTemporaire.coefficient()<<" "
                        << ecueTemporaire.nombreHeureCours()<<" "<<ecueTemporaire.nombreHeureTd()<<" "
                        << ecueTemporaire.nombreHeureTp()
                        <<endl;
        }

        fichier.close();
        cout << "Fichier \""<< nomFichier << "\" créé" <<endl;
    }

    else
        cout << "Rien n'a été exporté" << endl;

}
