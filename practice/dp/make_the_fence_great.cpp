#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> q;
    while (q--)
    {
        ll n;
        cin >> n;
        vector<pair<ll, ll>> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i].first;
            cin >> arr[i].second;
        }
        vector<vector<ll>> dp(n, vector<ll>(3));
        dp[0][0] = 0, dp[0][1] = 1 * arr[0].second, dp[0][2] = 2 * arr[0].second;
        for (ll i = 1; i < n; i++)
        {
            for (ll j = 0; j < 3; j++)
            {
                dp[i][j] = INT64_MAX;
                for (ll k = 0; k < 3; k++)
                {
                    if (j + arr[i].first != k + arr[i - 1].first)
                    {
                        ll temp = j * arr[i].second;
                        temp += dp[i - 1][k];
                        dp[i][j] = min(dp[i][j], temp);
                    }
                }
            }
        }
        ll ans = INT64_MAX;
        ans = min(ans, dp[n - 1][0]);
        ans = min(ans, dp[n - 1][1]);
        ans = min(ans, dp[n - 1][2]);
        // cout << dp[n - 1][0] << " " << dp[n - 1][1] << " " << dp[n - 1][2] << "\n";
        cout << ans << "\n";
    }
}