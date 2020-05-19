#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 3003
#define mod 998244353
string s, t;
ll n, m;
v<v<ll>> dp(N, v<ll>(N));
ll powmod(ll x, ll y, ll p)
{
    ll res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
               // equal to p

    if (x == 0)
        return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s >> t;
    n = s.size(), m = t.size();
    for (ll i = m; i <= n; i++)
    {
        if (i > m)
            dp[i][0] = 1;
        else if (t[m - 1] == s[i - 1])
            dp[i][0] = 1;
        if (s[i - 1] == t[0])
            dp[i][1] = 1;
    }
    for (ll i = n; i >= 1; i--)
    {
        for (ll j = 0; j <= n - i + 1; j++)
        {
            if (j + 1 > m)
                dp[i][j + 1] = (dp[i][j + 1] + dp[i + 1][j]) % mod;
            else if (s[i - 1] == t[j])
                dp[i][j + 1] = (dp[i][j + 1] + dp[i + 1][j]) % mod;
            ll temp = j + i;
            if (temp > m)
                dp[i][j] = (dp[i][j] + dp[i + 1][j]) % mod;
            else if (s[i - 1] == t[temp - 1])
                dp[i][j] = (dp[i][j] + dp[i + 1][j]) % mod;
            // cout << dp[i][j] << " ";
        }
        // cout << "\n";
    }
    ll ans = 0;
    for (ll i = 0; i <= n; i++)
    {
        ans = (ans + dp[1][i]) % mod;
    }
    cout << ans << "\n";
}