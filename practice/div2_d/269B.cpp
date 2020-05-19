#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// typedef long long int int;
#define N 5005
vector<vector<int>> dp(N, vector<int>(N));
vector<int> arr(N), smaller(N);
vector<int> visited(N);
vector<double> co(N);
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i] >> co[i];
    }
    int maxelement = -1;
    for (int i = 1; i <= n; i++)
    {
        visited[arr[i]]++;
        maxelement = max(maxelement, arr[i]);
        for (int j = arr[i] + 1; j <= m; j++)
        {
            smaller[j] = visited[j];
        }
        for (int j = 1; j <= m; j++)
        {
            if (arr[i] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else if (arr[i] < j)
            {
                dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + smaller[j]);
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1] + smaller[j]);
            }
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[n][m] << "\n";
}