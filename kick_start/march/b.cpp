#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double ld;
#define N 55
ll t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        ll ans = 0, n, k, p;
        vector<vector<ll>> plates(N, vector<ll>(N)), dp(N, vector<ll>(1505)), cum(N, vector<ll>(N));
        cin >> n >> k >> p;
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= k; j++)
            {
                cin >> plates[i][j];
            }
        }
        for (ll i = 1; i <= n; i++)
        {
            cum[i][0] = 0;
            for (ll j = 1; j <= k; j++)
            {
                cum[i][j] = cum[i][j - 1] + plates[i][j];
            }
        }
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= p; j++)
            {
                dp[i][j] = 0;
                for (ll s = 0; s <= min(k, j); s++)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - s] + cum[i][s]);
                }
            }
        }
        ans = dp[n][p];
        cout << "Case #" << i << ": " << ans << "\n";
    }
}