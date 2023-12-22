#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int mod = 1000000007;
#define f(i, n) for (int i = 0; i < n; i++)
#define fp(i, s, n) for (int i = s; i < n; i++)
#define fm(i, s) for (int i = s; i >= 0; i--)
#define fmm(i, s, n) for (int i = s; i >= n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define test(t) while (t--)
#define wge(i, n) while (i >= n)
#define wg(i, n) while (i > n)
#define wl(i, n) while (i < n)
#define wle(i, n) while (i <= n)
/*******************************************************************************************************************************
                                     ..........YOU RUN YOU GOT SUBMITTED..........
*******************************************************************************************************************************/
const int N = 1000000;

void precalculation(bool *isPrime)
{
    for (int i = 2; i <= N; i++)
        isPrime[i] = true;
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= N; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

void solve(bool *isPrime)
{
    int n;
    cin >> n;
    vector<int> vec(n);
    vector<string> ans(n);
    f(i, n)
    {
        cin >> vec[i];
        int x = sqrtl(vec[i]);
        if (x * x == vec[i] && isPrime[x])
            ans[i] = "YES";
        else
            ans[i] = "NO";
    }
    f(i, n) cout << ans[i] << endl;
    return;
}
int32_t main()
{
    // cout<<fixed;
    // cout<<setprecision(10);
    bool isPrime[N + 1];
    precalculation(isPrime);
    ll t = 1;
    // cin>>t;
    test(t)
    {
        solve(isPrime);
    }
    return 0;
}