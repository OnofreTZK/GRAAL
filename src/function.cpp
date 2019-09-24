#include "../include/function.h"

T const * findIf ( T const * first, T const * last, Predicate target )
{
    while( first != last )
    {
        if( *first = target )
        {
            return first;
        }

        first++;
    }

    std::cout << "O Alvo não está no vetor!\n";
}
