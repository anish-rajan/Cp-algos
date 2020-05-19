#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int dp[n + 1];
    dp[0] = 0;
    int restaftergym = 0, restaftercontest = 0; // indicates whether person is currently resting.
    // dp[i] represents the maximum working days upto first i days.
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 3)
        {
            dp[i] = dp[i - 1] + 1;
            if (i > 1)
            {
                if (a[i - 1] == 2)
                {
                    restaftergym = 0;
                    restaftercontest = 1;
                }
                else if (a[i - 1] == 1)
                {
                    restaftercontest = 0;
                    restaftergym = 1;
                }
                else if (a[i - 1] == 0)
                {
                    restaftercontest = 0;
                    restaftergym = 0;
                }
                else
                {
                    restaftercontest = restaftercontest == 0 ? 1 : 0;
                    restaftergym = restaftergym == 0 ? 1 : 0;
                }
            }
        }
        else if (a[i] == 0)
        {
            dp[i] = dp[i - 1];
            restaftergym = 0;
            restaftercontest = 0;
        }
        else if (a[i] == 1)
        {
            if (restaftercontest == 1)
            {
                dp[i] = dp[i - 1];
                restaftercontest = 0;
            }
            else
            {
                dp[i] = dp[i - 1] + 1;
                restaftercontest = 1;
            }
            restaftergym = 0;
        }
        else
        {
            if (restaftergym == 1)
            {
                dp[i] = dp[i - 1];
                restaftergym = 0;
            }
            else
            {
                dp[i] = dp[i - 1] + 1;
                restaftergym = 1;
            }
            restaftercontest = 0;
        }
        //cout << dp[i] << " ";
    }
    int answer = n - dp[n];
    cout << endl
         << answer << endl;
    return 0;
}