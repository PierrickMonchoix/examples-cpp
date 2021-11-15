#include "Pull.h"


Pull::Pull() : _isolation(100)   { }   //definition des membres


int Pull::getIsolationTermique(){
    return _isolation;
}