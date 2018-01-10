#ifndef IMPORTATION_H
#define IMPORTATION_H

#include <fstream>
#include <sstream>

#include "uesimple.h"
#include "formation.h"
#include "stockageDonnees.h"

using std::cin;

class importation
{
    public:
        // constructeur destructeur
        importation();
        virtual ~importation();

        // methode retour
        bool execution(stockageDonnees* ) ;
        int nombreECUE() ;
        int nombreUEsimple() ;
        int entier(string);
        string recupererNomFichier () ;
        string recupererLigne(std::vector<string>) ;
        std::ifstream fichierOuvert(string) ;
        uesimple ueSimpleAuRang( int ) ;
        ecue ecueAuRang( int ) ;

        // methode modificateur
        void affichageLigne(string) ;
        void affichageImport();
        void affichageUeSimple();
        void affichageEcue();
        void ajoutUE(uesimple);
        void ajoutECUE(ecue );



    protected:
    private:
        formation d_formation ;
        std::vector<uesimple> ensembleUEsimple;
        std::vector<ecue> ensembleECUE;
        stockageDonnees* baseDeDonnees ;
};

#endif // IMPORTATION_H
