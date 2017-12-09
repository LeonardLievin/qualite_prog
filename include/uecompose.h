#ifndef UECOMPOSE_H
#define UECOMPOSE_H

#include "ue.h"
#include "ecue.h"


class uecompose : public ue
{
public:
    uecompose();
    ~uecompose();
    vector < ecue* > getEnsembleEcue() const ;

private:
    vector < ecue* > d_ensemble_ecue ;

};

#endif // UECOMPOSE_H
