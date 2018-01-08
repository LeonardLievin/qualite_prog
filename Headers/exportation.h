#ifndef EXPORTATION_H
#define EXPORTATION_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "uesimple.h"
#include "formation.h"

using std::cout ;
using std::string;
using std::cin;
using std::endl;
using std::vector;

class exportation
{
    public:
        exportation();
        virtual ~exportation();

        void execution();

        string definirNomFichier();
        bool nomFichierExiste(string) ;
        bool creationFichier( bool, string) ;

        void ueAexporter( std::vector<uesimple> ) ;
        void ecueAexporter( std::vector<ecue> ) ;
        void setFormation( formation);

    protected:
    private:
        std::vector<uesimple> ensembleUEsimple;
        std::vector<ecue> ensembleECUE;
        formation d_formation ;

};

#endif // EXPORTATION_H
