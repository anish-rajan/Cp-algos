#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n, p, q, r;
    cin >> n >> p >> q >> r;
    vector<ll> arr(n);
    vector<pair<ll, ll>> dp(n);
    vector<pair<ll, ll>> dp1(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    dp[0].first = arr[0];
    dp[0].second = arr[0];
    dp1[n - 1].first = arr[n - 1];
    dp1[n - 1].second = arr[n - 1];
    // cout << dp[0].first << " " << dp1[0].first << " " << dp[0].second << " " << dp1[0].second << "\n";
    for (ll i = 1; i < n; i++)
    {
        dp[i].first = min(dp[i - 1].first, arr[i]);
        dp[i].second = max(dp[i - 1].second, arr[i]);
        // cout << dp[i].first << " " << dp1[i].first << " " << dp[i].second << " " << dp1[i].second << "\n";
    }
    for (ll i = n - 2; i >= 0; i--)
    {
        dp1[i].first = min(dp1[i + 1].first, arr[i]);
        dp1[i].second = max(dp1[i + 1].second, arr[i]);
        // cout << dp[i].first << " " << dp1[i].first << " " << dp[i].second << " " << dp1[i].second << "\n";
    }
    ll ans = INT64_MIN;
    for (ll i = 0; i < n; i++)
    {
        ll temp = q * arr[i];
        ll temp1;
        if (p > 0)
        {
            temp1 = p * dp[i].second;
            if (r > 0)
            {
                temp1 += r * dp1[i].second;
            }
            else
            {
                temp1 += r * dp1[i].first;
            }
        }
        else
        {
            temp1 = p * dp[i].first;
            if (r > 0)
            {
                temp1 += r * dp1[i].second;
            }
            else
            {
                temp1 += r * dp1[i].first;
            }
        }
        ans = max(ans, temp + temp1);
    }
    cout << ans << "\n";
}