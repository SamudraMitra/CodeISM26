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
        ll n;
        cin >> n;
        ll lo = 0;
        ll hi = n;
        ll ans = lo;
        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;
            ll num = mid * 2 + 1;
            if (((num * num + 1) / 2) <= n)
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