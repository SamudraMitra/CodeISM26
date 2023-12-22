#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
ll f(ll mid, ll n)
{
    if (mid % 2 == 0)
    {
        ll lo = mid;
        ll hi = mid + 1;
        ll cnt = 2;
        ll res = 0;
        while (n >= hi)
        {
            res += cnt;
            cnt = cnt * 2;
            lo = lo * 2;
            hi = hi * 2 + 1;
        }
        res += max((ll)0, n - lo + 1);
        return res;
    }
    else
    {
        ll lo = mid;
        ll hi = mid;
        ll cnt = 1;
        ll res = 0;
        while (n >= hi)
        {
            res += cnt;
            cnt = cnt * 2;
            lo = lo * 2;
            hi = hi * 2 + 1;
        }
        res += max((ll)0, n - lo + 1);
        return res;
    }
}
int main()
{
    ll t;
    // cin>>t;
    t = 1;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll loe = 1;
        ll hie = (n) / 2;
        ll loo = 1;
        ll hio = (n + 1) / 2;
        ll anso = 1;
        ll anse = 1;
        // cout<<f(5,11)<<"\n";
        // for(ll i=1;i<=11;i++)
        // {
        //     cout<<f(i,11)<<"\n";
        // }
        while (loe <= hie)
        {
            ll mid = loe + (hie - loe) / 2;
            if (f(2 * mid, n) >= k)
            {
                anse = 2 * mid;
                loe = mid + 1;
            }
            else
            {
                hie = mid - 1;
            }
        }
        while (loo <= hio)
        {
            ll mid = loo + (hio - loo) / 2;
            if (f((2 * mid - 1), n) >= k)
            {
                anso = 2 * mid - 1;
                loo = mid + 1;
            }
            else
            {
                hio = mid - 1;
            }
        }
        cout << max(anse, anso) << "\n";
    }
}