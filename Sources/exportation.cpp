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


void exportation::setFormation(formation formationParametre)
{
    d_formation = formationParametre ;
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


        if (d_formation.domaine().size()>0)fichier << "Domaine " <<d_formation.domaine()<<endl;
        if (d_formation.mention().size()>0)fichier <<"Mention "<<d_formation.mention()<<endl;
        if (d_formation.parcours().size()>0)fichier <<"Parcours "<<d_formation.parcours()<<endl;
        if (d_formation.annee()>1)fichier <<"Année "<< d_formation.annee() << " "<<d_formation.niveau()<<" "
        << d_formation.anneeNiveau()<<" Semestre "<< d_formation.semestreValeur().getNumero()<<endl<<endl;



        if (ensembleUEsimple.size()>0)fichier << "Liste UEs simples : " <<endl;
        for ( int i = 0 ; i < ensembleUEsimple.size() ; i++)
        {
            uesimple ueTemporaire = ensembleUEsimple.at(i) ;
            fichier     << "1 "<<ueTemporaire.codeMatiere()<<" "<<ueTemporaire.intitule()<<" "
                        << ueTemporaire.coefficient()<<" "<<ueTemporaire.ects()<<" "
                        << ueTemporaire.nombreHeureCours()<<" "<<ueTemporaire.nombreHeureTd()<<" "
                        << ueTemporaire.nombreHeureTp()
                        <<endl;
        }

        if (ensembleECUE.size()>0)fichier <<endl<< "Liste ECUEs : " <<endl;
        for ( int i = 0 ; i < ensembleECUE.size() ; i++)
        {
            ecue ecueTemporaire = ensembleECUE.at(i) ;
            fichier     << "2 "<<ecueTemporaire.codeMatiere()<<" "<<ecueTemporaire.intitule()<<" "
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
