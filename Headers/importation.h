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

        void execution() ;
        string recupererNomFichier () ;
        std::ifstream fichierOuvert(string) ;
        void affichageLigne(string) ;

        void creerUE(string , string ,int ,int , int, int , int);
        void creerECUE(string,string, int, int, int, int );

    protected:
    private:
        std::vector<uesimple> ensembleUEsimple;
        std::vector<ecue> ensembleECUE;

};

#endif // IMPORTATION_H
