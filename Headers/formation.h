#ifndef FORMATION_H
#define FORMATION_H

#include "semestre.h"
#include "uesimple.h"
#include <vector>

using std::cout ;
using std::string;
using std::endl;
using std::vector;

class formation
{
public:
    // constructeur, destructeur
    formation();
    formation(string domaine, string mention, string parcours, int annee,
    string niveau,int anneeNiveau, semestre semestreParametre);
    ~formation();

    // methode retour
    string domaine() const;
    string mention() const;
    string parcours() const;
    string niveau() const;
    int annee() const;
    int anneeNiveau() const;
    bool existe() const;
    vector <semestre*> listeSemestres() const;
    semestre* semestreNumero(int numeroSemestre) const;

    // méthode modificateur
    void mettreDomaine(string) ;
    void mettreMention(string) ;
    void mettreParcours(string);
    void mettreNiveau(string) ;
    void mettreAnnee(int) ;
    void mettreAnneeNiveau(int) ;
    //void mettreSemestre (semestre);
    void afficher(std::ostream &ost) const;


private:
    string d_domaine ;
    string d_mention ;
    string d_parcours ;
    string d_niveau ;
    int d_anneeNiveau ;
    int d_annee ;
    vector <semestre*> d_listeSemestres ;
    bool d_existe;

};

#endif // FORMATION_H
