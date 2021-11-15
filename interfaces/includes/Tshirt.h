#ifndef TSHIRT_H_
#define TSHIRT_H_

#include "AVetement.h"

class Tshirt: public AVetement{

    private:

    int _isolation;

    public:

    Tshirt();

    int getIsolationTermique();
};

#endif //TSHIRT_H_