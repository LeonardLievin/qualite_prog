#ifndef EXPORTATION_H
#define EXPORTATION_H

#include <fstream>

#include "uesimple.h"
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
        void ueAexporter( std::vector<uesimple> ) ;
        void ecueAexporter( std::vector<ecue> ) ;
        void mettreFormation( formation);

    protected:
    private:
        std::vector<uesimple> ensembleUEsimple;
        std::vector<ecue> ensembleECUE;
        formation d_formation ;


};

#endif // EXPORTATION_H
