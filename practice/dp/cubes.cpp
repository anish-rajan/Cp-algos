#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> arr(200005), dp(200005), dp1(200005);
vector<ll> ans(100005), start(100005), curr(100005);
int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    fill(ans.begin(), ans.end(), -1);
    for (ll i = n - 1; i >= 0; i--)
    {
        if (ans[arr[i]] == -1)
        {
            dp[i] = i;
            ans[arr[i]] = i;
        }
        else
        {
            dp[i] = ans[arr[i]];
            ans[arr[i]] = i;
        }
    }
    fill(ans.begin(), ans.end(), -1);
    for (ll i = 0; i < n; i++)
    {
        if (ans[arr[i]] == -1)
        {
            dp1[i] = i;
            ans[arr[i]] = i;
        }
        else
        {
            dp1[i] = ans[arr[i]];
            ans[arr[i]] = i;
        }
    }
    fill(ans.begin(), ans.end(), -1);
    for (ll i = 0; i < n; i++)
    {
        if (ans[arr[i]] == -1)
        {
            ans[arr[i]] = 1;
            curr[arr[i]] = 1;
            start[arr[i]] = i;
        }
        else
        {
            ll temp = i - dp1[i] - 1;
            ll temp1 = curr[arr[i]];
            for (ll j = start[arr[i]];; j = start[arr[i]])
            {
                if (k < i - start[arr[i]] - temp1)
                {
                    start[arr[i]] = dp[start[arr[i]]];
                    temp1--;
                }
                else
                {
                    ans[arr[i]] = max(ans[arr[i]], temp1 + 1);
                    curr[arr[i]] = temp1 + 1;
                    break;
                }
            }
        }
        // cout << curr[arr[i]] << " " << dp[i] << " " << dp1[i] << " " << start[arr[i]] << "\n";
    }
    ll ans1 = 1;
    for (ll i = 1; i <= m; i++)
    {
        ans1 = max(ans1, ans[i]);
    }
    cout << ans1 << "\n";
}