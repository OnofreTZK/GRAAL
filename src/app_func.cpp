#include "../include/function.h"

#include <iterator>


bool cmp( const int & a, const int & b ) { return( a < b ); }

int main ( void )
{
    int A[10] = { 1, 4, 67, 90, 45, 8, 32, 65, 21, 58 };

    std::cout << "\n[ ";
    for( const int & i: A )
    {
        std::cout << i << " ";
    }
    std::cout << "]\n";

//===================== TEST MinMax =========================

    std::cout << "\n>>>O valor minimo é " << A[0] << " e o maior é " << A[3] << "\n";

    //std::pair< int, int > Pairs = minmax( A, A+10, cmp );

    std::cout << ">>>O menor e o maior achados foram: "
              << *(minmax( A, A+10, cmp ).first) << ", "
              << *(minmax( A, A+10, cmp ).second) << "\n\n";



//===================== TEST Reverse =========================


    return 0;
}
