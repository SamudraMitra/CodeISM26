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
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> facts;
        for (ll i = 1; i * i <= n; i++)
        {
            if ((n % i) == 0)
            {
                facts.push_back(i);
                if (i != (n / i))
                    facts.push_back(n / i);
            }
        }
        sort(facts.begin(), facts.end());
        facts.pop_back();
        cout << facts.back() << " " << n - facts.back() << "\n";
    }
}