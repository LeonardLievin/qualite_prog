#ifndef SEMESTRE_H
#define SEMESTRE_H

#include "ue.h"
#include <vector>

class semestre
{
public:
    // constructeur, destructeur
    semestre();
    semestre(int numero);
    ~semestre();

    // méthode retour
    int getNumero() const;
    std::vector<ue*> getUEs() const;

private:
    int d_numero ;
    std::vector<ue*> d_ue ;
};

#endif // SEMESTRE_H
