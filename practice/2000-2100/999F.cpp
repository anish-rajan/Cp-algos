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
#define N 505
#define N1 12
#define N2 100005
#define mod 1000000007
#define INF INT_MAX

ll n, k;
v<ll> c(N *N1), f(N), h(N1), c1(N2);
v<ll> p(N2);

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (ll i = 1; i <= k * n; i++)
        cin >> c[i], c1[c[i]]++;
    for (ll i = 1; i <= n; i++)
        cin >> f[i], p[f[i]]++;
    for (ll i = 1; i <= k; i++)
        cin >> h[i];
    ll ans = 0;
    for (ll i = 1; i <= 1e5; i++)
    {
        ll no = p[i], no1 = c1[i];
        // if (i <= 6)
        //     cout << p[i] << " " << c1[i] << " ";
        v<v<ll>> dp(no + 2, v<ll>(no1 + 2, 0));
        for (ll i = 1; i <= no; i++)
        {
            for (ll j = 1; j <= no1; j++)
            {
                for (ll l = 1; l <= k; l++)
                {
                    if (j - l >= 0)
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - l] + h[l]);
                    // cout << dp[i][j] << " ";
                }
            }
        }
        ll ans1 = 0;
        for (ll i = 1; i <= no1; i++)
            ans1 = max(ans1, dp[no][i]);
        ans += ans1;
        // if (i <= 6)
        //     cout << ans1 << "\n";
    }
    cout << ans << "\n";
}