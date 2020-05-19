#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// typedef long long int int;
#define N 5202
vector<vector<int>> arr(N, vector<int>(N));
vector<vector<int>> dp(N, vector<int>(N));
int main()
{
    int n;
    cin >> n;
    string input;
    for (int i = 1; i <= n; i++)
    {
        cin >> input;
        int temp = 0;
        int j = 1;
        for (int j = 0; j < n / 4; j++)
        {
            int no;
            if (input[j] >= 48 && input[j] <= 57)
            {
                no = input[j] - '0';
            }
            else
                no = (input[j] - 'A') + 10;
            int temp1 = 4;
            while (temp1 > 0)
            {
                arr[i][temp + temp1] = no % 2;
                temp1--;
                no /= 2;
            }
            temp += 4;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + arr[i][j];
            // cout << arr[i][j] << " ";
        }
        // cout << endl;
    }
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            int f = 0;
            for (int j = i; j <= n; j += i)
            {
                for (int k = i; k <= n; k += i)
                {
                    int temp = dp[j][k] - dp[j - i][k] - dp[j][k - i] + dp[j - i][k - i];
                    if (temp != 0 && temp != i * i)
                    {
                        f = 1;
                    }
                }
            }
            if (f == 0)
                ans = max(ans, i);
        }
    }
    cout << ans << "\n";
}
