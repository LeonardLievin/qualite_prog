#ifndef ECUE_H
#define ECUE_H

#include "matiere.h"

class ecue : public matiere
{
    public:
        ecue();
        ~ecue();
        int getNbCours() const;
        int getNbTp() const;
        int getNbTd() const;
        virtual int nbTotalHeure() const override;

    private:
        int d_nb_cours;
        int d_nb_td;
        int d_nb_tp ;

};

#endif // ECUE_H
