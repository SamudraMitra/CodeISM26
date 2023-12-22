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
ll series(ll start, ll terms)
{
    ll termstofinishst = start;
    ll termsinseries = min(termstofinishst, terms);
    ll remterms = max(terms - termsinseries, 0ll);
    ll a = start;
    ll d = -1;
    ll sum = ((termsinseries * (2 * a + (termsinseries - 1) * d)) / 2) + remterms;
    return sum;
}
bool checker(ll mid, ll n, ll m, ll k)
{
    ll res = 0;
    ll leftpillow = series(mid, n - k + 1);
    ll rightpillow = series(mid - 1, k - 1);
    ll total = leftpillow + rightpillow;
    if (total <= m)
    {
        return 1;
    }
    return 0;
}
int main()
{
    fastio;
    ll n, m, k;
    cin >> n >> m >> k;
    ll lo = 1;
    ll hi = m;
    ll ans = 1;
    while (lo <= hi)
    {
        ll mid = lo + (hi - lo) / 2;
        if (checker(mid, n, m, k))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    // cout << series(3, 4) << "\n";
    // cout << checker(2, n, m, k);
    // cout << checker(5, n, m, k) << "\n";
    cout << ans << "\n";
}