#ifndef TESTER_H_
#define TESTER_H_
#include <string>

/**FRAMEWORK: Dans test.cpp:
 
#include "Tester.h"
#include <iostream>
 
bool fonctionATesterTrue();
bool fonctionATesterFalse();

void testAll(){  
  INITIALISE_TESTS
  ADD_TEST_FUNCTION(fonctionATesterTrue)
  ADD_TEST_FUNCTION(fonctionATesterFalse)
  LAUNCH_TESTS
}

bool fonctionATesterTrue(){
    ASSERT_EQUAL(1,1)
    return true;
}

bool fonctionATesterFalse(){
    ASSERT_EQUAL(1,0)
    return true;
}
 
*/


#define ASSERT_EQUAL(a,b) \
    if(a != b){  \
        std::cout << #a << " = " << a << std::endl  ;\
        std::cout << #b << " = " << b << std::endl ; \
        return false;  \
    }  \

#define INITIALISE_TESTS \
    Tester::initialize();

#define ADD_TEST_FUNCTION(f) \
    Tester::pushFunction(f, #f);

#define LAUNCH_TESTS \
    Tester::testAll();


typedef struct s_functionStack
{
    bool (*function)();
    std::string functionName;

    struct s_functionStack *previous;
} * p_functionStack;

class Tester
{

private:
    static int _countFunctions;
    static p_functionStack _pFunctionStack;

    static s_functionStack popFunctionStack();

public:

    static void initialize();

    static void pushFunction(bool (*functionToTest)() , std::string functionName);
    static void testAll();
};

#endif //TESTER_H_