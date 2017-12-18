#include "../Headers/matiere.h"

// constructeur, destructeur
matiere::matiere(){}
matiere::matiere(std::string code_matiere, std::string intitule, int coefficient) :
    d_code {code_matiere}, d_intitule{intitule}, d_coefficient {coefficient}
{}
matiere::~matiere(){}

// m�thode retour
std::string matiere::codeMatiere() const{
    return d_code;
}
std::string matiere::intitule() const{
    return d_intitule;
}
int matiere::coefficient() const{
    return d_coefficient;
}