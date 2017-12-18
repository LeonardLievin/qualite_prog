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

        // m�thodes retour
        int nombreHeureCours() const;
        int nombreHeureTp() const;
        int nombreHeureTd() const;

        // m�thodes void
        void setNbCours (int h_cours) ;
        void setNbTp (int h_tp) ;
        void setNbTd (int h_td) ;

        // m�thodes abstraite
        virtual void afficher(std::ostream& ost) const override;
        virtual int nombreTotalHeure() const override;

    private:
        int d_nombreHeureCours;
        int d_nombreHeureTd;
        int d_nombreHeureTp ;

};

#endif // ECUE_H
