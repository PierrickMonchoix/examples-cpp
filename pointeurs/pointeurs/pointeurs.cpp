#include "pointeurs.h"

int variable = 0;
int* pointeur = (int*) 0;

void initVariable(int value){
    variable = value;
    pointeur = &variable;
}

int getValue(){
    return *pointeur;
}

int* getAdress(){
    return pointeur;
}
