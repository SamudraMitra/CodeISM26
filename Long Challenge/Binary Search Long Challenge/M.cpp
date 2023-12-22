#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef long long ll;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    ll sum = 0;
    vector<ll> pref;
    vector<int> ind;
    int curInd = 0;
    for (auto &i : a)
    {
        cin >> i;
        sum += i;
        if (pref.empty() || sum > pref.back())
        {
            pref.push_back(sum);
            ind.push_back(curInd);
        }
        curInd++;
    }
    while (m--)
    {
        ll x;
        cin >> x;
        if (pref.back() < x && sum <= 0)
        {
            cout << -1 << " ";
            continue;
        }
        ll needTimes = 0;
        if (pref.back() < x)
        {
            needTimes = (x - pref.back() + sum - 1) / sum;
        }
        x -= needTimes * sum;
        cout << needTimes * n + ind[lower_bound(pref.begin(), pref.end(), x) - pref.begin()] << " ";
    }
    cout << "\n";
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}