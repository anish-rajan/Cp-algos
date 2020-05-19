#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 200005
#define mod 1000000007
ll r, g, h;
vector<ll> dp(N);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r >> g;
    h = sqrt(2 * (r + g));
    if (((h + 1) * (h + 2)) / 2 <= r + g)
    {
        h++;
    }
    if ((h * (h + 1)) / 2 > r + g)
        h--;
    // cout << h;
    for (ll j = r; j >= 0; j--)
        dp[j] = 1;
    for (ll i = 1; i <= h; i++)
    {
        for (ll j = r; j >= 0; j--)
        {
            ll k = (((i * (i + 1)) / 2) - j);
            if (k <= g)
            {
                if (j - i >= 0 && k - i >= 0)
                {
                    dp[j] = (dp[j - i] + dp[j]) % mod;
                }
                else if (j - i >= 0 && k >= 0)
                    dp[j] = dp[j - i];
                else if (k - i >= 0)
                    dp[j] = dp[j];
                else
                    dp[j] = 0;
            }
            else
                dp[j] = 0;
            // cout << dp[j] << " ";
        }
        // cout << endl;
    }
    ll ans = 0;
    for (ll i = 0; i <= r; i++)
    {
        ans = (ans + dp[i]) % mod;
    }
    cout << ans << "\n";
}