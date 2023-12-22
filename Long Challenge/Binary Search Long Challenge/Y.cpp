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
ld f(ll mid, ll medind, vector<ll> &pref, vector<ll> &v, ll n)
{
    ll leftsum = pref[medind - 1] - pref[medind - 1 - mid];
    ll rightsum = pref[n] - pref[n - mid];
    ld mean = ((leftsum + rightsum + v[medind - 1]) * (1.0)) / (2.0 * mid + 1);
    ld median = v[medind - 1];
    return (mean - median);
}
int main()
{
    fastio;
    ll t = 1;

    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (auto &I : v)
            cin >> I;
        sort(v.begin(), v.end());
        vector<ll> copy(n + 1, 0);
        for (ll i = 1; i <= n; i++)
        {
            copy[i] = v[i - 1];
            copy[i] += copy[i - 1];
        }
        vector<ll> res;
        ll ressize = 0;
        ld ss = -1;
        ll bestmed = -1;
        for (ll i = 0; i < n; i++)
        {
            ll medind = i + 1;
            ll lo = 0;
            ll hi = min(i, n - 1 - i);
            while (hi - lo > 5)
            {
                ll m1 = lo + ((hi - lo) / 3);
                ll m2 = hi - ((hi - lo) / 3);
                if (f(m1, medind, copy, v, n) > f(m2, medind, copy, v, n))
                {
                    hi = m2;
                }
                else
                {
                    lo = m1;
                }
            }
            ld ans = -1;
            ll siz = 0;
            for (ll x = lo; x <= hi; x++)
            {
                if (1e-11 < (f(x, medind, copy, v, n) - ans))
                {
                    ans = f(x, medind, copy, v, n);
                    siz = x;
                }
            }
            if (ans > ss)
            {
                ss = ans;
                ressize = siz;
                bestmed = i;
            }
        }
        cout << 2 * ressize + 1 << "\n";
        for (ll k = bestmed - ressize; k < bestmed; k++)
        {
            cout << v[k] << " ";
        }
        cout << v[bestmed] << " ";

        for (ll k = n - ressize; k < n; k++)
        {

            cout << v[k] << " ";
        }

        cout << "\n";
    }
}