#include <iostream>
#include <stdlib.h>

using namespace std;

#define Swap(a, b) \
    {              \
        int c = b; \
        b = a;     \
        a = c;     \
    }

#define SwapUnify(a, b, t) \
    {                      \
        t temp = a;        \
        a = b;             \
        b = temp;          \
    }

#define Max 10
#define For_Each for (int i = 0; i < Max; i++)

int main()
{
    int x = 5, y = 10;
    float n = 5.5, m = 6.6;
    int a[Max];

    Swap(x, y);
    cout << "x=" << x << " y=" << y << endl;
    SwapUnify(n, m, float);
    cout << "n=" << n << " m=" << m << endl;

    For_Each
    {
        cout << i << " ";
    }
    cout << endl;

    int k[] = {1, 5, 3, 4, 6};

    for (int i = 0; i < sizeof(k) / sizeof(int); i++)
        printf("%d %d\n", i, k[i]);

#define for_each_member(T, k, i) for (int i = 0; i < sizeof(k) / sizeof(T); i++)

    for_each_member(int, k, j)
        printf("%d: %d\t", j, k[j]);

    return 0;
}
