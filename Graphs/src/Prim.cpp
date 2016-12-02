#include <stdio.h>

struct link
{
    int destination, weight;
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
    link tree[vertices]; 
    // Initialize null values for algorithm
    for (int i = 0; i < vertices; i++)
        tree[i] = (struct link) { -1, MAX_VALUE };

    for (int i = 1, 
        next = 0, 
        mark[vertices] = {0}; i < vertices; i++)
    {
        mark[next] = 1;
        for (int j = 0; j < vertices; j++)
        {
            if (j != next)
            //salidzinam esosos attalumus ar jauniegutajiem
            {
                if (tree[j].weight > weights[next][j])
                {
                    tree[j].destination = next;
                    tree[j].weight = weights[next][j];
                }
            }
        }
        //atrod minimālo attālumu no neizīmētajām virsotnēm
        int minimum = MAX_VALUE;
        for (int j = 0; j < vertices; j++)
        {
            if (!mark[j])
            {
                if (tree[j].weight < minimum)
                {
                    minimum = tree[j].weight;
                    next = j;
                }
            }
        }
        // Sum of weights is the total
        totalWeight += tree[next].weight;
        //Ja kāda virsotne nav pievienota visam pārējam, tad rodas kļūda, par kuru vienkārši paziņo :
        if (minimum == MAX_VALUE)
            printf("Detached vertice...\n");
        
        // Un pēc tam atsāk ciklu no tās tādā veidā panākot, ka minimālie attālutree vienmēr būs pareizi.
    }
    printf("totalWeight: %d\n", totalWeight);
    for(int i = 1; i < vertices; i++)
        printf("%c <-> %c (%d)\n", i+'A', tree[i].destination+'A', tree[i].weight);

    return 0;
}
