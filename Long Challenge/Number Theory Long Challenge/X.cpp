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
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        // map<ll, ll> freq;
        vector<ll> freq(n + 1, 0);
        for (auto &i : v)
        {
            cin >> i;
            freq[i]++;
        }
        vector<ll> dp(n + 1, 0);
        for (ll i = n; i >= 1; i--)
        {
            ll term = 0;
            for (ll j = i; j <= n; j += i)
            {
                term += freq[j];
            }
            dp[i] = (term * (term - 1)) / 2;
            for (ll j = 2 * i; j <= n; j += i)
            {
                dp[i] -= dp[j];
            }
        }
        vector<ll> uni;
        for (ll i = 1; i <= n; i++)
        {
            if (freq[i] > 0)
                uni.push_back(i);
        }
        ll m = uni.size();
        for (ll i = 0; i < m; i++)
        {
            for (ll j = uni[i]; j <= n; j += uni[i])
            {
                dp[j] = 0;
            }
        }
        ll ans = accumulate(dp.begin(), dp.end(), 0ll);
        cout << ans << "\n";
    }
}