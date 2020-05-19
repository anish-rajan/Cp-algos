#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 100005
ll n;
vector<ll> arr(N), dp(N);
stack<pair<ll, ll>> maxes;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    dp[0] = 0;
    ll ans = 0;
    maxes.push(make_pair(arr[0], dp[0]));
    for (ll i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            dp[i] = 1;
        }
        else
        {
            dp[i] = 0;
            while (!maxes.empty())
            {
                if (arr[i] > maxes.top().first)
                {
                    dp[i] = max(dp[i], maxes.top().second + 1);
                    maxes.pop();
                }
                else
                    break;
            }
        }
        if (maxes.empty())
            dp[i] = 0;
        maxes.push(make_pair(arr[i], dp[i]));
        ans = max(ans, dp[i]);
        // cout << dp[i] << " ";
    }
    cout << ans << "\n";
}