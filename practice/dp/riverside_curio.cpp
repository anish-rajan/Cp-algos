#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 100005
vector<ll> arr(N);
vector<pair<ll, ll>> dp(N);
int main()
{
    ll n;
    cin >> n;
    ll maxlevels = 1;
    ll ind = 0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    dp[n].first = 0, dp[n].second = n + 1;
    maxlevels = arr[n] + 1;
    ind = n;
    for (ll i = n - 1; i >= 1; i--)
    {
        if (arr[i] + 1 >= maxlevels - (ind - i))
        {
            maxlevels = arr[i] + 1;
            ind = i;
        }
        dp[i].first = maxlevels;
        dp[i].second = ind;
        // cout << dp[i].first << " " << dp[i].second << "\n";
    }
    ll levels = 1;
    ll sum = 0;
    for (ll i = 2; i <= n; i++)
    {
        if (arr[i] == levels)
            levels++;
        else if (arr[i] < levels)
        {
            if (dp[i].first - levels <= dp[i].second - i)
            {
                sum += levels - arr[i] - 1;
            }
            else
            {
                sum += levels - arr[i];
                levels++;
            }
        }
        // cout << levels << " ";
    }
    // cout << endl;
    cout << sum << "\n";
}