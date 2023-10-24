// https://www.codechef.com/problems/BEAUTIFULARR
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
long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    fastio;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for (auto &i : v)
            cin >> i;
        sort(v.begin(), v.end());
        ll lo = 0;
        ll hi = n;
        ll ans = lo;
        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;
            ll req = 0;
            for (ll i = 0; i < mid; i++)
            {
                req += (v[mid - 1] - v[i]);
            }
            if (req <= k)
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        ll moves = k;
        for (ll i = 0; i < ans; i++)
        {
            moves -= (v[ans - 1] - v[i]);
            v[i] = v[ans - 1];
        }
        ll y = moves / ans;
        for (ll i = 0; i < ans; i++)
        {
            if (moves == 0)
                break;
            moves -= y;
            v[i] += y;
        }
        for (ll i = 0; i < ans; i++)
        {
            if (moves == 0)
                break;
            moves--;
            v[i]++;
        }
        ll sum = 0;
        ll sos = 0;
        ll mod = 1e9 + 7;
        for (auto &i : v)
        {
            sum += i;
            sum %= mod;
            sos += i * i;
            sos %= mod;
        }
        cout << ((((((sum * sum) % mod - sos) + mod) % mod) * binpow(2, mod - 2, mod)) % mod) << "\n";
    }
}