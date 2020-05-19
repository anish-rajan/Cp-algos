#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double ld;
#define N 104
vector<vector<ll>> dp(N, vector<ll>(N)), cum(N, vector<ll>(N));
ll n, h;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> h;
    dp[0][0] = 1;
    cum[0][0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        dp[0][i] = 0;
        cum[0][i] = cum[0][i - 1] + dp[0][i];
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j <= n; j++)
        {
            cum[i][0] = 0;
            if (j <= i && j >= 1)
            {
                dp[i][j] = 0;
                for (ll k = 0; k <= i - 1; k++)
                {
                    if (j - 2 >= 0)
                        dp[i][j] += cum[k][j - 2] * dp[i - k - 1][j - 1] + cum[i - k - 1][j - 2] * dp[k][j - 1] + dp[k][j - 1] * dp[i - k - 1][j - 1];
                    else
                        dp[i][j] += dp[k][j - 1] * dp[i - k - 1][j - 1];
                }
            }
            else
                dp[i][j] = 0;
            if (j > 0)
                cum[i][j] = cum[i][j - 1] + dp[i][j];
            // cout << cum[i][j] << " ";
        }
        // cout << endl;
    }
    ll ans;
    if (h != 0)
        ans = cum[n][n] - cum[n][h - 1];
    else
    {
        ans = cum[n][n];
    }
    cout << ans << "\n";
}