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
    ll n;
    cin >> n;
    ll g = gcd(a, b);
    vector<ll> facts;
    for (ll i = 1; i * i <= g; i++)
    {
        if ((g % i) == 0)
        {
            facts.push_back(i);
            if (i != (g / i))
                facts.push_back(g / i);
        }
    }
    sort(facts.begin(), facts.end());
    // for (auto &i : facts)
    //     cout << i << " ";
    // cout << "\n";
    while (n--)
    {
        ll l, r;
        cin >> l >> r;
        auto z = *(upper_bound(facts.begin(), facts.end(), r) - 1);
        if (l <= z)
        {
            cout << z << "\n";
        }
        else
        {
            cout << "-1\n";
        }
    }
}