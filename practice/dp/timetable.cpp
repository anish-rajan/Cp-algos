#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 505
vector<string> arr(N);
vector<vector<int>> dp(N, vector<int>(N)), mem(N, vector<int>(N));
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '1')
                temp.push_back(j);
        }
        int r = temp.size() - 1;
        if (r >= 0)
            mem[i][0] = temp[r] - temp[0] + 1;
        else
            mem[i][0] = 0;
        for (int j = 1; j <= k; j++)
        {
            if (j > r)
            {
                mem[i][j] = 0;
            }
            else
            {
                mem[i][j] = temp[r] - temp[j] + 1;
                for (int s = 0; s < j; s++)
                {
                    mem[i][j] = min(mem[i][j], temp[r - j + s] - temp[s] + 1);
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (i >= 1)
                dp[i][j] = dp[i - 1][j] + mem[i][0];
            else
                dp[i][j] = mem[i][0];
        }
        for (int j = 0; j <= k; j++)
        {
            for (int s = 0; s + j <= k; s++)
            {
                if (i >= 1)
                    dp[i][s + j] = min(dp[i - 1][j] + mem[i][s], dp[i][s + j]);
                else
                    dp[i][s + j] = min(mem[i][s], dp[i][s + j]);
            }
        }
    }
    cout << dp[n - 1][k] << "\n";
}