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
bool check(ll n, ll m, ll k, ll mid)
{
    ll res = 0;
    for (ll i = 1; i <= n; i++)
    {
        res += min((mid / i), m);
    }
    return (res >= (k));
}
int main()
{
    fastio;
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        ll lo = 1;
        ll hi = n * m;
        ll ans = hi;
        while (lo <= hi)
        {
            ll mid = lo + (hi - lo) / 2;
            if (check(n, m, k, mid))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}