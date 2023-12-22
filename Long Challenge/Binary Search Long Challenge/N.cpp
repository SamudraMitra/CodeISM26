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
bool check(ll mid, vector<ll> &freee, ll m, ll k)
{
    ll p = 0;
    ll c = 0;
    while (p < m)
    {
        ll x = freee[p];
        ll nex = upper_bound(freee.begin(), freee.end(), x + mid + 1) - freee.begin() - 1;
        if ((nex == p) && (p != (m - 1)))
            return false;
        if (p == m - 1)
            break;
        p = nex;
        c++;
    }
    return (c < k);
}
int main()
{
    fastio;
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> freee;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            freee.push_back(i);
        }
    }
    ll m = freee.size();
    ll lo = 0;
    ll hi = n - 2;
    ll ans = hi;
    while (lo <= hi)
    {
        ll mid = lo + (hi - lo) / 2;
        if (check(mid, freee, m, k))
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