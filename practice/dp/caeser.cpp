#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<vector<vector<vector<ll>>>> dp(105, vector<vector<vector<ll>>>(105, vector<vector<ll>>(15, vector<ll>(15))));
vector<vector<vector<vector<ll>>>> h(105, vector<vector<vector<ll>>>(105, vector<vector<ll>>(15, vector<ll>(15))));
vector<vector<vector<vector<ll>>>> f(105, vector<vector<vector<ll>>>(105, vector<vector<ll>>(15, vector<ll>(15))));
#define mod 100000000

ll solve(ll n, ll m)
{
    // cout << "a";
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
    for (ll i = 0; i <= m; i++)
    {
        dp[0][i] = 1;
    }
    for (ll i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }
    return dp[n][m];
}

int main()
{
    ll n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    ll ans;
    for (ll i = 0; i <= n1; i++)
    {
        for (ll j = 0; j <= n2; j++)
        {
            for (ll k = 0; k <= k1; k++)
            {
                for (ll l = 0; l <= k2; l++)
                {
                    ll ans = 0;
                    if (i != 0 && j != 0 && k < k1 && l < k2)
                        ans = (dp[i - 1][j][k + 1][k2] + dp[i][j - 1][k1][l + 1]) % mod;
                    else if (i != 0 && j != 0)
                    {
                        if (k < k1)
                        {
                            ans = (ans + dp[i - 1][j][k + 1][k2]) % mod;
                        }
                        else
                        {
                            for (ll m = 0; m <= k2; m++)
                            {
                                ans = (ans + dp[i - 1][j][k1][m]) % mod;
                            }
                        }
                        if (l < k2)
                        {
                            ans = (ans + dp[i][j - 1][k1][l + 1]) % mod;
                        }
                        else
                        {
                            for (ll m = 0; m <= k1; m++)
                            {
                                ans = (ans + dp[i][j - 1][m][k2]) % mod;
                            }
                        }
                    }
                    else
                        ans = 1;
                    dp[i][j][k][l] = ans;
                }
            }
        }
    }
    cout << dp[n1][n2][k1][k2] << "\n";
}