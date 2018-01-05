#ifndef EXPORTATION_H
#define EXPORTATION_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

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

    protected:
    private:
};

#endif // EXPORTATION_H
