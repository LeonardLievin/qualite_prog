#include "../include/formation.h"

formation::formation()
{}

formation::formation(string domaine, string mention, string parcours, int annee):d_domaine{domaine}, d_mention{mention}, d_parcours{parcours}, d_annee{annee}
{}

formation::~formation()
{}

string formation::getDomaine() const{
    return d_domaine;
}
string formation::getMention() const{
    return d_mention;
}
string formation::getParcours() const{
    return d_parcours;
}

int formation::getAnnee() const{
    return d_annee;
}

vector <semestre*> formation::getSemestres() const{
    return d_semestre;
}
