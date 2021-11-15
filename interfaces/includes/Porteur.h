#ifndef PORTEUR_H_
#define PORTEUR_H_

#include "AVetement.h"

class Porteur{

    private:
    AVetement *_vetement;

    public:
    Porteur(AVetement *vetement);

    int getIsolation();


    
};

#endif //PORTEUR_H_