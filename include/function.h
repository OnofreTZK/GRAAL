#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <functional>
#include <algorithm>
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
//function 

#endif

