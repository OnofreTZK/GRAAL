#include "../include/function.h"

#include <iterator>

int main ( void )
{
    int A[10] = { 1, 4, 67, 90, 45, 8, 32, 65, 21, 58 };

    std::cout << "\n[ ";
    for( const int & i: A )
    {
        std::cout << i << " ";
    }
    std::cout << "]\n";

    //int target1{65};
    //int target2{22};

    return 0;
}
