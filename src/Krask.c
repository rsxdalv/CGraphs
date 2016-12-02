#include <stdio.h>

struct link
{
    int source, size;
};

#define inf 2048
#define _ inf
#define SIZED 7
#define MAYBE -1

int main()
{
    int Matrix[SIZED][SIZED] = {
        0, 6, _, 11, 5, _, _,
        6, 0, 15, 18, 8, _, _,
        _, 15, 0, 8, _, _, _,
        11, 18, 8, 0, _, 10, 7,
        5, 8, _, _, 0, 15, 9,
        _, _, _, 10, 15, 0, _,
        _, _, _, 7, 9, _, 0};

    int visited[SIZED] = {0};
    struct link Mi[SIZED];
    for (int a = 0; a < SIZED; a++)
        Mi[a] = (struct link){.source = -1, .size = inf};

    int length = 0;

    int groupn = 0; // Some sort of id counter

    for (int count = 1, minimum = inf, alpha = MAYBE, beta = MAYBE;
         count < SIZED;
         count++, alpha = MAYBE, beta = MAYBE, minimum = inf)
    {
        for (int i = 0; i < SIZED; i++)
        { // Pret katru virsotni
            for (int k = i + 1; k < SIZED; k++)
            {
                if (!visited[k] || visited[i] != visited[k])
                    //Ja viena no virstonem ir neiezimeta
                    //atskirigas grupas virsotnes
                    if (Matrix[i][k] < minimum)
                    {
                        //ir loks mazaks par min
                        alpha = i;
                        beta = k;
                        minimum = Matrix[i][k];
                    }
            }
        }
        if (alpha == MAYBE || beta == MAYBE)
            printf("Unreachable vertice!\n");
        if (minimum == inf)
            printf("Error, minimum == inf\n");
        else
            length += Matrix[alpha][beta];
        if (!visited[alpha])
        {
            if (!visited[beta])
                visited[alpha] = visited[beta] = ++groupn;
            else
                visited[alpha] = visited[beta];
        }
        else if (!visited[beta])
            visited[beta] = visited[alpha];
        else
        {
            int repl = visited[beta];
            int rep = visited[alpha];
            for (int x = 0; x < SIZED; x++)
                if (visited[x] == repl)
                    visited[x] = rep;
        }
        printf("Link %c <-> %c\n", alpha + 'A', beta + 'A');
    }

    printf("Length: %d\n", length);
    return 0;
}
