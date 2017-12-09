#include "uechoix.h"

uechoix::uechoix()
{}

uechoix::~uechoix(){}

vector <ue*> uechoix::getUEDispo() const
{
    return d_choix_disponible_ue;
}
