#include "Sensible.h"
#include <string>

Sensible::Sensible(std::string name , int pvMax) : Personnage(name , pvMax) { //Personnage(name , pvMax) is super in Java 

}

void Sensible::beAttacked(int dammage)
{
    _pv -= dammage + 1; //les sensibles perdent 1 pv en plus
    if (_pv < 0)
    {
        _pv = 0;
    }
}

void Sensible::beAttackedVirtual(int dammage){
    beAttacked(dammage);
}