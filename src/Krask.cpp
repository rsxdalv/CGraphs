#include <iostream>

// Pieliku komentārus lai kļūtu nedaudz skaidrāka darbība
using namespace std;

struct link
{
    int source, size;
};

#define MAX_VALUE 2048
#define _ MAX_VALUE
#define SIZED 7

int main()
{
    int Matrix[SIZED][SIZED]={
        0,	6,	_,	11,	5,	_,	_,
        6,	0,	15,	18,	8,	_,	_,
        _,	15,	0,	8,	_,	_,	_,
        11,	18,	8,	0,	_,	10,	7,
        5,	8,	_,	_,	0,	15,	9,
        _,	_,	_,	10,	15,	0,	_,
        _,	_,	_,	7,	9,	_,	0};

    int mark[SIZED] = {0};
    link Mi[SIZED] = {MAX_VALUE};
    for (int a = 0; a < SIZED; a++)
        Mi[a] = (struct link){.source = -1, .size = MAX_VALUE};

    int next = 0;
    int length = 0;

    int maing[SIZED] = {0};
    int groupn = 0;

    for (int count = 1; count < SIZED; count++)
    {

        int minn = _;
        int alpha = -1, beta = -1;
        for (int i = 0; i < SIZED; i++)
        { // Pret katru virsotni
            for (int k = i + 1; k < SIZED; k++)
            {
                if (!mark[k] || mark[i] != mark[k])
                    //Ja viena no virstonem ir neiezimeta
                    //atskirigas grupas virsotnes
                    if (Matrix[i][k] < minn)
                    {
                        //ir loks mazaks par min
                        alpha = i;
                        beta = k;
                        minn = Matrix[i][k];
                    }
            }
        }
        if (alpha == -1 || beta == -1)
            cout << "Nesasniedzama virsotne!" << endl;
        if (minn == _)
            cout << "kluuda!" << endl;
        else
            length += Matrix[alpha][beta];
        if (mark[alpha] == 0)
        {
            if (mark[beta] == 0)
            {
                mark[alpha] = mark[beta] = ++groupn;
            }
            else
                mark[alpha] = mark[beta];
        }
        else if (mark[beta] == 0)
            mark[beta] = mark[alpha];
        else
        {
            int repl = mark[beta];
            int rep = mark[alpha];
            for (int x = 0; x < SIZED; x++)
                if (mark[x] == repl)
                    mark[x] = rep;
        }
        printf("Link %c <-> %c\n", alpha + 'A', beta + 'A');
    }

    cout << "Length : " << length << endl;

    return 0;
}
