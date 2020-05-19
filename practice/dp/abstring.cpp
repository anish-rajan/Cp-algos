#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 300005
vector<ll> dp(N), dp1(N), dp2(N), dp3(N);
int main()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    dp[0] = s[0] == 'A' ? 1 : 0;
    dp1[0] = s[0] == 'B' ? 1 : 0;
    for (ll i = 1; i < n; i++)
    {
        dp[i] = s[i] == 'A' ? dp[i - 1] + 1 : 0;
        dp1[i] = s[i] == 'B' ? dp1[i - 1] + 1 : 0;
    }
    dp2[n - 1] = s[n - 1] == 'A' ? 1 : 0;
    dp3[n - 1] = s[n - 1] == 'B' ? 1 : 0;
    for (ll i = n - 2; i >= 0; i--)
    {
        dp2[i] = s[i] == 'A' ? dp2[i + 1] + 1 : 0;
        dp3[i] = s[i] == 'B' ? dp3[i + 1] + 1 : 0;
    }
    ll ans = n * (n - 1) / 2;
    for (ll i = 0; i < n - 1; i++)
    {
        if (s[i] == 'A' && s[i + 1] == 'B')
        {
            ans -= dp[i];
            ans -= dp3[i + 1] - 1;
        }
        else if (s[i] == 'B' && s[i + 1] == 'A')
        {
            ans -= dp1[i];
            ans -= dp2[i + 1] - 1;
        }
        // cout << dp[i] << " " << dp1[i] << " " << dp2[i] << " " << dp3[i] << " " << ans << "\n";
    }
    cout << ans << "\n";
}