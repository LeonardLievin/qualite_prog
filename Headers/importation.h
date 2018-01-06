#ifndef IMPORTATION_H
#define IMPORTATION_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "uesimple.h"
#include "ecue.h"

using std::cout ;
using std::string;
using std::cin;
using std::endl;

class importation
{
    public:
        importation();
        virtual ~importation();

        bool execution() ;
        string recupererNomFichier () ;
        std::ifstream fichierOuvert(string) ;
        void affichageLigne(string) ;
        void affichageImport();

        void creerUE(string , string ,int ,int , int, int , int);
        void creerECUE(string,string, int, int, int, int );

        int nombreUEsimple() ;
        uesimple* ueSimpleAuRang( int ) ;
        int nombreECUE() ;
        ecue* ecueAuRang( int ) ;


    protected:
    private:
        std::vector<uesimple> ensembleUEsimple;
        std::vector<ecue> ensembleECUE;

};

#endif // IMPORTATION_H
