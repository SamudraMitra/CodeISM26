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
    ll n, l, x, y;
    cin >> n >> l >> x >> y;
    vector<ll> v(n);
    unordered_set<ll> st;
    for (auto &i : v)
    {
        cin >> i;
        st.insert(i);
    }
    bool xp = false;
    bool yp = false;
    for (ll i = 0; i < n; i++)
    {
        if (st.find(v[i] + x) != st.end())
        {
            xp = true;
        }
        if (st.find(v[i] + y) != st.end())
        {
            yp = true;
        }
    }
    if (xp && yp)
    {
        cout << 0 << "\n";
    }
    else if (xp || yp)
    {
        cout << 1 << "\n";
        if (xp)
        {
            cout << y << "\n";
        }
        else
        {
            cout << x << "\n";
        }
    }
    else
    {
        for (ll i = 0; i < n; i++)
        {
            ll addedto = v[i] + x;
            if ((0 <= addedto) && (addedto <= l))
            {
                if ((st.find(addedto + y) != st.end()) || (st.find(addedto - y) != st.end()))
                {
                    cout << 1 << "\n";
                    cout << addedto << "\n";
                    return 0;
                }
            }
            addedto = v[i] - x;
            if ((0 <= addedto) && (addedto <= l))
            {
                if ((st.find(addedto + y) != st.end()) || (st.find(addedto - y) != st.end()))
                {
                    cout << 1 << "\n";
                    cout << addedto << "\n";
                    return 0;
                }
            }
            addedto = v[i] + y;
            if ((0 <= addedto) && (addedto <= l))
            {
                if ((st.find(addedto + x) != st.end()) || (st.find(addedto - x) != st.end()))
                {
                    cout << 1 << "\n";
                    cout << addedto << "\n";
                    return 0;
                }
            }
            addedto = v[i] - y;
            if ((0 <= addedto) && (addedto <= l))
            {
                if ((st.find(addedto + x) != st.end()) || (st.find(addedto - x) != st.end()))
                {
                    cout << 1 << "\n";
                    cout << addedto << "\n";
                    return 0;
                }
            }
        }
        cout << 2 << "\n";
        cout << x << " " << y << "\n";
    }
}