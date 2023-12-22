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
        ll n, m;
        cin >> n >> m;
        vector<ll> a = {1};
        vector<ll> b;
        for (ll i = 1; i < n; i++)
        {
            ll x;
            cin >> x;
            a.push_back(x);
        }
        map<ll, ll> mb;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            b.push_back(x);
            mb[x]++;
        }
        sort(a.begin(), a.end());
        ll res = 0;
        for (ll i = 0; i < n; i++)
        {
            ll temp = a[i];
            auto z = mb.upper_bound(a[i]);
            if (z == mb.end())
            {
                res = n - i;
                // cout << "dsfd " << i << "\n";
                break;
            }
            else
            {
                mb[z->first]--;
                if (mb[z->first] == 0)
                {
                    mb.erase(z);
                }
            }
        }
        cout << res << "\n";
    }
}