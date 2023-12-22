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
        ll a, b, c, d, e, f;
        cin >> c >> d >> e >> f >> a >> b;
        cout << max(0ll, min(min(min(c - 1, d - 1), min(e - 1, f - 1)), b) - a + 1);
    }
}