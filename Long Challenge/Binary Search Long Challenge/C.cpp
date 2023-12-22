#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
bool f(ll mid, vector<ll> &v, ll h, ll n)
{
    ll sum = 0;
    ll res = 0;
    vector<ll> copy(mid);
    for (ll i = 0; i < mid; i++)
    {
        copy[i] = v[i];
    }
    sort(copy.begin(), copy.end(), greater<ll>());
    for (ll i = 0; i < mid; i += 2)
    {
        ll x = copy[i];
        sum += copy[i];
    }
    if (sum <= h)
        return true;
    else
        return false;
}
int main()
{
    ll t;
    t = 1;
    while (t--)
    {
        ll n, h;
        cin >> n >> h;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ll lo = 0;
        ll hi = n;
        ll ans = 0;
        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;
            if (f(mid, v, h, n))
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