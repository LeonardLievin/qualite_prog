#ifndef EXPORTATION_H
#define EXPORTATION_H

#include <fstream>

#include "uesimple.h"
#include "uechoix.h"
#include "uecompose.h"
#include "formation.h"

using std::cin;

class exportation
{
    public:
        // constructeur, destructeur
        exportation();
        ~exportation();

        // methode retour
        string definirNomFichier();
        bool nomFichierExiste(string) ;
        bool creationFichier( bool, string) ;

        // methode modificateur
        void execution();

        void ueAexporter( std::vector<uesimple*> ) ;
        void ecueAexporter( std::vector<ecue*> ) ;
        void uechoixAexporter( std::vector<uechoix*> ) ;
        void uecomposeAexporter( std::vector<uecompose*> ) ;

        void mettreFormation( std::vector<formation*>);

    protected:
    private:
        std::vector<uesimple*> ensembleUEsimple;
        std::vector<uecompose*> ensembleUEcompose;
        std::vector<ecue*> ensembleECUE;
        std::vector<formation*> ensembleFormation;


};

#endif // EXPORTATION_H
