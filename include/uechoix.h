#ifndef UECHOIX_H
#define UECHOIX_H

#include "ue.h"
#include <vector>

class uechoix : public ue
{
public:
    uechoix();
    ~uechoix();
    vector <ue*> getUEDispo() const ;
private:
    vector <ue*> d_choix_disponible_ue;
};

#endif // UECHOIX_H
