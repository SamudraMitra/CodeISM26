#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b)
{
    return (b == 0) ? a : gcd(b, a % b);
}
int main()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &I : v)
        cin >> I;

    vector<ll> lr(n + 2, 0);
    vector<ll> rl(n + 2, 0);
    lr[0] = v[0];
    ll left = 0;
    ll right = 0;
    ll ans = n + 1;
    bool flag = true;
    while (right < n)
    {
        while (lr[right] != 1)
        {
            right++;
            if (right >= n)
            {
                flag = false;
                break;
            }
            lr[right] = gcd(lr[right - 1], v[right]); // prefix gcd in the range left to right
        }
        if (!flag)
        {
            break;
        }
        rl[right] = v[right];
        for (ll x = right - 1; x >= left; x--) // calculating suffix gcd
        {
            rl[x] = gcd(rl[x + 1], v[x]);
        }
        while (rl[left] == 1)
        {
            ans = min(ans, right - left + 1);
            left++;
        }
        right++;
        if (right >= n)
            break;
        lr[right] = gcd(rl[left], v[right]);
    }
    if (ans == n + 1)
        cout << -1 << "\n";
    else
        cout << ans << "\n";
}

// dry run using:
// 7
// 4 6 9 3 5 8 2