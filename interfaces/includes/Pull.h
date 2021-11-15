#ifndef PULL_H_
#define PULL_H_

#include "AVetement.h"

class Pull: public AVetement{
    private:
    
    int _isolation;

    public:

    Pull();
    int getIsolationTermique();
};

#endif //PULL_H_