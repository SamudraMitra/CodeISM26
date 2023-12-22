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
bool isafe(ll x, ll y, ll n, ll m)
{
    return (((0 <= x) && (x < n)) && ((0 <= y) && (y < m)));
}
bool checker(ll mid, vector<vector<ll>> &v, ll n, ll m)
{
    vector<vector<ll>> copy(n, vector<ll>(m, 0));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (v[i][j] >= mid)
            {
                copy[i][j] = 1;
            }
        }
    }
    // for (auto &i : copy)
    // {
    //     for (auto &j : i)
    //         cout << j << " ";
    //     cout << "\n";
    // }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            copy[i][j] += ((((i - 1) >= 0) ? copy[i - 1][j] : 0) + ((j - 1) >= 0 ? (copy[i][j - 1]) : 0) - ((((i - 1) >= 0) && ((j - 1) >= 0)) ? (copy[i - 1][j - 1]) : 0));
        }
    }

    for (ll i = 0; i + mid - 1 < n; i++)
    {
        for (ll j = 0; j + mid - 1 < m; j++)
        {
            ll temp = (isafe(i + mid - 1, j + mid - 1, n, m) ? copy[i + mid - 1][j + mid - 1] : 0) + (isafe(i - 1, j - 1, n, m) ? copy[i - 1][j - 1] : 0) - (isafe(i + mid - 1, j - 1, n, m) ? copy[i + mid - 1][j - 1] : 0) - (isafe(i - 1, j + mid - 1, n, m) ? copy[i - 1][j + mid - 1] : 0);
            if (temp == mid * mid)
                return true;
        }
    }
    return false;
}
int main()
{
    fastio;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> v(n, vector<ll>(m, 0));
        for (auto &i : v)
        {
            for (auto &j : i)
                cin >> j;
        }
        ll lo = 1;
        ll hi = min(n, m);
        ll ans = lo;
        while (lo <= hi)
        {
            ll mid = lo + (hi - lo) / 2;
            if (checker(mid, v, n, m))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        // cout << checker(2, v, n, m) << "\n";
        cout << ans << "\n";
    }
}