#include "../Headers/matiere.h"

// constructeur, destructeur
matiere::matiere() :
d_code {"code"}, d_intitule{"matiere"}, d_coefficient {1}
{}

matiere::matiere(std::string code_matiere, std::string intitule, int coefficient) :
    d_code {code_matiere}, d_intitule{intitule}, d_coefficient {coefficient}
{}
matiere::~matiere(){}

// méthode retour
std::string matiere::codeMatiere() const{
    return d_code;
}
std::string matiere::intitule() const{
    return d_intitule;
}
int matiere::coefficient() const{
    return d_coefficient;
}

// méthode modificateur

void matiere::afficher(std::ostream& ost) const
{
    ost << d_code << " " << d_intitule << " "<< d_coefficient ;
}
