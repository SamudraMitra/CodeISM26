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
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    ll g = 0;
    for (auto &i : v)
    {
        g = gcd(g, i);
    }
    for (auto &i : v)
    {
        i /= g;
    }
    ll N = (ll)(15e6);
    vector<ll> lop;
    vector<ll> spf(N + 1);
    for (ll i = 1; i <= N; i++)
        spf[i] = i;
    for (ll i = 2; i <= N; i++)
    {
        if (spf[i] == i)
        {
            lop.push_back(i);
            for (ll j = i * i; j <= N; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
    // cout << lop.size() << "\n";
    map<ll, ll> pfreq;
    for (auto &num : v)
    {
        ll z = num;
        set<ll> prime_factors;
        while (z > 1)
        {
            prime_factors.insert(spf[z]);
            z /= spf[z];
        }
        for (auto &i : prime_factors)
        {
            pfreq[i]++;
        }
    }
    ll optimal_prime = 1;
    ll maxfreq = -1;
    for (auto &i : pfreq)
    {
        if (maxfreq < i.second)
        {
            maxfreq = i.second;
            optimal_prime = i.first;
        }
    }
    if (maxfreq == -1)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << n - maxfreq << "\n";
    }
}

// ad