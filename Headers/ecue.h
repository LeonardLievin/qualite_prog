#ifndef ECUE_H
#define ECUE_H

#include "matiere.h"

class ecue : public matiere
{
    public:
        // constructeur, destructeur
        ecue();
        ecue(std::string code_matiere, std::string intitule,
             int coefficient, int heure_cours, int heure_td, int heure_tp );
        ~ecue();

        // méthodes retour
        int nombreHeureCours() const;
        int nombreHeureTp() const;
        int nombreHeureTd() const;

        // méthodes void
        void mettreNombreHeureCours (int heure_cours) ;
        void mettreNombreHeureTp (int heure_tp) ;
        void mettreNombreHeureTd (int heure_td) ;
        void afficher_Ecue(std::ostream& ost) const ;

        // méthodes abstraite
        virtual void afficher(std::ostream& ost) const override;
        virtual int nombreTotalHeure() const override;

    private:
        int d_nombreHeureCours;
        int d_nombreHeureTd;
        int d_nombreHeureTp ;

};

#endif // ECUE_H
