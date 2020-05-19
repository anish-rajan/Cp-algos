#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// typedef long long int ll;
#define N 5005
#define mod 1000000007
vector<char> arr(N);
vector<vector<int>> dp(N, vector<int>(N)), cum(N, vector<int>(N));
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    dp[1][0] = 1;
    cum[1][0] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (arr[i - 1] == 'f')
            {
                if (j == 0)
                {
                    dp[i][0] = 0;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
            else
            {
                dp[i][j] = cum[i - 1][j];
            }
            // cout << dp[i][j] << " ";
        }
        cum[i][n] = dp[i][n];
        for (int j = n - 1; j >= 0; j--)
        {
            cum[i][j] = (cum[i][j + 1] + dp[i][j]) % mod;
        }
        // cout << endl;
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans = (ans + dp[n][i]) % mod;
    }
    cout << ans << "\n";
}