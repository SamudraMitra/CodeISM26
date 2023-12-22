#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    if (n <= 2)
    {
        printf("-1\n");
        return 0;
    }
    if (n == 3)
    {
        printf("210\n");
        return 0;
    }
    int mod = 1;
    printf("1");
    for (int i = 0; i < n - 1; i++)
    {
        mod *= 10;
        mod %= 210;
        if (i < n - 4)
            printf("0");
    }
    for (int i = 0; i < 1000; i++)
        if ((i + mod) % 210 == 0)
        {
            printf("%.3d\n", i);
            return 0;
        }
    return 0;
}