#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define fr(i, n) for (ll i = 0; i < n; i++)
const int N = 2e5 + 5;
int n, k;
vector<int> a(N);
vector<int> cop;
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
bool check(int x, int cur)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!cur)
        {
            ans++;
            cur ^= 1;
        }
        else
        {
            if (a[i] <= x)
            {
                ans++;
                cur ^= 1;
            }
        }
    }
    return ans >= k;
}
int binsearch(int lo, int hi)
{
    ll ans = hi;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(cop[mid], 0) || check(cop[mid], 1))
        {
            ans = cop[mid];
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return ans;
}
int32_t main()
{
    fastio;
    ll t = 1;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            cop.push_back(a[i]);
        }
        sort(cop.begin(), cop.end());
        int ans = binsearch(0, n - 1);
        cout << ans;
    }
}