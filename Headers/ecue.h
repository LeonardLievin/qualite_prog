#ifndef ECUE_H
#define ECUE_H

#include "matiere.h"

class ecue : public matiere
{
    public:
        // constructeur, destructeur
        ecue();
        ecue(std::string, std::string, int , int, int, int );
        ~ecue();

        // méthodes retour
        int nombreHeureCours() const;
        int nombreHeureTp() const;
        int nombreHeureTd() const;
        bool dansUeCompose() const;


        // méthodes void
        void mettreNombreHeureCours (int ) ;
        void mettreNombreHeureTp (int ) ;
        void mettreNombreHeureTd (int) ;
        void mettreDansUeCompose(bool);
        void afficher_Ecue(std::ostream& ost) const ;

        // méthodes abstraite
        virtual void afficher(std::ostream& ost) const override;
        virtual int nombreTotalHeure() const override;

    private:
        int d_nombreHeureCours;
        int d_nombreHeureTd;
        int d_nombreHeureTp ;
        bool d_dansUeCompose;

};

#endif // ECUE_H
