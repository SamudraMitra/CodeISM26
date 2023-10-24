// https://www.codechef.com/practice/INTBINS01/problems/SNAKEEAT
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
        vector<ll> v(n);
        for (auto &i : v)
            cin >> i;
        sort(v.begin(), v.end());
        vector<ll> ps(n, 0);
        ps[0] = v[0];
        for (ll i = 1; i < n; i++)
        {
            ps[i] = ps[i - 1] + v[i];
        }
        while (k--)
        {
            ll x;
            cin >> x;
            ll lo = 0;
            ll pos = lower_bound(v.begin(), v.end(), x) - v.begin();
            ll hi = pos;
            ll ans = lo;
            while (lo <= hi)
            {
                ll mid = (lo + hi) / 2;
                ll z = (x * mid) - ((((pos - 1) >= 0) ? ps[pos - 1] : 0ll) - (((pos - mid - 1) >= 0) ? ps[pos - mid - 1] : 0ll));
                if ((pos - mid) >= z)
                {
                    ans = mid;
                    lo = mid + 1;
                }
                else
                {
                    hi = mid - 1;
                }
            }
            cout << ans + (n - pos) << "\n";
        }
    }
}