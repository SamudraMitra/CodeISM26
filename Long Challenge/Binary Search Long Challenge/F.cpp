#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
bool f(ll mid, ll n)
{
    ll v = 0;
    ll cp = n;
    while (n > 0)
    {
        if (n >= mid)
        {
            n -= mid;
            v += mid;
            n = n - (n / 10);
        }
        else
        {
            v += n;
            n = 0;
        }
    }
    return (v >= (cp + 1) / 2);
}
int main()
{
    ll t;
    t = 1;
    while (t--)
    {
        ll n;
        cin >> n;
        ll lo = 1;
        ll hi = n;
        ll ans = 0;
        while (lo <= hi)
        {
            ll mid = lo + (hi - lo) / 2;
            if (f(mid, n))
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