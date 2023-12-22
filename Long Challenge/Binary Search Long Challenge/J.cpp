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
ld f(ld mid, vector<pair<ll, ll>> &v, ll n)
{
    ld res = -1.0;
    for (ll i = 0; i < n; i++)
    {
        res = max(res, (v[i].second + abs(mid - v[i].first)));
    }
    return res;
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
        vector<pair<ll, ll>> v(n);
        for (auto &i : v)
        {
            cin >> i.first;
        }
        for (auto &i : v)
        {
            cin >> i.second;
        }
        sort(v.begin(), v.end());
        ld lo = v[0].first;
        ld hi = v[n - 1].first;
        ld eps = 1e-7;
        while ((hi - lo) > eps)
        {
            ld p1 = lo + (hi - lo) / 3;
            ld p2 = hi - (hi - lo) / 3;
            if (f(p1, v, n) > f(p2, v, n))
            {
                lo = p1;
            }
            else
            {
                hi = p2;
            }
        }
        cout << fixed << setprecision(7) << lo << "\n";
    }
}