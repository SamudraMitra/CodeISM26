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
        ll n, x;
        cin >> n >> x;
        vector<ll> v(n);
        for (auto &i : v)
            cin >> i;
        ll lo = 1;
        ll hi = 1e10;
        ll ans = lo;
        while (lo <= hi)
        {
            ll mid = lo + (hi - lo) / 2;
            ll res = 0;
            for (ll i = 0; i < n; i++)
            {
                res += max(0ll, mid - v[i]);
            }
            if (res <= x)
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        cout << ans << "\n";
    }
}