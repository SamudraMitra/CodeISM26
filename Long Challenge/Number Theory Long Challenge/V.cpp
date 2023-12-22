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
const ll mod = 998244353;
ll comp(vector<pair<ll, ll>> &v, ll n, ll sum)
{
    vector<vector<ll>> dp(n + 1, vector<ll>(sum + 1, 0));
    dp[0][0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        ll tot = 0;
        ll left = v[i - 1].first;
        ll right = v[i - 1].second;
        for (ll j = 0; j <= sum; j++)
        {
            if (j >= left)
            {
                dp[i][j] += dp[i - 1][j - left];
                dp[i][j] %= mod;
            }
            if (j >= (right + 1))
            {
                dp[i][j] -= dp[i - 1][j - right - 1];
                dp[i][j] += mod;
                dp[i][j] %= mod;
            }
        }
        for (ll j = 1; j <= sum; j++)
        {
            dp[i][j] += dp[i][j - 1];
            dp[i][j] %= mod;
        }
    }
    ll res = 0;
    for (ll i = 0; i <= sum; i++)
    {
        res += dp[n][i];
        res %= mod;
    }
    return res;
}
int main()
{
    fastio;
    vector<ll> g(1e5 + 1, 0);
    vector<ll> f(1e5 + 1, 0);
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> v(n);
    for (auto &i : v)
        cin >> i.first >> i.second;
    for (ll i = 1; i <= 1e5; i++)
    {
        vector<pair<ll, ll>> cv(v);
        for (auto &x : cv)
        {
            x.first = ((x.first + i - 1) / i);
            x.second = (x.second / i);
        }
        g[i] = comp(cv, n, m / i);
    }
    for (ll i = m; i >= 1; i--)
    {
        f[i] = g[i];
        for (ll j = 2 * i; j <= m; j += i)
        {
            f[i] = (f[i] - f[j] + mod) % mod;
        }
    }
    cout << f[1] << "\n";
}