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
bool check(ll n, ll m, ll k, ll q, ll mid, vector<vector<ll>> &v)
{
    vector<vector<ll>> monitor(n + 1, vector<ll>(m + 1, 0));
    for (auto &i : v)
    {
        if (i[2] <= mid)
        {
            monitor[i[0]][i[1]] = 1;
        }
    }
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= m; j++)
        {
            monitor[i][j] += (((j - 1) >= 0) ? monitor[i][j - 1] : 0) + (((i - 1) >= 0) ? monitor[i - 1][j] : 0) - ((((i - 1) >= 0) && ((j - 1) >= 0)) ? monitor[i - 1][j - 1] : 0);
        }
    }
    for (ll i = 1; i + k - 1 <= n; i++)
    {
        for (ll j = 1; j + k - 1 <= m; j++)
        {
            ll sum = monitor[i + k - 1][j + k - 1] + monitor[i - 1][j - 1] - (monitor[i - 1][j + k - 1] + monitor[i + k - 1][j - 1]);
            if (sum == k * k)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    fastio;
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, m, k, q;
        cin >> n >> m >> k >> q;
        vector<vector<ll>> v;
        while (q--)
        {
            vector<ll> temp(3, 0);
            for (auto &i : temp)
                cin >> i;
            v.push_back(temp);
        }
        ll lo = 0;
        ll hi = 1e9 + 1;
        ll ans = -1;
        while (lo <= hi)
        {
            ll mid = lo + (hi - lo) / 2;
            if (check(n, m, k, q, mid, v))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}