#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 2003
vector<ll> arr(N), cnt1(N), cnt2(N);
vector<vector<ll>> dp(N, vector<ll>(3)), dp1(N, vector<ll>(3));
int main()
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        cnt1[i] = arr[i] == 1 ? cnt1[i - 1] + 1 : cnt1[i - 1];
        cnt2[i] = arr[i] == 2 ? cnt2[i - 1] + 1 : cnt2[i - 1];
        // cout << cnt1[i] << " " << cnt2[i] << "\n";
    }
    for (ll i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][0] + arr[i] == 1;
        if (arr[i] == 2)
        {
            dp[i][1] = dp[i - 1][1] + 1;
            dp[i][1] = max(dp[i][1], dp[i - 1][0] + 1);
        }
        else
            dp[i][1] = dp[i - 1][1];
    }
    dp1[n][0] = arr[n] == 1 ? 1 : 0;
    dp1[n][1] = arr[n] == 2 ? 1 : 0;
    for (ll i = n; i >= 1; i--)
    {
        dp1[i][1] = dp1[i + 1][1] + arr[i] == 2;
        if (arr[i] == 1)
        {
            dp1[i][0] = dp1[i + 1][0] + 1;
            dp1[i][0] = max(dp1[i][0], dp1[i + 1][1] + 1);
        }
        else
            dp1[i][0] = dp1[i + 1][0];
    }
    ll ans = max(dp[n][0], dp[n][1]);
    for (ll i = 1; i <= n; i++)
    {
        ll a1 = 1;
        for (ll j = i + 1; j <= n; j++)
        {
            if (arr[j] == 1)
            {
                a1 += 1;
            }
            else
            {
                a1 = max(a1, cnt2[j] - cnt2[i - 1]);
            }
            if (j != n)
                ans = max(ans, cnt1[j] + max(dp1[j + 1][0], dp1[j + 1][1]));
            else
                ans = max(ans, cnt1[j]);
            ans = max(ans, cnt1[i - 1] + a1 + cnt2[n] - cnt2[j]);
            ans = max(ans, max(dp[i - 1][0], dp[i - 1][1]) + cnt2[n] - cnt2[i - 1]);
            // cout << i << " " << j << " " << a1 << " " << ans << "\n";
        }
    }
    cout << ans << "\n";
}