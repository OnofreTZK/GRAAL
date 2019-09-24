#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <functional>


template < typename T, typename Predicate >

T const * findIf ( T const * first, T const * last , Predicate target )
{

    T const * fast = first;

    while( fast != last )
    {
        if( *fast == target )
        {
            std::cout << ">>> findIf procurou " << target
                      << ", achou " << *fast 
                      << " na posição "
                      << std::distance( first, fast ) << "\n";
            return fast;
        }

        fast++;
    }

    std::cout << "O Alvo não está no vetor!\n";

    return last;
}


#endif

