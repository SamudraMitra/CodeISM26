#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
ll f(ll mid, vector<ll> &a, vector<ll> &b, ll n, ll m)
{
    ll res = 0;
    for (ll i = 0; i < n; i++)
    {
        res += max((mid - a[i]), (ll)0);
    }
    for (ll i = 0; i < m; i++)
    {
        res += max((b[i] - mid), (ll)0);
    }
    return res;
}
int main()
{
    ll t;
    t = 1;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n);
        vector<ll> b(m);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (ll i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        ll lo = 1;
        ll hi = (ll)(1e9);
        while (hi - lo >= 3)
        {
            ll mid1 = lo + (hi - lo) / 3;
            ll mid2 = hi - (hi - lo) / 3;
            if (f(mid1, a, b, n, m) < f(mid2, a, b, n, m))
            {
                hi = mid2;
            }
            else
            {
                lo = mid1;
            }
        }
        ll ans = LLONG_MAX;
        for (ll i = lo; i <= hi; i++)
        {
            ans = min(ans, f(i, a, b, n, m));
        }
        cout << ans << "\n";
    }
}