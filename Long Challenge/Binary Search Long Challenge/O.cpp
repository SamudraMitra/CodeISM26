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
ll f(ll mid, ll n, ll a, ll r, ll m, vector<ll> &v)
{
    ll tba = 0;
    ll tbr = 0;
    for (ll i = 0; i < n; i++)
    {
        if (v[i] > mid)
        {
            tbr += (v[i] - mid);
        }
        else
        {
            tba += (mid - v[i]);
        }
    }
    if (tba > tbr)
    {
        ll sum = (tba - tbr) * a + tbr * m;
        return sum;
    }
    else
    {
        ll sum = (tbr - tba) * r + tba * m;
        return sum;
    }
}
int main()
{
    fastio;
    ll n, m, a, r;
    cin >> n >> a >> r >> m;
    vector<ll> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    m = min(m, a + r);
    ll lo = 0;
    ll hi = *max_element(v.begin(), v.end());
    while (lo + 5 < hi)
    {
        ll m1 = lo + (hi - lo) / 3;
        ll m2 = hi - (hi - lo) / 3;
        if (f(m1, n, a, r, m, v) < f(m2, n, a, r, m, v))
        {
            hi = m2;
        }
        else
        {
            lo = m1;
        }
    }
    ll ans = LLONG_MAX;
    for (ll i = lo; i <= hi; i++)
    {
        ans = min(ans, f(i, n, a, r, m, v));
    }
    cout << ans << "\n";
}