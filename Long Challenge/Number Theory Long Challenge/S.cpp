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
long long binpow(long long a, long long b)
{
    // a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll spf[(ll)(1e7 + 1)];
void factorise(ll n, vector<pair<ll, ll>> &p)
{
    map<ll, ll> m;
    while (spf[n] != n)
    {
        m[spf[n]]++;
        n /= spf[n];
    }
    if (n != 1)
        m[n]++;
    for (auto &i : m)
    {
        p.push_back({i.first, i.second});
    }
}
int main()
{
    fastio;
    ll t = 1;
    ll N = (ll)(1e7);
    vector<ll> lop;
    for (ll i = 2; i <= N; i++)
        spf[i] = i;
    for (ll i = 2; i <= N; i++)
    {
        if (spf[i] == i)
        {
            for (ll j = i * i; j <= N; j += i)
            {
                spf[j] = i;
            }
        }
    }
    while (t--)
    {
        vector<ll> upper;
        vector<ll> lower;
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
            cin >> v[i];
        for (ll i = 0; i < n; i++)
        {
            ll d = -1;
            vector<pair<ll, ll>> m;
            factorise(v[i], m);
            ll x = m.size();
            for (ll mask = 0; mask < (1 << x); mask++)
            {
                ll d1 = 1;
                for (ll k = 0; k < x; k++)
                {
                    if (mask & (1 << k))
                    {
                        d1 *= (binpow((m[k].first), (m[k].second)));
                    }
                }
                ll d2 = v[i] / d1;
                if ((((gcd(d1 + d2, v[i])) == 1) && (d1 > 1)) && (d2 > 1))
                {
                    upper.push_back(d1);
                    lower.push_back(d2);
                    d = 0;
                    break;
                }
            }
            if (d == -1)
            {
                upper.push_back(-1);
                lower.push_back(-1);
            }
        }
        for (auto &i : upper)
        {
            cout << i << " ";
        }
        cout << "\n";
        for (auto &i : lower)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}