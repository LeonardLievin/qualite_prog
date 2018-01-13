#include "../Headers/formation.h"

// constructeur, destructeur
formation::formation()
{}

formation::formation(string domaine, string mention, string parcours, int annee, string niveau,
    int anneeNiveau, semestre semestreParametre):
        d_domaine{domaine}, d_mention{mention}, d_parcours{parcours}, d_annee{annee}, d_niveau{niveau},
        d_anneeNiveau{anneeNiveau}
{
    int numeroSemestre = semestreParametre.numero() ;
    d_listeSemestres.push_back(new semestre(numeroSemestre));
	d_listeSemestres.push_back(new semestre(numeroSemestre+1));
}

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

bool formation::existe() const
{
    return d_existe ;
}

vector <semestre*> formation::listeSemestres() const{
    return d_listeSemestres;
}

// méthode modificateur

void formation::mettreDomaine(string domaine)
{   d_domaine = domaine ;}

void formation::mettreMention(string mention)
{   d_mention = mention ;}

void formation::mettreParcours(string parcours)
{   d_parcours = parcours ;}

void formation::mettreNiveau(string niveau)
{   d_niveau = niveau ;}

void formation::mettreAnneeNiveau(int anneeNiveau)
{   d_anneeNiveau = anneeNiveau ; }

void formation::mettreAnnee(int annee)
{   d_annee = annee ; }



void formation::afficher(std::ostream &ost) const
{
    if(d_domaine.size()>0)ost << "Domaine : " << d_domaine << endl;
    if(d_mention.size()>0)ost << "Mention : " << d_mention << endl;
    if(d_parcours.size()>0)ost << "Parcours : " << d_parcours << endl;
    if(d_annee>1 && d_annee<2500)ost << "Année " << d_annee << " " <<d_niveau<<" "<<d_anneeNiveau<<endl;
    for (int i = 0; i < listeSemestres().size(); i++)
	{
		listeSemestres()[i]->afficher(ost);
		ost << endl;
	}
}


semestre* formation::semestreNumero(int numeroSemestre) const
{
	return d_listeSemestres[numeroSemestre];
}
