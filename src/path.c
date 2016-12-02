#include <stdio.h>
#include <stdbool.h>
#define inf 0x7FFF
#define _ inf
#define min(A, B) ((A) < (B) ? (A) : (B))
#define Ms 6 // Only for initialization

int main(int argc, char **argv)
{
    int Matrix[Ms][Ms] = {
        0, 4, 2, _, _, _,
        4, 0, 1, 3, _, _,
        2, 1, 0, 8, 10, _,
        _, 3, 8, 0, 2, 6,
        _, _, 10, 2, 0, 3,
        _, _, _, 6, 3, 0};

    unsigned int Iter[Ms];
    
    bool constant[Ms] = { true };

    // initialize Iter
    Iter[0] = 0;
    for (int i = 1; i < Ms; i++)
        Iter[i] = inf;

    unsigned int ite = 0;
    while (1) // ite -> iterātors, cn -> izeja
    {
        for (int j = 0; j < Ms; j++)
        {
            //Jaunais = min esošais pret esošā ceļa attālumu + ceļa garums
            Iter[j] = min(Iter[j], Iter[ite] + Matrix[ite][j]);
            printf("MIN %d %d %d\n", ite, j + 1, Iter[j]);
        }
        //Atrast min nekonst
        int n = inf;
        for (int k = 1; k < Ms; k++)
        {
            // Ja nav konst
            if (!constant[k])
                if (n > Iter[k])
                {
                    n = Iter[k];
                    ite = k;
                    printf("NEK %d %d\n", ite, n);
                }
        }
        printf("MNK %d %d\n", ite, Iter[ite]);
        constant[ite] = true;
        if (n == inf)
            break;
    }

    for (int i = 0; i < Ms; i++)
    {
        if (Iter[i] == inf)
            printf("Unreachable\t");
        else
            printf("%d\t", Iter[i]);
    }
    printf("\n");
    
    int ind = Ms - 1;
    int Order[Ms];
    int of = 1;
    Order[0] = ind;
    int cn = 1;

    while (cn)
    {
        for (int g = 0; g < Ms; g++)
        {
            if (ind != g)
                if (Iter[ind] == (Matrix[ind][g] + Iter[g]))
                {
                    if (g != 0)
                        ind = g;
                    else
                        cn = 0;
                    Order[of++] = g;
                }
        }
    }

    int ror[of]; // Masivs ar jau atrasto isako celu.
    int of2 = 0; // Iterators šim masīvam.
    while (of)   // Datu ekstraktēšana un apgriešana otrādi.
        ror[of2++] = Order[--of];

    //Īsākā ceļa izvade
    printf("Order:");
    if (ror[of2] != 11) {
        printf("%d\n", of2);
        printf("Path doesn't exist \n");
    }
    else
        for (int d = 0; d < of2; d++)
            printf("%d ", ror[d]);

    return 0;
}
