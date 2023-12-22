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
ll solve(ll a, ll b)
{
    vector<ll> divbig, divsm;
    for (ll i = 1; i <= sqrt(a + b); i++)
    {
        if (((a + b) % i) == 0)
        {
            divbig.push_back(i);
        }
    }
    for (ll i = 1; i <= sqrt(a); i++)
    {
        if ((a % i) == 0)
        {
            divsm.push_back(i);
        }
    }
    ll n = divbig.size();
    ll m = divsm.size();
    ll res = LLONG_MAX;
    for (ll i = 0; i < n; i++)
    {
        auto z = upper_bound(divsm.begin(), divsm.end(), divbig[i]) - divsm.begin() - 1;
        if (z == -1)
            continue;
        ll smside = divsm[z];
        ll bigvert = ((a + b) / divbig[i]);
        ll smvert = (a / smside);
        if (smvert <= bigvert)
        {
            ll peri = (divbig[i] + bigvert) * 2;
            res = min(res, peri);
        }
    }
    return res;
}
int main()
{
    fastio;
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        ll op1 = solve(a, b);
        ll op2 = solve(b, a);
        cout << min(op1, op2) << "\n";
    }
}