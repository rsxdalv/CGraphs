#include <stdio.h>

struct link
{
    int from, weight;
};

#define MAX_VALUE 2048
#define _ MAX_VALUE
#define vertices 7

int main(int argc, char **argv)
{
    // example graph
    int weights[vertices][vertices] = {
        0,  6,  _,  11, 5,  _,  _,
        6,  0,  15, 18, 8,  _,  _,
        _,  15, 0,  8,  _,  _,  _,
        11, 18, 8,  0,  _,  10, 7,
        5,  8,  _,  _,  0,  15, 9,
        _,  _,  _,  10, 15, 0,  _,
        _,  _,  _,  7,  9,  _,  0};


    // result storage
    int totalWeight = 0;
    struct link tree[vertices]; 
    // Initialize null values for algorithm
    for (int i = 0; i < vertices; i++)
        tree[i] = (struct link) { -1, MAX_VALUE };

    for (int i = 1, 
        next = 0, 
        visited[vertices] = {1},
        minimum = MAX_VALUE; 
        i < vertices; 
        i++, 
        minimum = MAX_VALUE,
        visited[next] = 1) // Mark next as visited
    {
        //salidzinam esosos attalumus ar jauniegutajiem
        for (int j = 0; j < vertices; j++) {
            if (j != next && tree[j].weight > weights[next][j]) {
                tree[j] = (struct link) { .from = next, .weight = weights[next][j] };
            }
        }
        
        //atrod minimālo attālumu no neizīmētajām virsotnēm
        for (int j = 0; j < vertices; j++) {
            if (!visited[j] && tree[j].weight < minimum) {
                minimum = tree[j].weight;
                next = j;
            }
        }
        
        // Sum of weights is the total
        totalWeight += tree[next].weight;
        //Ja kāda virsotne nav pievienota visam pārējam, tad rodas kļūda, par kuru vienkārši paziņo :
        if (minimum == MAX_VALUE) printf("Error: detached vertice\n");
        // Un pēc tam atsāk ciklu no tās tādā veidā panākot, ka minimālie attālutree vienmēr būs pareizi.
    }
    
    // Print results
    printf("totalWeight: %d\n", totalWeight);
    for(int i = 1; i < vertices; i++)
        printf("%c <-> %c (%d)\n", i + 'A', tree[i].from + 'A', tree[i].weight);

    return 0;
}
