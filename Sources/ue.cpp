#include "../Headers/ue.h"

// constructeur , destructeur
ue::ue(){}
ue::ue(std::string& codeMatiere,std::string& intitule,int coefficient,int ects):
    matiere(codeMatiere,intitule,coefficient),d_ects(ects)
{}
ue::~ue(){}

// methode retour
int ue::ects() const{
    return d_ects;
}


// methode modificateur

void ue::afficher(std::ostream &ost) const{
	ost<<d_ects ;
}
