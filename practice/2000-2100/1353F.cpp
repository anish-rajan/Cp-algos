#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define v vector
#define inp_push(no, v) \
    ll no;              \
    cin >> no;          \
    v.push_back(no);
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 100005
#define mod 1000000007
#define INF INT64_MAX
ll t;
long long powmod(long long x, long long y, long long m)
{
    long long res = 1LL;
    while (y)
    {
        if (y & 1)
            res = (res * x) % m;
        // cout << x << " " << mod << "\n";
        x = (x * x) % m;
        y /= 2;
    }
    return res;
}

ll comp(ll k, ll l, ll c2l, ll c1l, ll akl, ll val)
{
    if (l > 1)
    {
        if (k > 1 && akl >= val)
        {
            if (c1l == INF && c2l == INF)
                return INF;
            return min(c2l, c1l) + (akl >= val ? akl - val : INF);
        }
        else if (akl >= val)
        {
            if (c2l == INF)
                return INF;
            return c2l + (akl >= val ? akl - val : INF);
        }
        else
            return INF;
    }
    else
    {
        if (k > 1 && akl >= val)
        {
            if (c1l == INF)
                return INF;
            return c1l + (akl >= val ? akl - val : INF);
        }
        else if (akl >= val)
            return (akl >= val ? akl - val : INF);
        else
            return INF;
    }
}
ll comp(ll k, ll l, ll c2l, ll c1l, ll akl, ll val, ll n, ll m)
{
    if (l < m)
    {
        if (k < n && akl >= val)
        {
            if (c1l == INF && c2l == INF)
                return INF;
            return min(c2l, c1l) + (akl >= val ? akl - val : INF);
        }
        else if (akl >= val)
        {
            if (c2l == INF)
                return INF;
            return c2l + (akl >= val ? akl - val : INF);
        }
        else
            return INF;
    }
    else
    {
        if (k < n && akl >= val)
        {
            if (c1l == INF)
                return INF;
            return c1l + (akl >= val ? akl - val : INF);
        }
        else if (akl >= val)
            return (akl >= val ? akl - val : INF);
        else
            return INF;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        v<v<ll>> a(n + 2, v<ll>(m + 2)), dp(n + 2, v<ll>(m + 2, INF)), dp1(n + 2, v<ll>(m + 2, INF));
        for (ll i = 1; i <= n; i++)
            for (ll j = 1; j <= m; j++)
                cin >> a[i][j];
        for (ll i = 1; i <= n; i++)
            for (ll j = 1; j <= m; j++)
            {
                v<ll> c1(m + 2, INF), c2(m + 2, INF);
                for (ll k = 1; k <= i; k++)
                {
                    for (ll l = 1; l <= j; l++)
                    {
                        if (k == i && l == j)
                            continue;
                        ll val = a[i][j] - (i + j - 2) + (k + l - 2);

                        c2[l] = comp(k, l, c2[l - 1], c1[l], a[k][l], val);
                        // if (i == 2 && j == 2)
                        //     cout << val << " " << a[k][l] << " " << c2[l] << "\n";
                    }
                    if (k != i)
                        c1 = c2;
                }
                if (i == 1 && j == 1)
                {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = min(c2[j - 1], c1[j]);
            }
        for (ll i = n; i >= 1; i--)
            for (ll j = m; j >= 1; j--)
            {
                v<ll> c1(m + 2, INF), c2(m + 2, INF);
                for (ll k = n; k >= i; k--)
                {
                    for (ll l = m; l >= 1; l--)
                    {
                        if (k == i && l == j)
                            continue;
                        ll val = a[i][j] + (n - i + m - j) - (n - k + m - l);
                        c2[l] = comp(k, l, c2[l + 1], c1[l], a[k][l], val, n, m);
                    }
                    if (k != i)
                        c1 = c2;
                }
                if (i == n && j == m)
                {
                    dp1[i][j] = 0;
                    continue;
                }
                dp1[i][j] = min(c2[j + 1], c1[j]);
            }
        ll ans = INT64_MAX;
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= m; j++)
            {
                // cout << dp[i][j] << " ";
                if (dp[i][j] != INF && dp1[i][j] != INF)
                    ans = min(ans, dp[i][j] + dp1[i][j]);
            }
            // cout << "\n";
        }
        // for (ll i = 1; i <= n; i++)
        // {
        //     for (ll j = 1; j <= m; j++)
        //         cout << dp1[i][j] << " ";
        //     cout << "\n";
        // }
        cout << ans << "\n";
    }
}