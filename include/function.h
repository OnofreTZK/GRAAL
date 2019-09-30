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
//Overloaded function equal.
//=========================================================================

template< typename Itr, typename Equal >

bool equal( const Itr first, const Itr last, const Itr first2, Equal eq )
{
    int range_size1 = std::distance( first, last );
    int range_size2 = std::distance( first2, first2 + range_size1 );
    if( eq( range_size1, range_size2) )
    {
        return true;
    }

    return false;
}

template< typename Itr, typename Equal >

bool equal( const Itr first, const Itr last, const Itr first2, const Itr last2, Equal eq )
{
    Itr fast = first;
    Itr fast2 = first2;

    while( ( fast != last ) and ( fast2 != last2 ) )
    {
        if( !eq( *fast, *fast2 ) )
        {
            return false;
        }
        fast++;
        fast2++;
    }
    return true;
}

//=========================================================================
// function unique
//=========================================================================
template< typename Itr, typename Equal >

Itr unique( Itr first, Itr last, Equal eq )
{
    Itr fast = first;
    Itr slow = first;

    int cnt = 0;

    while( fast != last )
    {
        slow = first;

        while( slow != last )
        {
            if( slow == fast )
            {
                slow++;
                continue;
            }
            else if( eq( *slow, *fast ) )
            {
                break;
            }
            slow++;
        }

        if( slow != last )
        {
            fast++;
            continue;
        }
        else if( slow == last )
        {
            cnt++;
            slow = fast;

            while( slow != first )
            {
                std::iter_swap( slow, slow - 1 );
                slow--;
            }
        }
        fast++;
    }

    //fast = first;

    Itr sortedLast = first + cnt;

    Itr minor{ first };

    while( first != sortedLast )
    {
        Itr selector{ first };
        //selection sort
        while( selector != sortedLast )
        {
            if( *selector < *minor )
            {
                minor = selector;
            }
            selector++;
        }
        std::iter_swap( first, minor );
        first++;
    }
    return last;
}

//===============================================================================
// function partition
//===============================================================================

template< typename Itr, typename Predicate >

Itr partition( Itr first, Itr last, Predicate p )
{
    Itr slow = first;
    Itr fast = first;

    while( fast != last )
    {
        if(  p( *fast  ) )
        {
            std::iter_swap( slow, fast );
            slow++;
        }

        fast++;
    }


    return slow;
}

//=============================================================================
// function to sort - i will use Insertion sort
//=============================================================================

template< typename Itr, typename Comparison >

Itr sort( Itr first, Itr last, Comparison comp )
{

    Itr fast = first;
    Itr slow = fast;

    while( fast != last - 1 )
    {

        if( comp( *(fast + 1 ), *fast ) )
        {
            std::iter_swap( fast, fast + 1 );
            slow = fast;
            fast++;

            while( slow != first )
            {
                if( comp( *slow, *(slow - 1) ) )
                {
                    std::iter_swap( slow, slow - 1 );
                    slow--;
                }
                else if( *slow == *(slow - 1) )
                {
                    slow--;
                }
                else if(  comp( *(slow - 1 ), *slow ) )
                {
                    break;
                }

            }

        }
        else if( comp( *fast, *(fast + 1) ) )
        {
            fast++;
        }
        else if( *fast == *(fast + 1) )
        {
            fast++;
        }

    }

    return fast;
}
//=============================================================================
// function to rotate - nfirst must be first and n nfirst - 1 must be last;
//=============================================================================

template< typename Itr >

Itr rotate( Itr first, Itr nfirst, Itr last )
{

    std::cout << "\nnfirst = " << *nfirst << "\n";

    Itr fast = nfirst;
    Itr fast2 = first;
 
    while(  fast2 != nfirst )
    {
        std::iter_swap( fast2++ , fast++ );
    }

    return first;
}
#endif

