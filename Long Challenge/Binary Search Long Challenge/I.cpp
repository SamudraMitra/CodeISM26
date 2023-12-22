#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int inf = 1e18;
bool isPossible(vector<int> &v, int k, int mid)
{
    map<int, int> mp;
    for (auto i : v)
        mp[i]++;
    int cnt = 0;
    for (auto i : mp)
    {
        int k = i.second;
        cnt += k / mid;
    }
    return cnt >= k;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int st = 1;
    int en = n / k;
    int cnt = 1;
    while (st <= en)
    {
        int mid = (st + en) / 2;
        if (isPossible(v, k, mid))
        {
            cnt = mid;
            st = mid + 1;
        }
        else
            en = mid - 1;
    }
    map<int, int> mp;
    for (auto i : v)
        mp[i] += 1;
    vector<int> ans;
    for (auto i : mp)
    {
        int k = i.second;
        while (k >= cnt)
        {
            k -= cnt;
            ans.push_back(i.first);
        }
    }
    for (int i = 0; i < k; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}