#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 1003
vector<ll> count1(N);
vector<pair<ll, ll>> dp(N);
vector<vector<char>> arr(N, vector<char>(N));
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    for (ll i = 1; i <= n; i++)
    {

        for (ll j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
        // cout << count1[i] << "\n";
    }
    count1[0] = 0;
    for (ll i = 1; i <= m; i++)
    {
        ll c = 0;
        for (ll j = 1; j <= n; j++)
        {
            if (arr[j][i] == '#')
                c++;
        }
        count1[i] = c;
    }
    dp[0].first = 0;
    dp[0].second = 0;
    for (ll i = 1; i <= m; i++)
    {
        ll c = 0;
        dp[i].first = 1000006;
        dp[i].second = 1000006;
        // dp[i].first = dp[i - 1].first + n - count1[i];
        // dp[i].second = dp[i - 1].second + count1[i];
        if (i <= x)
        {
            dp[i].first = dp[i - 1].first + n - count1[i];
            dp[i].second = dp[i - 1].second + count1[i];
        }
        else
        {
            for (ll j = 0; j < x; j++)
            {
                c += count1[i - j];
            }
            for (ll j = x; j <= y; j++)
            {
                if (i - j == 0 || i - j >= x)
                {
                    dp[i].first = min(dp[i].first, n * (j)-c + dp[i - j].second);
                    dp[i].second = min(dp[i].second, c + dp[i - j].first);
                    // cout << i - j << " " << c << "\n";
                }
                c += count1[i - j];
            }
        }
        // cout << dp[i].first << " " << dp[i].second << "\n";
    }
    cout << min(dp[m].first, dp[m].second) << "\n";
}