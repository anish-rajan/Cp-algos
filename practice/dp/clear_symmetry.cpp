#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    vector<ll> dp(101);
    dp[1] = 1;
    dp[2] = 0;
    ll add = 4;
    for (ll i = 3; i <= 100; i++)
    {
        if (i % 2 == 0)
        {
            ll temp = i / 2;
            if (temp % 2 != 0)
            {
                temp /= 2;
                temp *= 2;
                temp *= temp;
                temp *= 2;
            }
            else
            {
                temp /= 2;
                ll temp1 = temp - 1;
                temp *= 2;
                temp *= temp;
                temp1 *= 2;
                temp1 *= temp1;
                temp += temp1;
            }
            dp[i] = temp;
        }
        else
        {
            dp[i] = dp[i - 2] + add;
            add += 4;
        }
        // cout << dp[i] << " ";
    }
    ll x;
    cin >> x;
    ll ans = INT64_MAX;
    for (ll i = 100; i >= 1; i--)
    {
        if (dp[i] >= x && i % 2 == 1)
        {
            if (i == 3)
            {
                if (x != 3)
                {
                    ans = min(ans, i);
                }
            }
            else
                ans = min(ans, i);
        }
        else
        {
            if (x % 4 == 0 && dp[i] >= x)
            {
                ans = min(ans, i);
            }
        }
    }
    cout << ans << "\n";
}