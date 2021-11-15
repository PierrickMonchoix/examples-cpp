#ifndef TEMPLATE_H_
#define TEMPLATE_H_

/**Les templates doient etres déclarés dans les .h et non les .cpp
 * Cela pose une étonnation:
 * MAIS LES .h NE SONT PAS COMPILES!!
 * 
 * Alors une theorie (de moi meme) dit que le code est ici recopié mot à mot

*/

template <typename T> //pouvait etre aussi:  class T
int size(){
    return (int)sizeof(T);
}

#endif //TEMPLATE_H_


