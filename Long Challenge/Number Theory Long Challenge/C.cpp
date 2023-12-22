#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define fr(i, n) for (ll i = 0; i < n; i++)
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    fastio;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        if ((n % 2) == 0)
            cout << 1 + (k - 1) % n << "\n";
        else
        {
            ll ints = ((k - 1) / ((n - 1) / 2));
            cout << 1 + (k - 1 + ints) % n << "\n";
        }
    }
}