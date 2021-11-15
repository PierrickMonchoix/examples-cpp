#include "Tester.h"
#include <iostream>
#include "template.h"
 
bool templateSizeOf();

void testAll(){  
  INITIALISE_TESTS
  ADD_TEST_FUNCTION(templateSizeOf)
  LAUNCH_TESTS
}


/**noter que size est déclarré dans le header!!!
 * 
 */
bool templateSizeOf(){
    ASSERT_EQUAL(size<int>(),4) //4 octets
    return true;
}

