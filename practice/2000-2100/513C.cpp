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
#define N 6
#define mod 1000000007
#define INF INT_MAX

ll n;
v<pair<ll, ll>> intes(N);

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
    cin >> n;
    ll minl = 1e6, maxr = -1;
    for (ll i = 1; i <= n; i++)
    {
        cin >> intes[i].fi >> intes[i].se;
        minl = min(minl, intes[i].fi);
        maxr = max(maxr, intes[i].se);
    }
    ld ans = 0;

    for (ll i = minl; i <= maxr; i++)
    {
        v<v<ld>> dp(N, v<ld>(N, 0));
        dp[0][0] = 1;
        for (ll j = 1; j <= n; j++)
        {
            ld l = intes[j].fi, r = intes[j].se;
            v<v<ld>> dp1(N, v<ld>(N));
            for (ll k = 0; k < 3; k++)
            {
                if (i >= l && i <= r)
                {
                    //equal
                    dp1[0][min(k + 1, (ll)2)] += dp[0][k] / (r - l + 1);
                    dp1[1][min(k + 1, (ll)2)] += dp[1][k] / (r - l + 1);
                    //greater
                    dp1[1][k] += dp[0][k] * (r - i) / (r - l + 1);
                    //smaller
                    dp1[1][k] += dp[1][k] * (i - l) / (r - l + 1);
                    dp1[0][k] += dp[0][k] * (i - l) / (r - l + 1);
                }
                else if (i < l)
                {
                    dp1[1][k] += dp[0][k];
                }
                else if (i > r)
                {
                    dp1[0][k] += dp[0][k];
                    dp1[1][k] += dp[1][k];
                }
                // if (i == 3)
                // {
                //     cout << k << " " << dp1[0][k] << " " << dp1[1][k] << "\n";
                // }
            }
            dp = dp1;
        }
        ld ans1 = 0;
        ans1 += dp[1][1] + dp[0][2] + dp[1][2];
        ans += ans1 * i;
        // if (i == 3)
        //     cout << ans1 << "\n";
    }
    printf("%0.11Lf\n", ans);
}