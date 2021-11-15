#include "Tester.h"
#include <iostream>
 
bool setAndGetPtrFunc();

void testAll(){  
  INITIALISE_TESTS
  ADD_TEST_FUNCTION(setAndGetPtrFunc)
  LAUNCH_TESTS
}

int _foo(char var){
    char c = var+1;
    return (int)c;
}

/**Declaration d'un ptr de fonction _ptrFunc
 * preant en arg un char et renvoyant un int
 * 
 * On peut comprendre (mnémotecnique)
 *    *_ptrFunc  comme: "_ptrFunc est un ptr"
 *    et le reste decrit une fonction de quoi avec qiuoi comme arg
 *    
 */
int (*_ptrFunc)(char);

/** setPtrFunc EST une fonction qui prend 1 arg: 
 *  ptrFunc qui est un pt de func 
 *  et setPtrFunc(...) EST un void. On a bien ecrit:
 *  void setPtrFunc(...) qui est la meme facon de declarer un void "a": 
 *  void a
 * 
 * 
 */
void setPtrFunc( int (*ptrFunc)(char) ){
    _ptrFunc = ptrFunc;
}

/**getPtrFunc est une fonction qui prend en arg rien du tout
 * et getPtrFunc(...) EST un ptr de func. On a bien ecrit:
 * int (*getPtrFunc(...)) (char c) qui est la meme faonco de declarer un ptr de func "a":
 * int (*a)(char);
 * 
 * 
 * 
 * 
 */
int (*getPtrFunc()) (char c)
{
   return _ptrFunc;
}





bool setAndGetPtrFunc(){
    setPtrFunc(_foo);
    int a = getPtrFunc()(8);
    std::cout << "size ptrfun " << sizeof(_ptrFunc) << std::endl;
    std::cout << "size int " << sizeof(int) << std::endl;
    ASSERT_EQUAL(a,9)
    return true;
}


