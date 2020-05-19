#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 100005
typedef long long int ll;
vector<vector<ll>> dp(N, vector<ll>(5));
vector<ll> arr(N);
int main()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    s = "a" + s;
    string t = "@hard";
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= 4; j++)
            dp[i][j] = INT64_MAX;
    }
    dp[0][0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= 4; j++)
        {
            if (s[i] != t[j])
            {
                if (i > 1)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = 0;
            }
            else
            {
                if (i > 1 && j > 1)
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j] + arr[i]);
                else if (i > 1)
                    dp[i][j] = dp[i - 1][j] + arr[i];
                else if (j > 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = arr[i];
            }
        }
        // cout << dp[i][1] << " " << dp[i][2] << " " << dp[i][3] << " " << dp[i][4] << "\n";
    }
    ll ans = INT64_MAX;
    for (ll i = 1; i <= 4; i++)
    {
        ans = min(ans, dp[n][i]);
    }
    cout << ans << "\n";
}