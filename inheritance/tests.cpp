#include "tests.h"
#include "Tester.h"
#include <iostream>
#include "Personnage.h"
#include "Sensible.h"

 
bool persoBeAttaked();
bool sensibleBeAttaked();
bool earlyBinding();
bool lateBinding();
bool lateBindingDontWorkWithoutPointer();

void testAll(){  
  INITIALISE_TESTS
  ADD_TEST_FUNCTION(persoBeAttaked)
  ADD_TEST_FUNCTION(sensibleBeAttaked)
  ADD_TEST_FUNCTION(earlyBinding)
  ADD_TEST_FUNCTION(lateBinding)
  ADD_TEST_FUNCTION(lateBindingDontWorkWithoutPointer)
  LAUNCH_TESTS
}

bool persoBeAttaked(){

    Personnage jean("Jean" , 100);
    jean.beAttacked(20);
    ASSERT_EQUAL(jean.getPv() , 100 - 20)
    return true;
}

bool sensibleBeAttaked(){
   Sensible robin("Robin" , 100);
   robin.beAttacked(20);
   ASSERT_EQUAL(robin.getPv(), 100 - 20 - 1);
   return true;
}

/*
early binding polymorphism

*/
bool earlyBinding(){
  Personnage *perso; //le compilateur va garder en tete que ce ptr est un ptr de perso
  Sensible *sensible = new Sensible("Sensible" , 100);
  perso = sensible;
  perso->beAttacked(20); // NON virt fun => c'est ce qu'il y a a priori ds le prt qui compte
  ASSERT_EQUAL(perso->getPv() , 80);
  return true;
}


/*
late binding polymorphism

*/
bool lateBinding(){
  Personnage *perso; //le compilateur va garder en tete que ce ptr est un ptr de perso
  Sensible *sensible = new Sensible("Sensible" , 100);
  perso = sensible;
  perso->beAttackedVirtual(20); // virt fun => c'est ce qu'il y a a posteriori ds le prt qui compte
  ASSERT_EQUAL(perso->getPv() , 79);
  return true;
}

/*
polymorphism make sens with ptr only

*/
bool lateBindingDontWorkWithoutPointer(){
  Personnage perso;
  Sensible sensible("Sensible" , 100);
  perso = sensible;
  perso.beAttackedVirtual(20);
  ASSERT_EQUAL(perso.getPv() , 80);
  return true;
}