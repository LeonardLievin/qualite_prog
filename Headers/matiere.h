#ifndef MATIERE_H
#define MATIERE_H
#include <iostream>

class matiere
{
public:
    // constructeur, destructeur
    matiere();
    matiere(std::string codeMatiere,
            std::string intitule,int coefficient);
    virtual ~matiere();

    // méthode retour
    std::string codeMatiere() const;
    std::string intitule() const;
    int coefficient() const;

    //méthode modificateur
    void setIntitule(const std::string& intitule);
    void setCoefficient(int coefficient);

    // méthode abstraite
    virtual int nombreTotalHeure() const = 0;
    virtual void afficher(std::ostream& ost) const =0;


private:
    std::string d_code ;
    std::string d_intitule ;
    int d_coefficient ;
};

#endif // MATIERE_H
