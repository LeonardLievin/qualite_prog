#ifndef UE_H
#define UE_H

#include "matiere.h"
#include <vector>

class ue : public matiere
{
public:
    ue();
    ~ue();
    int getEcts() const;

private:
    int d_ects;
};

#endif // UE_H
