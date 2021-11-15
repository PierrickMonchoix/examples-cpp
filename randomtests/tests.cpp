#include "Tester.h"
#include <iostream>

#include "tests.h"
 
bool fonctionATesterTrue();

void testAll(){  
  INITIALISE_TESTS
  ADD_TEST_FUNCTION(fonctionATesterTrue)
  LAUNCH_TESTS
}

extern int _c;

bool fonctionATesterTrue(){
    int a;
    
    a ++; //prouve que a a bien été créé
    g ++; //prouve que b a bien été créé
    _c++ ; //dont compile //prouve que c n' apas ete cree
    return true;
}



