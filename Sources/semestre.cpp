#include "../Headers/semestre.h"

// constructeur, destructeur
semestre::semestre(){}
semestre::semestre(int numero):d_numero{numero}
{}
semestre::~semestre(){}

// méthode retour
int semestre::getNumero() const{
    return d_numero;
}
std::vector<ue*> semestre::getUEs() const{
    return d_ue;
}
