#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>
#include <utility>


//===============================================================================
// function findIf -- search for target( client choose condition )
//===============================================================================

template< typename Itr, typename Predicate >

const Itr find_if( const Itr first, const Itr last , const Predicate p )
{
    Itr fast = first;

    while( fast != last )
    {
        if( p(*fast) )
        {
            return fast;
        }

        fast++;
    }

    std::cout << "O Alvo não está no vetor!\n";

    return last;
}
//===================================================================================


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



//=================================================================================
//function find with target
//=================================================================================

template< typename Itr, typename T, typename Equal >

Itr find( const Itr first, const Itr last, const T target, Equal eq )
{
    Itr fast = first;

    while( fast != last )
    {
        if( eq( *fast, target ) )
        {
            return fast;
        }
        fast++;
    }

    return last;
}



//=================================================================================
//all_of, any_of, none_of
//=================================================================================


template< typename Itr, typename Predicate >

bool all_of( const Itr first, const Itr last, Predicate p )
{
    Itr fast = first;

    while( fast != last )
    {
        if( !p(*fast) )
        {
            return false;
        }
        fast++;
    }

    return true;
}


template< typename Itr, typename Predicate >

bool any_of( const Itr first, const Itr last, Predicate p )
{
    Itr fast = first;

    while( fast != last )
    {
        if( p(*fast) )
        {
            return true;
        }
        fast++;
    }

    return false;
}


template< typename Itr, typename Predicate >

bool none_of( const Itr first, const Itr last, Predicate p )
{
    Itr fast = first;

    while( fast != last )
    {
        if( p(*fast) )
        {
            return false;
        }
        fast++;
    }

    return true;
}

//=========================================================================
#endif

