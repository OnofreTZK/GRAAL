#include "../include/graal.h"

#include <iterator>

using namespace graal;
//====================== CLIENT functions =========================

bool cmp( const int & a, const int & b ) { return( a < b ); }

bool p( const int & pred )
{
    if( pred % 2 == 1 )
    {
        return true;
    }

    return false;
}

bool eq( const int & a, const int & b )
{
    return ( a == b ); 
}

bool p2( const int & pred )
{
    if( pred % 2 == 0 )
    {
        return true;
    }

    return false;
}
//=================================================================
//My tests.
//=================================================================
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

    std::cout<< "\nTEST minmax\n";

    std::cout << "\n>>>O valor minimo é " << A[0] << " e o maior é " << A[3] << "\n";

    //std::pair< int, int > Pairs = minmax( A, A+10, cmp );

    std::cout << ">>>O menor e o maior achados foram: "
              << *(minmax( A, A+10, cmp ).first) << ", "
              << *(minmax( A, A+10, cmp ).second) << "\n\n";



//===================== TEST Copy ==========================

    std::cout<< "\nTEST copy\n";

    int B[10];

    std::cout << ">>>Vetor B antes de copy:\n";
    std::cout << "\n[ ";
    for( const int & i: B )
    {
        std::cout << i << " ";
    }
    std::cout << "]\n\n";

    int * Blast = B + 10;

    Blast = copy( A, A+10, B );

    std::cout << ">>>Vetor B depois de copy:\n";
    std::cout << "\n[ ";
    for( const int & i: B )
    {
        std::cout << i << " ";
    }
    std::cout << "]\n\n";

    std::cout << ">>>O Blast deve imprimit um lixo de memória: " << *Blast << "\n"; 


//===================== TEST Reverse ==========================

    std::cout<< "\nTEST reverse\n";

    int C[10] = { 1, 2 ,3, 4, 5, 6, 7, 8, 9, 10 };
    int D[5] = { 1, 3, 5, 7, 9 };

    std::cout << ">>>Vetor C antes de reverse:\n";
    std::cout << "\n[ ";
    for( const int & i: C )
    {
        std::cout << i << " ";
    }
    std::cout << "]\n\n";

    std::cout << ">>>Vetor D antes de reverse:\n";
    std::cout << "\n[ ";
    for( const int & i: D )
    {
        std::cout << i << " ";
    }
    std::cout << "]\n\n";

    reverse( C, C + 10 );
    reverse( D, D + 5 );

    std::cout << ">>>Vetor C depois de reverse:\n";
    std::cout << "\n[ ";
    for( const int & i: C )
    {
        std::cout << i << " ";
    }
    std::cout << "]\n\n";

    std::cout << ">>>Vetor D depois de reverse:\n";
    std::cout << "\n[ ";
    for( const int & i: D )
    {
        std::cout << i << " ";
    }
    std::cout << "]\n\n";



//===================== TEST find_if ==========================

    std::cout<< "\nTEST find_if\n";

    std::cout << ">>>Vetor A:\n";
    std::cout << "\n[ ";
    for( const int & i: A )
    {
        std::cout << i << " ";
    }
    std::cout << "]\n\n";

    std::cout << ">>>Para teste o predicado unário busca pelo primeiro número impar no vetor\n";
    std::cout << ">>>O primeiro impar no vetor A é 1\n";
    std::cout << ">>>find_if achou: " << *find_if( A, A + 10, p ) << "\n";

    int E[9] = { 2, 4, 6, 8, 9, 7, 5, 3, 1 };

    std::cout << ">>>Vetor E:\n";
    std::cout << "\n[ ";
    for( const int & i: A )
    {
        std::cout << i << " ";
    }
    std::cout << "]\n\n";

    std::cout << ">>>O primeiro impar no vetor E é 9\n";
    std::cout << ">>>find_if achou: " << *find_if( E, E + 9, p ) << "\n";



//===================== TEST find ==========================

    std::cout<< "\nTEST find\n";

    std::cout << ">>>Vetor A:\n";
    std::cout << "\n[ ";
    for( const int & i: A )
    {
        std::cout << i << " ";
    }
    std::cout << "]\n\n";

    std::cout << ">>>O alvo passado é 8 e ele está na posição 5!\n";
    std::cout << ">>>find achou " << *find( A, A + 10, 8, eq )
                                  << " na posição "
                                  << std::distance( A, find( A, A + 10, 8, eq ) )
                                  << "\n";




//===================== TEST all_of, anyf_of, none_of ==========================


    std::cout<< "\nTEST all_of\n";

    int F[10] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
    std::cout << "\n\n>>>Para teste o predicado unário testa se o elemento é par\n";

    std::cout << ">>>Vetor F:\n";
    std::cout << "\n[ ";
    for( const int & i: F )
    {
        std::cout << i << " ";
    }
    std::cout << "]\n\n";

    if( all_of( F, F + 10, p2 ) )
    {
        std::cout << "\nRetornou \x1b[92mTRUE\x1b[0m!\n";
    }
    else
    {
        std::cout << "\nRetornou \x1b[91mFALSE\x1b[0m!\n";
    }

    int G[5] = { 1, 2, 4, 6, 8 };

    std::cout << ">>>Vetor G:\n";
    std::cout << "\n[ ";
    for( const int & i: G )
    {
        std::cout << i << " ";
    }
    std::cout << "]\n\n";

    if( all_of( G, G + 5, p2 ) )
    {
        std::cout << "\nRetornou \x1b[92mTRUE\x1b[0m!\n";
    }
    else
    {
        std::cout << "\nRetornou \x1b[91mFALSE\x1b[0m!\n";
    }


    // any_of
    std::cout<< "\nTEST any_of\n";

    if( any_of( G, G + 5, p2 ) )
    {
        std::cout << "\nRetornou \x1b[92mTRUE\x1b[0m!\n";
    }
    else
    {
        std::cout << "\nRetornou \x1b[91mFALSE\x1b[0m!\n";
    }


    // none_of
    std::cout<< "\nTEST none_of\n";

    int H[10] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };

    std::cout << ">>>Vetor H:\n";
    std::cout << "\n[ ";
    for( const int & i: H )
    {
        std::cout << i << " ";
    }
    std::cout << "]\n\n";

    if( none_of( H, H + 10, p2 ) )
    {
        std::cout << "\nRetornou \x1b[92mTRUE\x1b[0m!\n";
    }
    else
    {
        std::cout << "\nRetornou \x1b[91mFALSE\x1b[0m!\n";
    }

    if( none_of( G, G + 5, p2 ) )
    {
        std::cout << "\nRetornou \x1b[92mTRUE\x1b[0m!\n";
    }
    else
    {
        std::cout << "\nRetornou \x1b[91mFALSE\x1b[0m!\n";
    }

//===================== TEST equal overloaded ==========================

    std::cout<< "\nTEST overloaded equal\n";

    int I[5] = { 1, 2, 3, 4, 5 };
    int J[6] = { 6, 7, 8, 9, 10, 11 };
    int K[5] = { 1, 2, 3, 4, 5 };

    if( equal( I, I + 5, J, eq ) )
    {
        std::cout << "\nRetornou \x1b[92mTRUE\x1b[0m!\n";
    }
    else
    {
        std::cout << "\nRetornou \x1b[91mFALSE\x1b[0m!\n";
    }


    if( equal( I, I + 5, K, K + 5, eq ) )
    {
        std::cout << "\nRetornou \x1b[92mTRUE\x1b[0m!\n";
    }
    else
    {
        std::cout << "\nRetornou \x1b[91mFALSE\x1b[0m!\n";
    }


    if( equal( I, I + 5, G, G + 5, eq ) )
    {
        std::cout << "\nRetornou \x1b[92mTRUE\x1b[0m!\n";
    }
    else
    {
        std::cout << "\nRetornou \x1b[91mFALSE\x1b[0m!\n";
    }


//===================== TEST unique ====================================

    std::cout<< "\nTEST unique\n";

    int L[10] = { 1, 1, 2, 2, 3, 3, 4, 5, 6, 7 };

    std::cout << ">>>Vetor L:\n";
    std::cout << "\n[ ";
    for( const int & i: L )
    {
        std::cout << i << " ";
    }
    std::cout << "]\n\n";

    int * newLast = unique( L, L + 10, eq );
    std::cout << *( newLast - 1 ) << "\n";

    std::cout << ">>>Vetor L:\n";
    std::cout << "\n[ ";
    for( const int & i: L )
    {
        std::cout << i << " ";
    }
    std::cout << "]\n\n";

//===================== TEST partition ====================================

    std::cout<< "\nTEST partition\n";

    int M[10] = { 1, 1, 2, 2, 3, 3, 4, 5, 6, 7 };

    std::cout << ">>>Vetor M:\n";
    std::cout << "\n[ ";
    for( const int & i: M )
    {
        std::cout << i << " ";
    }
    std::cout << "]\n\n";

    int * newLast2 = partition( M, M + 10, p2 );
    std::cout << *( newLast2 ) << "\n";

    std::cout << ">>>Vetor M:\n";
    std::cout << "\n[ ";
    for( const int & i: M )
    {
        std::cout << i << " ";
    }
    std::cout << "]\n\n";

//===================== TEST sort ====================================

    std::cout<< "\nTEST sort\n";

    int N[10] = { 1, 4, 67, 90, 45, 8, 32, 65, 21, 58 };

    std::cout << ">>>Vetor N:\n";
    std::cout << "\n[ ";
    for( const int & i: N )
    {
        std::cout << i << " ";
    }
    std::cout << "]\n\n";

    int * newLast3 = sort( N, N + 10, cmp );
    std::cout << *( newLast3 - 1 ) << "\n";

    std::cout << ">>>Vetor N:\n";
    std::cout << "\n[ ";
    for( const int & i: N )
    {
        std::cout << i << " ";
    }
    std::cout << "]\n\n";

//===================== TEST rotate ====================================

    std::cout<< "\nTEST rotate\n";
    int O[7] = { 1, 2, 3, 4, 5, 6, 7 }; //{ 1, 2 ,3, 4, 5, 6, 7, 8, 9, 10 };

    std::cout << ">>>Vetor O:\n";
    std::cout << "\n[ ";
    for( const int & i: O )
    {
        std::cout << i << " ";
    }
    std::cout << "]\n\n";

    int * newLast4 = rotate( O, O + 4, O + 7);
    std::cout << *( newLast4 ) << "\n";

    std::cout << ">>>Vetor O:\n";
    std::cout << "\n[ ";
    for( const int & i: O )
    {
        std::cout << i << " ";
    }
    std::cout << "]\n\n";

    return 0;
}
