#include "../include/semestre.h"

semestre::semestre(){}

semestre::semestre(int numero):d_numero{numero}
{}

semestre::~semestre(){}

int semestre::getNumero() const{
    return d_numero;
}

vector<ue*> semestre::getUEs() const{
    return d_ue;
}
