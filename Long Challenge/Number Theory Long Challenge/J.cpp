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
    // cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> v(n);
        for (auto &i : v)
            cin >> i;
        if (n * n <= (1e6 + 5))
        {
            ll res = 1;
            for (ll i = 0; i < n; i++)
            {
                for (ll j = i + 1; j < n; j++)
                {
                    res *= abs(v[i] - v[j]);
                    res %= m;
                }
            }
            cout << res << "\n";
        }
        else
        {
            cout << "0\n";
        }
    }
}