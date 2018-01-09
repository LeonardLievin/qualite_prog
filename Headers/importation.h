#ifndef IMPORTATION_H
#define IMPORTATION_H

#include <fstream>
#include <sstream>

#include "uesimple.h"
#include "formation.h"

using std::cin;

class importation
{
    public:
        // constructeur destructeur
        importation();
        virtual ~importation();

        // methode retour
        bool execution() ;
        int nombreECUE() ;
        int nombreUEsimple() ;
        string recupererNomFichier () ;
        std::ifstream fichierOuvert(string) ;
        uesimple* ueSimpleAuRang( int ) ;
        ecue* ecueAuRang( int ) ;

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

};

#endif // IMPORTATION_H
