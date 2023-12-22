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
    ll N = (ll)1e6;
    vector<ll> lop;
    vector<ll> spf(N + 1);
    for (ll i = 1; i <= N; i++)
        spf[i] = i;
    for (ll i = 2; i <= N; i++)
    {
        if (spf[i] == i)
        {
            for (ll j = i * i; j <= N; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    map<ll, ll> num_lcm;
    map<ll, ll> kay;
    ll z = k;
    while (z > 1)
    {
        kay[spf[z]]++;
        z /= spf[z];
    }

    for (auto i : v)
    {
        map<ll, ll> fact;
        z = i;
        while (z > 1)
        {
            fact[spf[z]]++;
            z /= spf[z];
        }
        // for (auto &i : fact)
        //     cout << i.first << " " << i.second << "\n";
        // cout << "\n";
        for (auto &i : fact)
        {
            num_lcm[i.first] = max(num_lcm[i.first], i.second);
        }
    }
    bool f = true;
    for (auto &i : kay)
    {
        if (num_lcm[i.first] < i.second)
        {
            f = false;
            break;
        }
    }
    if (f)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}