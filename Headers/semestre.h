#ifndef SEMESTRE_H
#define SEMESTRE_H

#include "matiere.h"
#include "vector"

class semestre
{
public:
    // constructeur, destructeur
    semestre();
    semestre(int );
    ~semestre();

    // méthode retour
    int numero() const;
    std::vector<matiere*> listeMatieres() const;

    int nombreTotalHeure() const ;
    int nombreHeureCours() const ;
    int nombreHeureTd() const ;
    int nombreHeureTp() const ;

    int totalCoefficient() const;
    int totalHeureCours() const;
    int totalHeureTd() const;
    int totalHeureTp() const;
    int totalEcts() const;

// méthode modificateur
    void ajouterMatiere(matiere* nouvelleMatiere);
    void supprimerMatiere(int i);
    void menuSupprimerMatiere();
    void afficher(std::ostream &ost) const;



private:
    int d_numero ;
    std::vector<matiere*> d_listeMatieres ;
};

#endif // SEMESTRE_H
