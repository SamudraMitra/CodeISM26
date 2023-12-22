#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int f[10000];
int n;

int main()
{

    scanf("%d", &n);

    for (int i = 2; i <= n; ++i)
    {
        bool found = 0;
        for (int j = 2; j * j <= i; ++j)
            if (i % j == 0)
            {
                found = 1;
                break;
            }

        if (!found)
        {
            int x = i;
            while (x <= n)
            {
                f[x] = 1;
                x *= i;
            }
        }
    }

    int ans = 0;
    for (int i = 2; i <= n; ++i)
        ans += f[i];
    cout << ans << endl;
    for (int i = 2; i <= n; ++i)
        if (f[i])
            cout << i << " ";
    cout << endl;

    return 0;
}