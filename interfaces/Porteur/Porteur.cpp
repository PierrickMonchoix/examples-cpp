#include "Porteur.h"
#include "AVetement.h"

Porteur::Porteur(AVetement *vetement) : _vetement(vetement) { }

int Porteur::getIsolation(){
    return _vetement->getIsolationTermique();
}

