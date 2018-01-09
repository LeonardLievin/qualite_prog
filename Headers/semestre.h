#ifndef SEMESTRE_H
#define SEMESTRE_H

#include "ue.h"

class semestre
{
public:
    // constructeur, destructeur
    semestre();
    semestre(int );
    ~semestre();

    // méthode retour
    int numero() const;
    std::vector<ue*> mettreUEs() const;

private:
    int d_numero ;
    std::vector<ue*> d_ue ;
};

#endif // SEMESTRE_H
