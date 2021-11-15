#ifndef PERSONNAGE_H_
#define PERSONNAGE_H_

#include <string>


class Personnage{

    protected:

    std::string _name;
    int _pvMax;
    int _pv;
    


    public:

    Personnage(std::string name , int pvMax );
    Personnage();

    int getPv();
    std::string getName();

    void beAttacked(int dammage);
    void beHealed(int heal);

    virtual void beAttackedVirtual(int dammage);

};

#endif //PERSONNAGE_H_
