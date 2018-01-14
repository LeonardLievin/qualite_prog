#include "../Headers/exportation.h"

// constructeur, destructeur
exportation::exportation()
{}

exportation::~exportation()
{}

// méthode retour
string exportation::definirNomFichier()
{
    string fichier;
    cout << "Choisir nom du fichier à creer : ";
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
        cout << "Le fichier \""<<nomFichier<<"\" existe deja" <<endl ;
        cout << "Voulez vous le remplacer (oui ou non) ? " <<endl ;
        cin >> reponse ;
        if (reponse == "oui") return true ;
        else return false ;
    }
    else return true;
}


// méthode modificateur

void exportation::ueAexporter( std::vector <uesimple*> listeUE )
{

    for (int i =0 ; i < listeUE.size() ; i++)
    {
        ensembleUEsimple.push_back(listeUE.at(i)) ;
    }

}

void exportation::uechoixAexporter( std::vector <uechoix*> listeUE )
{

    for (int i =0 ; i < listeUE.size() ; i++)
    {
        ensembleUEchoix.push_back(listeUE.at(i)) ;
    }

}
void exportation::uecomposeAexporter( std::vector <uecompose*> listeUE )
{

    for (int i =0 ; i < listeUE.size() ; i++)
    {
        ensembleUEcompose.push_back(listeUE.at(i)) ;
    }

}


void exportation::mettreFormation(std::vector <formation*> listeFormation)
{
    for (int i = 0 ; i < listeFormation.size() ; i ++)
        ensembleFormation.push_back(listeFormation.at(i)) ;
}

void exportation::ecueAexporter( std::vector <ecue*> listeECUE )
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

        if(ensembleFormation.empty() && ensembleECUE.empty() && ensembleUEsimple.empty() && ensembleUEchoix.empty()
            && ensembleUEcompose.empty() )
        {
            fichier << "!! Aucune valeur dans la base de donnees !! " <<endl ;
        }
        else if(ensembleFormation.empty() && (!ensembleUEchoix.empty() ||
                    !ensembleECUE.empty() || !ensembleUEsimple.empty() ||
                    !ensembleUEcompose.empty()))
        {
            fichier << "Matiere non incluses dans une formation : " << endl ;
            if (ensembleUEsimple.size()>0)fichier << "Liste UEs simples : " <<endl;
                for ( int i = 0 ; i < ensembleUEsimple.size() ; i++)
                {
                    //fichier << "1 ";
                    ensembleUEsimple.at(i)->afficher(fichier);
                }

            if (ensembleECUE.size()>0 )fichier <<endl<< "Liste ECUEs : " <<endl;
                for ( int i = 0 ; i < ensembleECUE.size() ; i++)
                {
                    //fichier << "2 ";
                    if(ensembleECUE.at(i)->dansUeCompose())ensembleECUE.at(i)->afficher(fichier);
                }

            if (ensembleUEcompose.size()>0)fichier <<endl<< "Liste UE composees : " <<endl;
                for ( int i = 0 ; i < ensembleUEcompose.size() ; i++)
                {
                    //fichier << "2 ";
                    ensembleUEcompose.at(i)->afficher(fichier);
                }
            if (ensembleUEchoix.size()>0)fichier <<endl<< "Liste UE choix : " <<endl;
                for ( int i = 0 ; i < ensembleUEchoix.size() ; i++)
                {
                    //fichier << "2 ";
                    ensembleUEchoix.at(i)->afficher(fichier);
                }
        }
        else
        {
            for (int j = 0 ; j < ensembleFormation.size() ; j++)
            {
                fichier << "--------------------------------------------"<<endl;
                ensembleFormation.at(j)->afficher(fichier);
                fichier << "--------------------------------------------"<<endl;
            }
        }

//        int totalCoefficientMaquette = totalCoefficient() ;

  //      fichier << "";

        fichier.close();
        cout << "Fichier \""<< nomFichier << "\" cree" <<endl;

    }

    else
        cout << "Rien n'a ete exporte" << endl;

}
