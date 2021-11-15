#include <string>
#include "Personnage.h"

//Class Personnage:

Personnage::Personnage(){
    _name = "undefined";
    _pvMax = -1;
    _pv = -1;
}


Personnage::Personnage(std::string name , int pvMax ){
    _name = name;
    _pvMax = pvMax;
    _pv = _pvMax;
}

void Personnage::beAttacked(int dammage){
    _pv -= dammage;
    if( _pv < 0){
        _pv = 0;
    }
}

void Personnage::beAttackedVirtual(int dammage){
    beAttacked(dammage);
}

void Personnage::beHealed(int heal){
    _pv += heal;
    if(_pv > _pvMax){
        _pv = _pvMax;
    }
}

std::string Personnage::getName(){
    return _name;
}

int Personnage::getPv(){
    return _pv;
}