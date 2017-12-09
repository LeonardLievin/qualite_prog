#ifndef MATIERE_H
#define MATIERE_H
#include <iostream>

using namespace std;

class matiere
{
public:
    matiere();
    ~matiere();
    string getCode() const;
    string getIntitule() const;
    int getCoeff() const;
    virtual int nbTotalHeure() const = 0;

private:
    string d_code ;
    string d_intitule ;
    int d_coefficient ;
};

#endif // MATIERE_H
