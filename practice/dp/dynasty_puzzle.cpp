#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 100
vector<vector<ll>> dp(N, vector<ll>(N));
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<string> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (ll i = 0; i < n; i++)
    {
        string s = arr[i];
        ll t = s.size();
        char st = s[0];
        char en = s[t - 1];
        for (ll i = 0; i < 26; i++)
        {
            if (dp[i][st - 97])
                dp[i][en - 97] = max(dp[i][en - 97], dp[i][st - 97] + t);
        }
        dp[st - 97][en - 97] = max(dp[st - 97][en - 97], t);
    }
    ll ans = 0;
    for (ll i = 0; i < 26; i++)
    {
        ans = max(ans, dp[i][i]);
    }
    cout << ans << "\n";
}