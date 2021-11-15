#ifndef SENSIBLE_H_
#define SENSIBLE_H_

#include "Personnage.h"
#include <string>

class Sensible: public Personnage{
    public:
    Sensible(std::string , int pvMax);
    void beAttacked(int dammage);
    void beAttackedVirtual(int dammage);
};


#endif //SENSIBLE_H_