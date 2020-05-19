#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 998244353
vector<vector<ll>> dp(1001, vector<ll>(2002));
vector<vector<pair<ll, ll>>> dp1(1001, vector<pair<ll, ll>>(2002));
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    dp[1][1] = 2;
    dp[1][2] = 2;
    dp1[1][1].first = 0;
    dp1[1][1].second = 2;
    dp1[1][2].first = 2;
    dp1[1][2].second = 0;
    for (ll i = 2; i <= 1000; i++)
    {
        dp[i][1] = 2;
        dp1[i][1].first = 0;
        dp1[i][1].second = 2;
        for (ll j = 2; j <= 2 * i; j++)
        {
            dp[i][j] = (dp1[i - 1][j].first * 3 + dp1[i - 1][j].second + dp1[i - 1][j - 1].second * 3 + dp1[i - 1][j - 2].first) % mod;
            dp1[i][j].first = (dp1[i - 1][j - 2].first + dp1[i - 1][j].first + dp1[i - 1][j - 1].second * 2) % mod;
            dp1[i][j].second = (dp[i][j] - dp1[i][j].first) % mod;
            if (dp1[i][j].second < 0)
                dp1[i][j].second += mod;
        }
    }
    cin >> n >> k;
    cout << dp[n][k] << "\n";
}