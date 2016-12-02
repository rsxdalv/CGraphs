#include <stdio.h>
#include <stdbool.h>
#define inf 0x7FFF
#define _ inf
#define min(A, B) ((A) < (B) ? (A) : (B))
#define SIZE 6 // Only for initialization

int main(int argc, char **argv)
{
    ////
    // Input data
    int Matrix[SIZE][SIZE] = {
        0, 4, 2, _, _, _,
        4, 0, 1, 3, _, _,
        2, 1, 0, 8, 10, _,
        _, 3, 8, 0, 2, 6,
        _, _, 10, 2, 0, 3,
        _, _, _, 6, 3, 0};

    ////
    // Initializators
    bool Found[SIZE] = { true };

    // initialize Distance
    unsigned int Distance[SIZE];
    Distance[0] = 0;
    for (int i = 1; i < SIZE; i++)
        Distance[i] = inf;

    ////
    // Get Distance from origin to all vertices
    for(unsigned int min_path_i = 0; true; ) {
        ////
        // Find new minimum values
        for (int i = 0; i < SIZE; i++)
            if(!Found[i]) {
                //Jaunais = min (esošais, esošā ceļa attālumu + ceļa garuSIZE)
                int path_to_i = Distance[min_path_i] + Matrix[min_path_i][i];
                Distance[i] = min(Distance[i], path_to_i);
                printf("Minumum %c %c (%d)\n", min_path_i + 'A', i + 'A', Distance[i]);
            }

        ////
        // Pick new non-constant minimum
        int min_dist = inf;
        for (int i = 1; i < SIZE; i++)
            if (!Found[i] && min_dist > Distance[i])
            {
                min_dist = Distance[i];
                min_path_i = i;
            }
        // No more paths left
        if (min_dist == inf)
            break;
        Found[min_path_i] = true;
        printf("Found vertice? %c (%d)\n", min_path_i + 'A', Distance[min_path_i]);

    }

    ////
    // Output all distances
    for (int i = 0; i < SIZE; i++)
        (Distance[i] == inf) ? printf("_\t") : printf("%d\t", Distance[i]);
    printf("\n");
    
    ////
    // Transform minimum path distances to a path
    int Path[SIZE];
    int offset = 1; // Path tracker
    int index = SIZE - 1;  // Reverse tracking index
    Path[0] = index; // Start from last

    while(offset != SIZE) // Run until all paths are found
        for (int i = 0; i < SIZE; i++)
            if (index != i && Distance[index] == (Matrix[index][i] + Distance[i]) )
                Path[offset++] = index = i; // Append variable

    int ReversePath[offset]; // Masivs ar jau atrasto isako celu.
    int rOffset = 0; // Distanceators šim masīvam.
    while (offset)   // Datu ekstraktēšana un apgriešana otrādi.
        ReversePath[rOffset++] = Path[--offset];

    //Īsākā ceļa izvade
    printf("Path: ");
    if (rOffset != 6) {
        printf("Path doesn't exist \n");
    }
    else
        for (int i = 0; i < rOffset; i++)
            printf("%c -> ", ReversePath[i] + 'A');

    return 0;
}
