#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 1005
vector<ll> a(N), b(N), c(N), d(N);
vector<vector<ll>> dp(N, vector<ll>(15));
int main()
{
    ll n, m, c0, d0;
    cin >> n >> m >> c0 >> d0;
    for (ll i = 1; i <= m; i++)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    dp[0][0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        dp[i][0] = (i / c0) * d0;
    }
    for (ll i = 1; i <= m; i++)
    {
        for (ll j = 0; j <= n; j++)
        {
            dp[j][i] = 0;
            for (ll k = 0; k <= j; k++)
            {
                ll temp = j - k;
                ll temp1 = a[i] / b[i];
                ll temp2 = temp / c[i];
                ll temp3 = min(temp1, temp2);
                ll temp4 = temp3 * d[i] + dp[k][i - 1];
                // if (i == 1 && j == 6)
                //     cout << dp[k][i - 1] << "\n";
                dp[j][i] = max(dp[j][i], temp4);
            }
        }
    }
    // for (ll i = 0; i <= n; i++)
    // {
    //     for (ll j = 0; j <= m; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << dp[n][m];
}