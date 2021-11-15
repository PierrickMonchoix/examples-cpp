#include <pthread.h>
#include "Tester.h"
#include <iostream>
#include <cstdlib>
#include <pthread.h>
 
bool fonctionATesterTrue();
bool fonctionATesterFalse();

void testAll(){ 
  INITIALISE_TESTS
  ADD_TEST_FUNCTION(fonctionATesterTrue)
  LAUNCH_TESTS
  /*ADD_TEST_FUNCTION(fonctionATesterFalse)
  LAUNCH_TESTS*/
}


int _a;
int *_ptrA = &_a;
int _addon;
int *_ptrAddon = &_addon;
    
pthread_t _thread;



void  *_incrementA(void *ptrAddon){
    int *intPtrAddon = (int *)ptrAddon;
    _a += *intPtrAddon;
    std::cout << "added !" << std::endl;
    pthread_exit(NULL);
}

bool fonctionATesterTrue(){
    *_ptrAddon = 4;
    *_ptrA = 10;
    
    pthread_create (&_thread, NULL, _incrementA, (void *) _ptrAddon);
    pthread_join(_thread, NULL);



    ASSERT_EQUAL(*_ptrA,14)
    return true;
}

bool fonctionATesterFalse(){
    ASSERT_EQUAL(1,0)
    return true;
}
