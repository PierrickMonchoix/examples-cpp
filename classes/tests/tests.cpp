#include <iostream>
#include "Personnage.h"
#include "Tester.h"

using namespace std;







    /*
    Inserer ici les fonctions à tester
    */
void  initTest();

bool testBeAttackedOnGlobalObject();
bool testBeHealedOnGlobalObject();
bool testEqualObjectNOTDoneByReference();
bool testOperateurNewUsePointer();

void testAll()
{
    initTest();

    INITIALISE_TESTS

    ADD_TEST_FUNCTION(testBeAttackedOnGlobalObject)
    ADD_TEST_FUNCTION(testBeHealedOnGlobalObject)
    ADD_TEST_FUNCTION(testEqualObjectNOTDoneByReference)
    ADD_TEST_FUNCTION(testOperateurNewUsePointer)

    LAUNCH_TESTS
}


#define PV_MAX 100
#define DAMMAGE 24
#define HEAL 10

Personnage _jean;
Personnage _eren;

#define VALUE 42

/** un constructeur sans new se fait en décrivrant directement le nom de l'objet
 * 
 */
void initTest(){
    Personnage jean("Jean" , PV_MAX);
    _jean = jean;  
}

// TEST FUNCTIONS

/** Les méthodes sont bien fonctionnelles
 * 
 * 
*/
bool testBeAttackedOnGlobalObject(){
    _jean.beAttacked(DAMMAGE);
    ASSERT_EQUAL( _jean.getPv() , PV_MAX - DAMMAGE )
    return true;
}
bool testBeHealedOnGlobalObject(){
    _jean.beHealed(HEAL);
    ASSERT_EQUAL( _jean.getPv() , PV_MAX - DAMMAGE + HEAL)
    return true;
}

/*L'opérateur d'affection (=) copie les attributs de l'objet


*/
bool testEqualObjectNOTDoneByReference()
{
    const int dammage = 20;
    const int pvMaxJean = 100;
    const int pvMaxEren = 113;

    Personnage jean("Jean" , pvMaxJean);
    Personnage eren("Eren" , pvMaxEren);

    eren = jean;
    jean.beAttacked(dammage);
    
    ASSERT_EQUAL(jean.getPv() , pvMaxJean - dammage);
    ASSERT_EQUAL(eren.getPv() , pvMaxJean); // eren a bien les pv de jean AVANT qu'il ne se fasse attaquer
    return true;
}

/* L'opérateur new crée un ptr d'objet
C'est donc ce qui va se rapprocher du java car quand on va fait un "="
On va bien copier la & de l'objet
new est un malloc
*/
bool testOperateurNewUsePointer(){
    const int pvMaxThomas = 120;
    const int pvMaxArthur = 100;
    const int dammage = 20;

    Personnage *thomas, *arthur; // c'est pour ca que l'étoile est sur la variable!!!!! sinon ca considère arthur comme un perso
    thomas = new Personnage("Thomas" , pvMaxThomas);
    arthur = new Personnage("Arthur" , pvMaxArthur);
    arthur = thomas; // artur a mtnt l'& de thomas
    thomas->beAttacked(dammage);
    
    ASSERT_EQUAL(thomas->getPv() , pvMaxThomas - dammage);
    ASSERT_EQUAL(arthur->getPv() , thomas->getPv())
    return true;
}




