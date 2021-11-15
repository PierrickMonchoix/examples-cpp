#include "tests.h"
#include "Tester.h"
#include <iostream>

#include "AVetement.h"
#include "Pull.h"
#include "Tshirt.h"
#include "Porteur.h"

 
bool interfaceIsAbstactClass();

void testAll(){  
  INITIALISE_TESTS
  ADD_TEST_FUNCTION(interfaceIsAbstactClass)
  LAUNCH_TESTS
}


/**
 * AVetement dont have constructor
 * and have a pure virtual method
 * 
 * 
 * 
 */
bool interfaceIsAbstactClass(){ 
  AVetement *vetement; //contient une adresse sur le stack
  vetement = new Pull(); // contient une nouvelle adresse dans le tas 
  //le new donne une nouvelle adress, ce qui est logique d'une par et 
  //serait absurte d'autre part: le stack et le tas sont dans deux espaces totalement diffrent
  Porteur porteur(vetement);
  ASSERT_EQUAL(porteur.getIsolation(),100)
  return true;
}

 