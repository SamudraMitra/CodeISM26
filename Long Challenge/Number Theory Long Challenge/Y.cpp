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
        ll n, q;
        cin >> n >> q;
        ll N = (ll)1e6;
        vector<ll> spf(N + 1);
        for (ll i = 1; i <= N; i++)
            spf[i] = i;
        for (ll i = 2; i * i <= N; i++)
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
        map<ll, ll> num;
        while (n > 1)
        {
            num[spf[n]]++;
            n /= spf[n];
        }
        map<ll, ll> copy;
        copy = num;
        while (q--)
        {
            ll type;
            cin >> type;
            if (type == 1)
            {
                ll x;
                cin >> x;
                while (x > 1)
                {
                    num[spf[x]]++;
                    x /= spf[x];
                }
                bool f = true;
                // ll res = 1;
                map<ll, ll> dem;
                for (auto &i : num)
                {
                    // res *= (i.second + 1);
                    ll term = i.second + 1;
                    while (term > 1)
                    {
                        dem[spf[term]]++;
                        term /= spf[term];
                    }
                }
                for (auto &i : dem)
                {
                    if (num[i.first] < i.second)
                    {
                        f = false;
                        break;
                    }
                }
                if (f)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
            else
            {
                num = copy;
            }
        }
        cout << "\n";
    }
}