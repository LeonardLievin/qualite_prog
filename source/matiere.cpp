#include "matiere.h"

matiere::matiere(){}

matiere::~matiere(){}

string matiere::getCode() const{
    return d_code;
}

string matiere::getIntitule() const{
    return d_intitule;
}

int matiere::getCoeff() const{
    return d_coefficient;
}
