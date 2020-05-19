#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 2002
#define mod 998244353
ll n, m, k;
vector<vector<ll>> dp(N, vector<ll>(N));

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j <= k; j++)
        {
            if (j == 0)
            {
                dp[i][j] = m;
            }
            else if (i == 1)
                dp[i][j] = 0;
            else
                dp[i][j] = (dp[i - 1][j] + (dp[i - 1][j - 1] * (m - 1)) % mod) % mod;
        }
    }
    cout << dp[n][k] << endl;
}