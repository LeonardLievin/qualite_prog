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

    // m�thode retour
    int numero() const;
    std::vector<matiere*> listeMatieres() const;

// m�thode modificateur
    void ajouterMatiere(matiere* nouvelleMatiere);
    void supprimerMatiere(int i);
    void menuSupprimerMatiere();
    void afficher(std::ostream &ost) const;


private:
    int d_numero ;
    std::vector<matiere*> d_listeMatieres ;
};

#endif // SEMESTRE_H
