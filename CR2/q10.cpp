// https://codeforces.com/problemset/problem/1707/A

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
bool checker(ll mid, vector<ll> &v, ll n, ll k)
{
    ll leave = n - mid;
    ll cnt = 0;
    for (ll i = 0; i < n; i++)
    {
        if (v[i] <= k)
        {
            cnt++;
        }
        else
        {
            if (leave > 0)
            {
                leave--;
            }
            else
            {
                cnt++;
                k--;
            }
        }
        if (k < 0)
            return false;
    }
    return true;
}
int main()
{
    fastio;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for (auto &i : v)
            cin >> i;
        ll lo = 0;
        ll hi = n;
        ll ans = 0;
        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;
            if (checker(mid, v, n, k))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        vector<ll> res(n, 0);
        ll leave = n - ans;
        for (ll i = 0; i < n; i++)
        {
            if (v[i] <= k)
            {
                res[i] = 1;
            }
            else
            {
                if (leave > 0)
                {
                    leave--;
                }
                else
                {
                    res[i] = 1;
                }
            }
        }
        for (auto &i : res)
            cout << i;
        cout << "\n";
    }
}