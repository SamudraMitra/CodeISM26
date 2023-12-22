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
vector<ll> factmodm(10000, 1);
vector<ll> factmodminv(10000, 1);
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll modinv(ll a)
{
    return binpow(a, mod - 2, mod);
}
ll f(ll idx, ll n, ll ptobetaken, vector<pair<ll, ll>> &primesandfreqs, vector<vector<ll>> &dp)
{
    ll op1 = 0, op2 = 0;
    if (idx >= n)
    {
        if (ptobetaken == 0)
            return 1;
        return 0;
    }
    if (dp[idx][ptobetaken] != -1)
        return dp[idx][ptobetaken];
    if (ptobetaken > 0)
    {
        op1 = ((factmodminv[(primesandfreqs[idx].second - 1)]) * f(idx + 1, n, ptobetaken - 1, primesandfreqs, dp)) % mod;
    }
    op2 = ((factmodminv[primesandfreqs[idx].second]) * f(idx + 1, n, ptobetaken, primesandfreqs, dp)) % mod;
    return (dp[idx][ptobetaken] = (op1 + op2) % mod);
}
int main()
{
    fastio;
    for (ll i = 1; i < 10000; i++)
    {
        factmodm[i] = (factmodm[i - 1] * i) % mod;
    }
    for (ll i = 0; i < 10000; i++)
    {
        factmodminv[i] = modinv(factmodm[i]);
    }

    ll n;
    cin >> n;
    vector<ll> v(2 * n);
    for (auto &i : v)
        cin >> i;
    ll num = 1;
    for (ll i = 1; i <= n; i++)
    {
        num *= i;
        num %= mod;
    }

    ll N = (ll)1e6;
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
    vector<ll> freq(1e6 + 1, 0);
    for (auto &i : v)
        freq[i]++;
    ll distprime = 0;
    vector<ll> nonporimesfreq;
    for (ll i = 1; i <= 1e6; i++)
    {
        if ((isprime[i]) && (freq[i] > 0))
        {
            distprime++;
        }
        if ((freq[i] > 0) && (!isprime[i]))
        {
            nonporimesfreq.push_back(freq[i]);
        }
    }
    if (distprime >= n)
    {
        for (auto &i : nonporimesfreq)
        {
            ll dem = 1;
            for (ll j = 1; j <= i; j++)
            {
                dem *= j;
                dem %= mod;
            }
            num *= modinv(dem);
            num %= mod;
        }
        vector<pair<ll, ll>> primesandfreqs;
        for (ll i = 1; i <= 1e6; i++)
        {
            if ((isprime[i]) && (freq[i] > 0))
            {
                primesandfreqs.push_back({i, freq[i]});
            }
        }
        vector<vector<ll>> dp(2 * n + 1, vector<ll>(2 * n + 1, -1));
        ll res = (num * f(0, primesandfreqs.size(), n, primesandfreqs, dp)) % mod;
        cout << res << "\n";
    }
    else
    {
        cout << 0 << "\n";
    }
}