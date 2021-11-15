#include "Tester.h"
#include <iostream>

//https://www.codingame.com/work/fr/question-entretien-c-plus-plus/
 
bool plusPlusOperatorDontReturnValue();
bool classesAreJustStructsWithPrivateNotion();
bool beforeStructSyntax();

void testAll(){  
  INITIALISE_TESTS
  ADD_TEST_FUNCTION(plusPlusOperatorDontReturnValue)
  ADD_TEST_FUNCTION(classesAreJustStructsWithPrivateNotion)
  ADD_TEST_FUNCTION(beforeStructSyntax)
  LAUNCH_TESTS
}

bool plusPlusOperatorDontReturnValue(){
    #define INIT_A 5
    #define INIT_B 10

    int a, b;
    a = INIT_A;
    b = INIT_B;
    
    b = a++; //on commence par faire b = a puis a ++

    ASSERT_EQUAL(b,INIT_A)
    ASSERT_EQUAL(a,INIT_A + 1)


    a = INIT_A;
    b = INIT_B;

    b = a = a + 1; //on commence par faire a = a + 1 puis b = a

    ASSERT_EQUAL(b,INIT_A + 1)
    ASSERT_EQUAL(a,INIT_A + 1)

    return true;
}

#define INIT_VALUE 10

struct my_struct{
    int a = INIT_VALUE;
    int getValue() {return a; } // pas besoin de ; a la fin
    void setValue(int val) {a = val; }
    int thisGetValue() {return this->a;} // this existe aussi pour les stuctures !!!
};

struct my_baby_struct : my_struct {

};

class My_class{
    //attributs et membres privés par défaut
    int a = INIT_VALUE; 
    public: 
    int getValue() {return a; }
    void setValue(int val) {a = val; }
    int thisGetValue() {return this->a;}
};

struct My_baby_class : public My_class {

};

/** Les classes et les sctucts cest quasi la meme chose en C++
 * Ya meme l'heritage pour les sctruct!
 * Ya juste pas de private
 * 
 * Attention l'heritage pr les structs existe en c++ mais pas en c
 * 
 */
bool classesAreJustStructsWithPrivateNotion(){
    #define SET_VALUE 15

    my_struct str; // rq: pas besoin de typedef en c++ mais on peut avoir des erreurs avec les namespaces
    ASSERT_EQUAL(str.getValue(),INIT_VALUE)
    str.setValue(SET_VALUE);
    ASSERT_EQUAL(str.getValue(),SET_VALUE)
    ASSERT_EQUAL(str.a , SET_VALUE)

    My_class cla; // appel du constructeur par defaut sans ()
    ASSERT_EQUAL(cla.getValue(),INIT_VALUE)
    cla.setValue(SET_VALUE);
    ASSERT_EQUAL(cla.getValue(),SET_VALUE)
    //ASSERT_EQUAL(cla.a , SET_VALUE) // impossible car privé

    my_struct str2; //utilisation de this
    ASSERT_EQUAL(str2.thisGetValue(),INIT_VALUE)
    str2.setValue(SET_VALUE);
    ASSERT_EQUAL(str2.thisGetValue(),SET_VALUE)
    ASSERT_EQUAL(str2.a , SET_VALUE)

    My_class cla2; //utilisation de this
    ASSERT_EQUAL(cla2.thisGetValue(),INIT_VALUE)
    cla2.setValue(SET_VALUE);
    ASSERT_EQUAL(cla2.thisGetValue(),SET_VALUE)
    //ASSERT_EQUAL(cla.a , SET_VALUE) // impossible car privé

    //inheritance:
    My_class baby_cla; // appel du constructeur par defaut sans ()
    ASSERT_EQUAL(baby_cla.getValue(),INIT_VALUE)
    baby_cla.setValue(SET_VALUE);
    ASSERT_EQUAL(baby_cla.getValue(),SET_VALUE)

    //struct inheritance
    my_struct baby_str; // rq: pas besoin de typedef en c++ mais on peut avoir des erreurs avec les namespaces
    ASSERT_EQUAL(baby_str.getValue(),INIT_VALUE)
    baby_str.setValue(SET_VALUE);
    ASSERT_EQUAL(baby_str.getValue(),SET_VALUE)
    ASSERT_EQUAL(baby_str.a , SET_VALUE)


    return true;
}


struct DefineStruct {
    int a;
    int b;
};

struct {
    int a;
    int b;
} _defineOneElement;

bool beforeStructSyntax(){ 
    _defineOneElement.a = 2; //one element of "no type"
   // _defineOneElement a; //npn sense

   //DefineStruct.a = 2; // non sense
    DefineStruct a;

    //on peut cummulter les duex biensur
    return true;
}

/**C'est ambigu car 
 * 
 */
class ClassWithIdenticalFuncsWithoutDiamond{
    public:
    int foo(){return 12; }
    //bool foo(){ return true; }  //cannot overload functions distinguished by return type alone
    int foo(int a){return 13;}
};

class ClassA1{
    public:
    int toto = 1;
    int foo(){
        return 1;
    }
};

class ClassA2{
    public:
    int toto = 1;

    int foo(){
        return 2;
    }
};

class ClassB : public ClassA1 , public ClassA2 {

};


// Ca compile pas car c'est innatendu que les classes parentes ai une foncton de meme nom
bool whatFieldOfMotherClassIsUsedWithoutDiamond(){
    ClassB classB;
    //ASSERT_EQUAL(classB.toto , 1) //dont compile, toto is ambiguous
    //ASSERT_EQUAL(classB.foo() , 1) //dont compile, foo is ambiguous
    return true;
}



class MotherDiamond{
    public:
   /* int foo(){
        return 0;
    }*/
};

class Fils : public MotherDiamond {
    /*int foo(){
        return 1;
    }*/
};
class Fille : public MotherDiamond {
        /*int foo(){
        return 2;
    }*/
};

class Toto{

};
class Titi : public Toto{

};
class Tata :  public Toto{

};
class Tita : public Tata {

};

class Consanguin : public Fils , Fille {};


// Ca compile  car c'est attendu que les classes parentes ai une foncton de meme nom
bool whatFieldOfMotherClassIsUsedWithDiamond(){
    Consanguin c;
    //c->foo();

    MotherDiamond m;
    //m = c; //ne compile pas pcq ca fait un diamand

    Toto toto;
    Titi titi;
    toto = titi;
    Tita tita;
    toto = tita;

}

bool uniquePtr(){
    unique_ptr<int> intptr

}






