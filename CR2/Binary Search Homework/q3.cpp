// https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/B ❤
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
    // cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for (auto &i : v)
            cin >> i;
        ll lo = *max_element(v.begin(), v.end());
        ll hi = accumulate(v.begin(), v.end(), 0ll);
        ll ans = hi;
        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;
            ll cnt = 0;
            for (ll i = 0; i < n; i++)
            {
                ll s = 0;
                bool f = true;
                while ((i < n) && ((s + v[i]) <= mid))
                {
                    s += v[i];
                    i++;
                    f = false;
                }
                if (!f)
                {
                    i--;
                    cnt++;
                }
            }
            if (cnt <= k)
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