#include "../include/function.h"

#include <iterator>

int main ( void )
{
    int A[10] = { 1, 4, 67, 90, 45, 8, 32, 65, 21, 58 };

    int target1{65};
    int target2{22};

    int test;

    std::cout << ">>> O alvo é " << target1 << " e está na posição 7\n";
    test = *findIf( A , A + 10, target1);
    std::cout << ">>> O alvo é " << target2 << " e ele não está na função!\n";
    std::cout << ">>> findIf retornou: \n";

    if( findIf( A, A + 10, target2 ) == A + 10 )
    {
        std::cout << "Last!\n";
    }
    else
    {
        std::cout << "Outro iterador! Corrija!\n";
    }

    return 0;
}
