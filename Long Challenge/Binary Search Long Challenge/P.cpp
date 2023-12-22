#include <bits/stdc++.h>
#define long long int
using namespace std;

bool check(int day, int n, int m, vector<int> &k, vector<pair<int, int>> &q)
{
    vector<int> lst(n, -1);
    for (int i = 0; i < m; ++i)
    {
        if (q[i].first <= day)
        {
            lst[q[i].second] = max(lst[q[i].second], q[i].first);
        }
    }
    vector<vector<int>> off(1001);
    for (int i = 0; i < n; ++i)
    {
        if (lst[i] != -1)
        {
            off[lst[i]].push_back(i);
        }
    }
    vector<int> need = k;
    int cur_money = 0;
    for (int i = 0; i <= day; ++i)
    {
        ++cur_money;
        if (i > 1000)
            continue;
        for (auto it : off[i])
        {
            if (cur_money >= need[it])
            {
                cur_money -= need[it];
                need[it] = 0;
            }
            else
            {
                need[it] -= cur_money;
                cur_money = 0;
                break;
            }
        }
    }
    return accumulate(need.begin(), need.end(), 0) * 2 <= cur_money;
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<int> k(n);
    vector<pair<int, int>> q(m);
    for (int i = 0; i < n; ++i)
    {
        cin >> k[i];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> q[i].first >> q[i].second;
        --q[i].first;
        --q[i].second;
    }
    int lo = 0;
    int hi = 2000;
    int ans = hi;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (check(mid, n, m, k, q))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << (ans + 1) << "\n";
}