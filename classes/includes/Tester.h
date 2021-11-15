#ifndef TESTER_H_
#define TESTER_H_
#include <string>

/**FRAMEWORK: Dans test.cpp:
 
#include "Tester.h"
 
bool <fonctionATester1>();
bool <fonctionATester2>();

void testAll(){  
  INITIALISE_TESTS
  ADD_TEST_FUNCTION(fonctionATester1)
  ADD_TEST_FUNCTION(fonctionATester2)
  LAUNCH_TESTS
}

bool <fonctionATester1>(){
    ...
}

bool <fonctionATester2>(){
    ...
}
 
*/


#define ASSERT_EQUAL(a,b) \
    if(a != b){  \
        cout << #a << " = " << a << endl  ;\
        cout << #b << " = " << b << endl ; \
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