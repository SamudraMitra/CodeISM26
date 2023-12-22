#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int main()
{
    ll t;
    t = 1;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            v[i] = abs(v[i]);
        }
        sort(v.begin(), v.end());
        ll res = 0;
        for (ll i = 0; i < n; i++)
        {
            ll x = (v[i] + 1) / 2;
            ll ub1 = lower_bound(v.begin(), v.end(), x) - v.begin();
            res += i - ub1;
        }
        cout << res << "\n";
    }
}