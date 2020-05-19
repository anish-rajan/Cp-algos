#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n + 1), cum(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    cum[0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        cum[i] = cum[i - 1] ^ arr[i];
        // cout << cum[i] << " ";
    }
    vector<pair<ll, ll>> ind(1050000);
    for (ll i = 0; i < 1050000; i++)
    {
        ind[i].first = -1;
        ind[i].second = -1;
    }
    vector<ll> dp(n + 1);
    dp[0] = 0;
    ind[0].first = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            if (ind[cum[i]].first == -1)
            {
                ind[cum[i]].first = i;
                dp[i] = 0;
            }
            else
            {
                dp[i] = dp[ind[cum[i]].first] + 1;
                ind[cum[i]].first = i;
            }
        }
        else
        {
            if (ind[cum[i]].second == -1)
            {
                ind[cum[i]].second = i;
                dp[i] = 0;
            }
            else
            {
                dp[i] = dp[ind[cum[i]].second] + 1;
                ind[cum[i]].second = i;
            }
        }
        // cout << dp[i] << " " << ind[cum[i]].first << " " << ind[cum[i]].second << "\n";
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        ans += dp[i];
    }
    cout << ans << "\n";
}