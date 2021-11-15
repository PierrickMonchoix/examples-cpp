//    Tester();

//   void addFunction(bool (*functionToTest)());

#include "Tester.h"
#include <iostream>

using namespace std;

//En c, les membres statics doivent êtres déclarés dans le .h puis être définit dans le .cpp
//en effet, un membre non-static est au définit dans le constructeur (zero de base)
int Tester::_countFunctions;
p_functionStack Tester::_pFunctionStack;

void Tester::initialize()
{
    _countFunctions = 0;
    _pFunctionStack = new s_functionStack;
}

void Tester::pushFunction(bool (*functionToTest)() , std::string functionName)
{
    if (_countFunctions == 0)
    {
        _pFunctionStack->function = functionToTest;
        _pFunctionStack->functionName = functionName;
    }
    else
    {
        p_functionStack pNewElementOfStack = new s_functionStack;
        pNewElementOfStack->function = functionToTest;
        pNewElementOfStack->functionName = functionName;
        pNewElementOfStack->previous = _pFunctionStack; //le nouveau stack devient l'ancien stack
        _pFunctionStack = pNewElementOfStack;
    }
    _countFunctions++;
}

s_functionStack Tester::popFunctionStack()
{
    p_functionStack pIEmeStackFunction = _pFunctionStack;
    for (int i = 0; i < _countFunctions - 1; i++)
    {
        pIEmeStackFunction = pIEmeStackFunction->previous;
    }

    p_functionStack pStackFunctionToPop = pIEmeStackFunction;
    s_functionStack stackFunctionToPop = *pStackFunctionToPop;
    delete pStackFunctionToPop;
    _countFunctions--;
    return stackFunctionToPop;
}

void Tester::testAll()
{
    cout << endl
         << endl
         << "########## TEST BEGIN ##########" << endl
         << endl;
    bool allPassed = true;
    while (_countFunctions > 0)
    {
        s_functionStack functionStackToTest = popFunctionStack();

        cout << "> TESTING " << functionStackToTest.functionName << endl;
        if (functionStackToTest.function())
        {
            cout << "< " << functionStackToTest.functionName << " PASSED" << endl
                 << endl;
        }
        else
        {
            cout << "< !!! " << functionStackToTest.functionName << " NOT PASSED" << endl
                 << endl;
            allPassed = false;
        }
    }
    if (allPassed)
    {
        cout << endl
             << " >>> ALL TEST PASSED !" << endl
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