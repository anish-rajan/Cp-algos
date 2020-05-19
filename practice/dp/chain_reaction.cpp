#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        cin >> arr[i].second;
    }
    sort(arr.begin(), arr.end());
    vector<ll> dp(n);
    dp[0] = 0;
    for (ll i = 1; i < n; i++)
    {
        pair<ll, ll> p(arr[i].first - arr[i].second, 0);
        ll ind = lower_bound(arr.begin(), arr.end(), p) - arr.begin();
        // cout << ind;
        if (ind == i)
        {
            dp[i] = dp[i - 1];
        }
        else if (ind == 0)
        {
            dp[i] = i;
        }
        else
        {
            dp[i] = i - ind + dp[ind - 1];
        }
        // cout << dp[i] << " ";
    }
    ll ans = INT64_MAX;
    for (ll i = 0; i < n; i++)
    {
        ans = min(ans, dp[n - i - 1] + i);
    }
    cout << ans << "\n";
}
