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

    
    bool constant[Ms] = { true };

    // initialize Distance
    unsigned int Distance[Ms];
    Distance[0] = 0;
    for (int i = 1; i < Ms; i++)
        Distance[i] = inf;

    for(unsigned int distance_iter = 0; true; ) // distance_iter -> Distanceātors
    {
        for (int i = 0; i < Ms; i++)
        {
            //Jaunais = min esošais pret esošā ceļa attālumu + ceļa garums
            Distance[i] = min(Distance[i], Distance[distance_iter] + Matrix[distance_iter][i]);
            printf("MIN %d %d %d\n", distance_iter, i + 1, Distance[i]);
        }
        //Atrast min nekonst
        int n = inf;
        for (int i = 1; i < Ms; i++)
        {
            if (!constant[i] && n > Distance[i])
            {
                n = Distance[i];
                distance_iter = i;
                printf("NEK %d %d\n", distance_iter, n);
            }
        }
        printf("MNK %d %d\n", distance_iter, Distance[distance_iter]);
        constant[distance_iter] = true;
        if (n == inf)
            break;
    }

    for (int i = 0; i < Ms; i++)
        (Distance[i] == inf) ? printf("_\t") : printf("%d\t", Distance[i]);
    
    printf("\n");
    
    int ind = Ms - 1;
    int Order[Ms];
    int of = 1;
    Order[0] = ind;

    for (int g = 0; g < Ms; g++)
    {
        if (ind != g && Distance[ind] == (Matrix[ind][g] + Distance[g]) )
        {
            if (g != 0)
                ind = g;
            else
                break;
            Order[of++] = g;
        }
    }


    int ror[of]; // Masivs ar jau atrasto isako celu.
    int of2 = 0; // Distanceators šim masīvam.
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
