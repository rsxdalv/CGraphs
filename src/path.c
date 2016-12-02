#include <stdio.h>
#include <stdbool.h>
#define inf 0x7FFF
#define _ inf
#define min(A, B) ((A) < (B) ? (A) : (B))
#define Ms 6 // Only for initialization

int main(int argc, char **argv)
{
    ////
    // Input data
    int Matrix[Ms][Ms] = {
        0, 4, 2, _, _, _,
        4, 0, 1, 3, _, _,
        2, 1, 0, 8, 10, _,
        _, 3, 8, 0, 2, 6,
        _, _, 10, 2, 0, 3,
        _, _, _, 6, 3, 0};

    ////
    // Initializators
    bool Found[Ms] = { true };

    // initialize Distance
    unsigned int Distance[Ms];
    Distance[0] = 0;
    for (int i = 1; i < Ms; i++)
        Distance[i] = inf;

    ////
    // Get Distance from origin to all vertices
    for(unsigned int min_path_i = 0; true; ) // min_path_i -> Distanceātors
    {
        ////
        // Find new minimum values
        for (int i = 0; i < Ms; i++)
        {
            if(!Found[i]) {
                //Jaunais = min esošais pret esošā ceļa attālumu + ceļa garums
                int m = Distance[min_path_i] + Matrix[min_path_i][i];
                Distance[i] = min(Distance[i], m);
                printf("Minumum %c %c (%d)\n", min_path_i + 'A', i + 'A', Distance[i]);
            }
        }
        ////
        // Pick new non-constant minimum
        int n = inf;
        for (int i = 1; i < Ms; i++)
        {
            if (!Found[i] && n > Distance[i])
            {
                n = Distance[i];
                min_path_i = i;
            }
        }
        printf("Found vertice? %c (%d)\n", min_path_i + 'A', Distance[min_path_i]);
        Found[min_path_i] = true;
        if (n == inf)
            break;
    }

    ////
    // Output all distances
    for (int i = 0; i < Ms; i++)
        (Distance[i] == inf) ? printf("_\t") : printf("%d\t", Distance[i]);
    printf("\n");
    
    ////
    // Transform data to something
    int Order[Ms];
    int of = 1;
    int ind = Ms - 1;
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
