// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/H

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
bool f(ll mid, ll br, ll nb, ll pb, ll cr, ll nc, ll pc, ll sr, ll ns, ll ps, ll r)
{
    return (((max((br * mid - nb), 0ll) * pb) + (max((cr * mid - nc), 0ll) * pc) + (max((sr * mid - ns), 0ll) * ps)) <= r);
}
int main()
{
    fastio;
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll nb, ns, nc, pb, ps, pc;
        cin >> nb >> ns >> nc >> pb >> ps >> pc;
        ll r;
        cin >> r;
        ll lo = 0;
        ll hi = 1e13;
        ll br = 0;
        ll cr = 0;
        ll sr = 0;

        for (auto &i : s)
        {
            if (i == 'B')
                br++;
            if (i == 'C')
                cr++;
            if (i == 'S')
                sr++;
        }
        ll ans = lo;
        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;
            if (f(mid, br, nb, pb, cr, nc, pc, sr, ns, ps, r))
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
