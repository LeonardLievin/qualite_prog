#include "../Headers/formation.h"

// constructeur, destructeur
formation::formation()
{}
formation::formation(string domaine, string mention, string parcours, int annee, string niveau,
        int anneeNiveau, semestre semestreParametre):
d_domaine{domaine}, d_mention{mention}, d_parcours{parcours}, d_annee{annee}, d_niveau{niveau},
d_anneeNiveau{anneeNiveau} , d_semestre{semestreParametre}
{}
formation::~formation()
{}

// méthode retour
string formation::domaine() const{
    return d_domaine;
}
string formation::mention() const{
    return d_mention;
}
string formation::parcours() const{
    return d_parcours;
}

int formation::annee() const
{
    return d_annee;
}

string formation::niveau() const
{
    return d_niveau ;
}

int formation::anneeNiveau() const
{
    return d_anneeNiveau ;
}



semestre formation::semestreValeur() const
{
    return d_semestre;
}

void formation::setDomaine(string domaine)
{   d_domaine = domaine ;}

void formation::setMention(string mention)
{   d_mention = mention ;}

void formation::setParcours(string parcours)
{   d_parcours = parcours ;}

void formation::setNiveau(string niveau)
{   d_niveau = niveau ;}

void formation::setAnneeNiveau(int anneeNiveau)
{   d_anneeNiveau = anneeNiveau ; }

void formation::setAnnee(int annee)
{   d_annee = annee ; }


void formation::setSemestre (semestre semestreParametre)
{   d_semestre = semestreParametre ;}

void formation::afficher(std::ostream &ost) const
{
    if(d_domaine.size()>0)ost << "Domaine : " << d_domaine << endl;
    if(d_mention.size()>0)ost << "Mention : " << d_mention << endl;
    if(d_parcours.size()>0)ost << "Parcours : " << d_parcours << endl;
    ost << "Année " << d_annee << endl <<d_niveau<<" "<<d_anneeNiveau<<" Semestre "<< d_semestre.getNumero()<< endl<<endl;
}
