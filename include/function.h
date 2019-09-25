#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <functional>
#include <algorithm>

template< typename Type > bool pred( Type const & pred ){ return true; }

template< typename T, typename predicate >
const T * findIf( const T * first, const T  * last , const predicate & target )
{

    const T * fast = first;

    while( fast != last )
    {
        if( ( *fast == target ) == pred( target ) )
        {
            return fast;
        }

        fast++;
    }

    std::cout << "O Alvo não está no vetor!\n";

    return last;
}


template< typename Type > bool cmp( const Type & a, const Type & b ){ return a < b; }

template< typename T >
const T * min( const T * first, const T * last )
{
    const T * min = first;

    while( first != last )
    {
        if( cmp( *first, *min ) )
        {
            min = first;
        }

        first++;
    }

    return min;
}





#endif

