#ifndef SEMESTRE_H
#define SEMESTRE_H
#include "ue.h"
#include <vector>



class semestre
{
public:
    semestre();
    semestre(int numero);
    ~semestre();
    int getNumero() const;
    vector<ue*> getUEs() const;

private:
    int d_numero ;
    vector<ue*> d_ue ;
};

#endif // SEMESTRE_H
