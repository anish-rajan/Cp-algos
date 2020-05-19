#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 5005
vector<string> arr(N);
vector<vector<ll>> dp(N, vector<ll>(N));
vector<vector<ll>> dp1(N, vector<ll>(N));
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        dp1[i][m] = arr[i - 1][m - 1] == '1' ? 1 : 0;
        for (ll j = m - 1; j >= 1; j--)
        {
            dp1[i][j] = arr[i - 1][j - 1] == '1' ? (dp1[i][j + 1] + 1) : 0;
        }
    }
    // for (ll i = 1; i <= n; i++)
    // {
    //     for (ll j = 1; j <= m; j++)
    //         cout << dp1[i][j] << " ";
    //     cout << "\n";
    // }
    for (ll j = 1; j <= m; j++)
    {
        for (ll i = 1; i <= n; i++)
        {
            dp[j][dp1[i][j]]++;
        }
        for (ll i = m - 1; i >= 0; i--)
        {
            dp[j][i] += dp[j][i + 1];
        }
    }
    // for (ll i = 1; i <= n; i++)
    // {
    //     for (ll j = 1; j <= m; j++)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    ll area = 0;
    for (ll i = 1; i <= m; i++)
    {
        for (ll j = i; j <= m; j++)
        {
            area = max(area, (j - i + 1) * (dp[i][j - i + 1]));
        }
    }
    cout << area << "\n";
}