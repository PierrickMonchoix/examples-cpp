#include <iostream>
#include "pointeurs.h"

using namespace std;

#define TEST_FUNCTION(f)   \
    cout << "> TESTING testExampleSucceed" << endl ;                                         \
    if (f())                                                         \
    {                                                                \
        cout << "< testExampleSucceed PASSED" << endl << endl;         \
    }                                                                  \
    else                                                               \
    {                                                                \
        cout << "< !!! testExampleSucceed NOT PASSED" << endl << endl; \
        allPassed = false;                                   \
    }

/*
functions a tester
*/
void  initTest();

bool testGetValue();
bool testGetAdressNotZero();

void testAll()
{
    initTest();
    cout << endl
         << endl
         << "########## TEST BEGIN ##########" << endl
         << endl;
    bool allPassed = true;

    /*
    functions a tester
    */
    TEST_FUNCTION(testGetValue)

    TEST_FUNCTION(testGetAdressNotZero)

    if (allPassed)
    {
        cout << endl
             << " >>> ALL TEST PASSED" << endl
             << endl;
    }
    else
    {
        cout << endl
             << " >>> FAIL TEST ALL" << endl
             << endl;
    }

    cout << endl
         << endl
         << "########## TEST END ##########" << endl
         << endl;
}


#define VALUE 42

void initTest(){
    initVariable(VALUE);
}

// TEST FUNCTIONS

bool testGetValue()
{ 
    int a = 0;
    a = getValue();
    std::cout << "Value is " << a <<std::endl;
    return a == VALUE;
}

bool testGetAdressNotZero()
{ 
    int* p = getAdress();
    long long pLong = 0;
    pLong = (long long) p;
    std::cout << "Adress is " << p << std::endl;
    return pLong != 0;
}

