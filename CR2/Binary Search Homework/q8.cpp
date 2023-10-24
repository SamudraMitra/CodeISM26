// https://www.codechef.com/problems/DIVIDE_GROUP

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
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for (auto &i : v)
            cin >> i;
        sort(v.rbegin(), v.rend());
        ll sum = accumulate(v.begin(), v.end(), 0ll);
        ll lo = 0;
        ll hi = (sum / k);
        ll ans = lo;
        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;
            ll waste = (sum - k * mid);
            ll temp = 0;
            for (ll i = 0; i < n; i++)
            {
                if (v[i] > mid)
                {
                    temp += (v[i] - mid);
                }
                else
                    break;
            }
            if (waste >= temp)
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        cout << ans << "\n";
    }
}