#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define N 1003
vector<ll> dp(N), arr(N);
int main()
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    dp[1] = 2;
    for (ll i = 2; i <= n; i++)
    {
        for (ll j = arr[i]; j < i; j++)
        {
            dp[i] = (dp[i] + dp[j]) % mod;
        }
        dp[i] = (dp[i] + 2) % mod;
        // cout << dp[i] << " ";
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        ans = (ans + dp[i]) % mod;
    }
    cout << ans << "\n";
}