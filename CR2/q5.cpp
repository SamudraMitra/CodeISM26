// https://codeforces.com/problemset/problem/1701/C
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll check(ll mid, map<ll, ll> &mp, ll tasks)
{
    ll res = 0;
    for (auto &it : mp)
    {
        res += min(it.second, mid) + max(((mid - it.second) / 2), 0ll);
    }
    if (res >= tasks)
        return 1;
    return 0;
}
pair<ll, ll> binarysearchfor000011111(ll lo, ll hi, map<ll, ll> &mp, ll tasks)
{
    ll ans = 0;
    while (lo <= hi)
    {
        ll mid = lo + (hi - lo) / 2;
        if (check(mid, mp, tasks))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return {ans, 0};
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> v(m);
        map<ll, ll> mp;
        for (auto &i : v)
        {
            cin >> i;
            mp[i]++;
        }
        for (ll i = 1; i <= n; i++)
        {
            if (mp[i] == 0)
            {
            }
        }
        cout << binarysearchfor000011111(0, 1000000, mp, m).first << "\n";
    }
}