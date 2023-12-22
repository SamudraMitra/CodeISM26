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
const ll mod = 998244353;
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll solve(ll upperbound, vector<ll> &pfs) // 2,[2]
{
    ll n = pfs.size();
    ll z = (1 << n);
    ll result = 0;
    for (ll mask = 1; mask < z; mask++)
    {
        ll term = 1;
        for (ll i = 0; i < n; i++)
        {
            if ((1 << i) & mask)
            {
                term *= pfs[i];
            }
        }
        ll bits = __builtin_popcountll(mask);
        if (bits % 2)
        {
            result += upperbound / term;
            result %= mod;
        }
        else
        {
            result -= upperbound / term;
            result += mod;
            result %= mod;
        }
    }
    return (((upperbound - result) % mod) + mod) % mod;
}
int main()
{
    fastio;
    ll t = 1;
    cin >> t;
    ll N = (ll)31623;
    vector<ll> lop;
    vector<bool> isprime(N + 1, true);
    for (ll i = 2; i <= N; i++)
    {
        if (isprime[i])
        {
            lop.push_back(i);
            for (ll j = i * i; j <= N; j += i)
            {
                if (isprime[j] == true)
                    isprime[j] = false;
            }
        }
    }
    isprime[1] = false;
    // cout << lop.size() << "\n";
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> v(n);
        for (auto &i : v)
            cin >> i;
        bool f = true;
        for (ll i = 0; i < n - 1; i++)
        {
            if ((v[i] % v[i + 1]) != 0)
            {
                f = false;
                break;
            }
        }
        if (f)
        {
            ll res = 1;
            for (ll i = 0; i < n - 1; i++)
            {
                ll g = v[i] / v[i + 1];       // 2
                ll upperbound = m / v[i + 1]; // 2
                vector<ll> prime_factors;
                for (auto &x : lop)
                {
                    if ((g % x) == 0)
                    {
                        prime_factors.push_back(x);
                        while ((g % x) == 0)
                            g /= x;
                    }
                    if (g == 1)
                        break;
                }
                if (g > 1)
                    prime_factors.push_back(g); //{2}
                res *= solve(upperbound, prime_factors);
                res %= mod;
            }
            cout << res << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
}