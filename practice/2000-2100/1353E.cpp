#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define v vector
#define inp_push(no, v) \
    ll no;              \
    cin >> no;          \
    v.push_back(no);
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 100005
#define mod 1000000007
ll t;
long long powmod(long long x, long long y, long long m)
{
    long long res = 1LL;
    while (y)
    {
        if (y & 1)
            res = (res * x) % m;
        // cout << x << " " << mod << "\n";
        x = (x * x) % m;
        y /= 2;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        string s;
        v<ll> ones(n, 0), dp(n, 0), dp1(n, 0);
        cin >> s;
        ones[0] = s[0] == '1' ? 1 : 0;
        for (ll i = 1; i < n; i++)
            ones[i] = ones[i - 1] + (s[i] == '1' ? 1 : 0);
        dp[0] = s[0] == '1' ? 0 : 1;
        dp1[0] = s[0] == '1' ? 1 : 0;
        for (ll i = 1; i < n; i++)
        {
            if (i - k >= 0)
            {
                dp[i] = min(dp[i - k] + ones[i - 1] - ones[i - k] + (s[i] == '1' ? 0 : 1), ones[i - 1] + (s[i] == '1' ? 0 : 1));
                dp1[i] = min(ones[i], dp[i - k] + ones[i] - ones[i - k]);
                dp1[i] = min(dp1[i], dp1[i - k] + ones[i] - ones[i - k]);
            }
            else
            {
                dp[i] = ones[i - 1] + (s[i] == '1' ? 0 : 1);
                dp1[i] = ones[i];
            }
            // cout << dp[i] << " ";
        }
        ll ans = INT64_MAX;
        for (ll i = n - 1; i >= n - k; i--)
        {
            ans = min(ans, dp[i] + ones[n - 1] - ones[i]);
            ans = min(ans, dp1[i] + ones[n - 1] - ones[i]);
        }
        cout << ans << "\n";
    }
}