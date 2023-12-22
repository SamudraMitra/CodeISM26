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
    ll a, b;
    cin >> a >> b;
    ll q;
    cin >> q;
    ll g = gcd(a, b);
    vector<ll> factors;
    for (ll i = 1; i * i <= g; i++)
    {
        if ((g % i) == 0)
        {
            factors.push_back(i);
            if (i != (g / i))
            {
                factors.push_back(g / i);
            }
        }
    }
    sort(factors.begin(), factors.end());
    // for (auto &i : factors)
    //     cout << i << " ";
    // cout << "\n";
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        ll left = lower_bound(factors.begin(), factors.end(), x) - factors.begin();
        ll right = upper_bound(factors.begin(), factors.end(), y) - factors.begin() - 1;
        // cout << left << " " << right << "\n\n";
        if (left <= right)
        {
            cout << factors[right] << "\n";
        }
        else
        {
            cout << "-1\n";
        }
    }
}

// 1 3 9