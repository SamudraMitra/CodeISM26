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
    vector<ll> freq(1e5 + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        freq[v[i]]++;
    }
    ll N = (ll)1e5;
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
    ll res = 1;
    for (auto &i : lop)
    {
        ll term = 0;
        for (ll j = i; j <= 1e5; j += i)
        {
            term += freq[j];
        }
        res = max(res, term);
    }
    cout << res << "\n";
}