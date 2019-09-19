#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A = 5, B = 8;

    int *p1 = &A;
    int *p2 = &B;

    intercambio(p1, p2);

    printf("A: %i", A);
    printf("B: %i", B);

    return 0;
}

void intercambio(int*A, int*B)
{
    int C = (*A);
    (*A) = (*B);
    (*B) = C;
}
