#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 100005
vector<ll> arr(N), dp(N);
int main()
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    dp[1] = 1;
    for (ll i = 2; i <= n; i++)
    {
        dp[i] = i;
        dp[i] = min(dp[i - 1] + 1, dp[i]);
        dp[i] = min(dp[i], arr[i]);
    }
    dp[n] = 1;
    for (ll i = n - 1; i >= 1; i--)
    {
        dp[i] = min(dp[i + 1] + 1, dp[i]);
        dp[i] = min(dp[i], n - i + 1);
    }
    ll ans = -1;
    for (ll i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
}