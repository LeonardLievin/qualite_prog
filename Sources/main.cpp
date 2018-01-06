#include <iostream>
#include "../Headers/uesimple.h"
#include "../Headers/importation.h"

int main()
{

    importation importa{} ;

    if(importa.execution())
        importa.affichageImport() ;

    return 0;
}
