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
ld f(ll n, vector<ld> &v, ld mid)
{
    vector<ld> pref = {0.0};
    for (auto &i : v)
    {
        pref.push_back(i - mid);
    }
    for (ll i = 1; i <= n; i++)
    {
        pref[i] += pref[i - 1];
    }
    ld maxel = *max_element(pref.begin(), pref.end());
    ld minel = *min_element(pref.begin(), pref.end());
    return abs(maxel - minel);
}
int main()
{
    fastio;
    ll n;
    cin >> n;
    vector<ld> v(n);
    for (auto &i : v)
        cin >> i;
    ld lo = -1000000;
    ld hi = 1000000;
    ld eps = 5e-12;
    while (hi - lo > eps)
    {
        ld m1 = lo + (hi - lo) / 3.0;
        ld m2 = hi - (hi - lo) / 3.0;
        if (f(n, v, m1) > f(n, v, m2))
        {
            lo = m1;
        }
        else
        {
            hi = m2;
        }
    }
    ld ans = f(n, v, lo);

    cout << fixed << setprecision(7) << ans << "\n";
}