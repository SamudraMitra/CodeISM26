#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define totalboxes(x) totalBoxes(reds, blues, a, b, x)

ld totalBoxes(ll reds, ll blues, ll a, ll b, ll ared)
{
    reds = reds - a * ared;
    blues = blues - b * ared;
    ld more = min((reds * 1.0) / b, (1.0 * blues) / a);
    return ared + more;
}

void solve()
{
    ll reds, blues, a, b;
    cin >> reds >> blues >> a >> b;
    ll low = 0;
    ll hi = min(reds / a, blues / b);

    while (hi > low + 2)
    { // local maxima
        ll p1 = low + (hi - low) / 3;
        ll p2 = hi - (hi - low) / 3;
        if (totalboxes(p2) <= totalboxes(p1))
        {
            hi = p2;
        }
        else
        {
            low = p1;
        }
    }
    cout << (ll)max(max(totalboxes(low), totalboxes(hi)), totalboxes((low + hi) / 2)) << endl;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}