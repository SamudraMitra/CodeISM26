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
bool isprime(ll n)
{
    if (n == 1)
        return false;
    for (ll i = 2; i * i <= n; i++)
    {
        if ((n % i) == 0)
            return false;
    }
    return true;
}
int main()
{
    fastio;
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (isprime(n))
        {
            cout << "1\n"
                 << n << "\n";
        }
        else if (isprime(n - 2))
        {
            cout << 2 << "\n";
            cout << 2 << " " << n - 2 << "\n";
        }
        else
        {
            ll x = 0;
            for (ll i = n; i >= max(2ll, (n - 300)); i--)
            {
                if (isprime(i))
                {
                    x = i;
                    break;
                }
            }
            for (ll i = 1; i <= n - x; i++)
            {
                if (isprime(i) && isprime(n - x - i))
                {
                    cout << "3\n";
                    cout << i << " " << n - x - i << " " << x << "\n";
                    return 0;
                }
            }
        }
    }
}