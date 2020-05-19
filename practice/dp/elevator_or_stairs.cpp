#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 200005
vector<ll> arr(N), b(N);
vector<vector<ll>> dp(N, vector<ll>(2));
int main()
{
    ll n, c;
    cin >> n >> c;
    for (ll i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }
    for (ll i = 0; i < n - 1; i++)
    {
        cin >> b[i];
    }
    dp[0][0] = arr[0], dp[0][1] = b[0] + c;
    for (ll i = 1; i < n - 1; i++)
    {
        dp[i][0] = min(dp[i - 1][0] + arr[i], dp[i - 1][1] + arr[i]);
        if (dp[i - 1][0] + c < dp[i - 1][1])
        {
            dp[i][1] = dp[i - 1][0] + c + b[i];
        }
        else
        {
            dp[i][1] = dp[i - 1][1] + b[i];
        }
    }
    cout << 0 << " ";
    for (ll i = 0; i < n - 1; i++)
    {
        cout << min(dp[i][0], dp[i][1]) << " ";
    }
    cout << "\n";
}