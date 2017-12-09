#include "ecue.h"

ecue::ecue(){}

ecue::~ecue(){}

int ecue::getNbCours() const{
    return d_nb_cours;
}

int ecue::getNbTp() const{
    return d_nb_tp;
}

int ecue::getNbTd() const{
    return d_nb_td;
}

int ecue::nbTotalHeure() const{
    return d_nb_cours + d_nb_td + d_nb_tp;
}
