// https://codeforces.com/problemset/problem/1680/C
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
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        int pre[n];
        int x = 0;
        for (int i = 0; i < n; i++)
        {
            x += (s[i] == '1');
            pre[i] = x;
        }
        int ans = pre[n - 1];
        for (int i = 0; i < n; i++)
        {
            int l = i, r = n - 1;
            while (l <= r)
            {
                int mid = l + (r - l) / 2;
                int zeroleft = (mid - i + 1) - (pre[mid] - (i != 0 ? pre[i - 1] : 0));
                int oneremoved = pre[n - 1] - (pre[mid] - (i != 0 ? pre[i - 1] : 0));
                if (zeroleft >= oneremoved)
                {
                    ans = min(zeroleft, ans);
                    r = mid - 1;
                }
                else
                {
                    ans = min(ans, oneremoved);
                    l = mid + 1;
                }
            }
        }
        cout << ans << endl;
    }
}