#include <iostream>
#include "../Headers/uesimple.h"
#include "../Headers/importation.h"
#include "../Headers/exportation.h"

int main()
{

    importation importa{} ;

    if(importa.execution())
        importa.affichageImport() ;
    /*
    uesimple ues1{};
    ues1.afficher(std::cout);

    ecue ecue1{};
    ecue1.afficher(std::cout);

    uesimple ues2{};
    ues2.afficher(std::cout);

    ecue ecue2{};
    ecue2.afficher(std::cout);

    std::vector <uesimple> listUEsimple ;
    std::vector <ecue> listECUE ;

    listUEsimple.push_back(ues1) ;
    listUEsimple.push_back(ues2) ;

    listECUE.push_back(ecue1) ;
    listECUE.push_back(ecue2) ;

    exportation exporta{} ;

    exporta.ueAexporter(listUEsimple) ;
    exporta.ecueAexporter(listECUE) ;

    exporta.execution();


*/

    return 0;
}
