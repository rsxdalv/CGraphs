#include <iostream>
#include <fstream>
#include <stdio.h>
#define inf 0x7FFF
#define _ inf
#define min(A, B) ((A) < (B) ? (A) : (B))
using namespace std;

int main(int argc, char **argv)
{
    //ifstream("test1.dat");
    //FILE * matr;
    //fopen("","w+");
    const int Ms = 6;

    int Matrix[Ms][Ms] = {
        0, 4, 2, _, _, _,
        4, 0, 1, 3, _, _,
        2, 1, 0, 8, 10, _,
        _, 3, 8, 0, 2, _,
        _, _, 10, 2, 0, _,
        _, _, _, _, _, 0
    };
    unsigned int Iter[Ms];
    bool cst[Ms];
    cst[0] = true;
    Iter[0] = 0;
    for (int i = 1; i < Ms; i++)
        Iter[i] = inf;

    unsigned int ite = 0, cn = 1;
    while (cn) // ite -> iterātors, cn -> izeja
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
            if (!cst[k])
                if (n > Iter[k])
                {
                    n = Iter[k];
                    ite = k;
                    printf("NEK %d %d\n", ite, n);
                }
        }
        printf("MNK %d %d\n", ite, Iter[ite]);
        if (n == inf)
            cn = false;

        cst[ite] = true;
        //ite=n;
    }
    cout << endl;
    /*for(int i=0;i<Ms;i++)
    {
        for(int j=i+1;j<Ms;j++)
        {
            Iter[j]=min(Iter[j],Iter[i]+Matrix[i][j]);
            cout<<endl<<j<<" "<<Iter[j]<<endl;
        }
    }*/
    for (int i = 0; i < Ms; i++)
    {
        for (int k = 0; k < Ms; k++)
        {
            if (Matrix[i][k] == inf)
                cout << "#  ";
            else
                printf("%d  ", Matrix[i][k]);
        }
        printf("\n");
    }
    cout << endl;

    for (int i = 0; i < Ms; i++)
    {
        if (Iter[i] == inf)
            cout << "Unreachable ";
        else
            printf("%d ", Iter[i]);
    }
    cout << endl;
    int ind = Ms - 1;
    int Order[Ms];
    int of = 1;
    //Order[of--]=ind;
    Order[0] = ind;
    //ind=2;
    cn = 1;
    while (0)
    {
        for (int g = 0; g < Ms; g++)
        {
            if (ind != g)
                if (Iter[ind] == (Matrix[ind][g] + Iter[g]))
                {
                    if (Iter[ind] == inf)
                        cn = 0;
                    //printf("Match %d %d\n",ind,g);
                    if (g != 0)
                        ind = g;
                    else
                        cn = 0;
                    Order[of--] = g;
                }
        }
    }
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
    cout << "Order : \n";
    if (ror[of2] != 5)
    {
        cout << of2;
        cout << "Path doesn't exist \n";
        return 0;
    }
    for (int d = 0; d < of2; d++)
        printf("%d ", ror[d]);
    return 0;
}
