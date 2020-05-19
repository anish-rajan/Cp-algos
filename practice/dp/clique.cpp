#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 1000006
vector<ll> arr(N), exists(N), dp(N);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        dp[arr[i]] = 1;
        exists[arr[i]]++;
    }
    ll ans = 1;
    for (ll i = 0; i < n; i++)
    {
        ll num = arr[i];
        for (ll j = num; j <= 1000000; j += num)
        {
            if (exists[j] && num != j)
            {
                dp[j] = max(dp[j], dp[num] + 1);
                ans = max(ans, dp[j]);
            }
        }
    }
    cout << ans << "\n";
}
