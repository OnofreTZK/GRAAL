#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>
#include <utility>

/*
//==============================================================================
// function findIf -- search for target in range
//===============================================================================
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
//===================================================================================
*/

//===================================================================================
//function minmax - return a pair< minor, major >
//=================================================================================== 

template< typename Itr, typename Compare >

std::pair< Itr, Itr > minmax( const Itr first, const Itr last, Compare cmp )
{
    Itr min = first;

    Itr max = first;

    Itr fast = first;

    while( fast != last )
    {
        if( cmp( *fast, *min ) )
        {
            min = fast;
        }

        if( cmp( *max, *fast ) )
        {
            max = fast;
        }

        fast++;
    }

    return std::make_pair( min, max);
}
//==================================================================================


//==================================================================================
//function copy - return last iterator of the new range
//==================================================================================

template< typename Itr >

Itr copy( const Itr first, const Itr last, Itr dfirst )
{
    Itr fast = first;

    while( fast != last )
    {
        *dfirst++ = *fast++;
    }

    return dfirst;
}
//=================================================================================



//=================================================================================
//function reverse - invert elements in range
//=================================================================================

template< typename Itr >

void reverse( Itr first, Itr last )
{
    Itr middle = first + std::distance( first, last)/2 - 1;

    last--;

    while(  first <= middle  )
    {
        std::iter_swap( first++, last-- );
    }
}
//=================================================================================
#endif

