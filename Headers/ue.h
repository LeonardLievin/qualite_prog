#ifndef UE_H
#define UE_H

#include "matiere.h"
#include <vector>

class ue : public matiere
{
public:
    // constructeur , destructeur
    ue();
    ue(std::string& code_matiere, std::string& intitule, int coefficient, int ects);
    virtual ~ue();

    // methode retour
    int ects() const;

    // méthode abstraite
    virtual void afficher(std::ostream& ost)const ;
    virtual int heureCours() const = 0;
    //virtual int nombreTotalHeure() const =0 ;

private:
    int d_ects;
};

#endif // UE_H
