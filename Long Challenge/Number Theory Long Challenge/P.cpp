#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    fastio;
    ll N = (ll)(1e7);
    ll spf[N + 1];
    for (ll i = 0; i <= N; i++)
    {
        spf[i] = (i);
    }
    vector<ll> lop;
    for (ll i = 2; i * i <= N; i++)
    {
        if (spf[i] == i)
        {
            // lop.push_back(i);
            for (ll j = i * i; j <= N; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
    for (ll i = 2; i <= N; i++)
    {
        if (spf[i] == i)
            lop.push_back(i);
    }
    // cout<<lop.size()<<"\n";
    ll t = 1;
    // cin>>t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        map<ll, ll> m;
        for (ll i = 0; i < n; i++)
        {
            while (v[i] > 1)
            {
                ll x = spf[v[i]];
                m[x]++;
                while (v[i] % x == 0)
                {
                    v[i] /= x;
                }
            }
        }
        vector<pair<ll, ll>> pc;
        for (auto i : m)
        {
            pc.push_back({i.first, i.second});
        }
        for (ll i = 1; i < pc.size(); i++)
        {
            pc[i].second += pc[i - 1].second;
        }
        ll q;
        cin >> q;
        while (q--)
        {
            ll a, b;
            cin >> a >> b;
            pair<ll, ll> pr1 = {a, 0};
            pair<ll, ll> pr2 = {b, LLONG_MAX};

            ll g1 = lower_bound(pc.begin(), pc.end(), pr1) - pc.begin() - 1;
            ll g2 = upper_bound(pc.begin(), pc.end(), pr2) - pc.begin() - 1;
            ll res = ((g2 >= 0) ? (pc[g2].second) : 0) - ((g1 >= 0) ? pc[g1].second : 0);
            cout << res << "\n";
        }
    }
}