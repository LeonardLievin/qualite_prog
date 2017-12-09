#ifndef UESIMPLE_H
#define UESIMPLE_H

#include "ue.h"

class uesimple : public ue
{
public:
    uesimple();
    ~uesimple() ;
    int getNbCours() const ;
    int getNbTd() const ;
    int getNbTp() const ;

private:
    int d_nb_cours;
    int d_nb_td;
    int d_nb_tp ;
};

#endif // UESIMPLE_H
