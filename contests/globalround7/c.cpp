#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 200005
#define mod 998244353
vector<ll> arr(N), occur, dp(N), cum(N);
ll n, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (arr[i] >= n - k + 1)
        {
            occur.push_back(i);
        }
    }
    ll p = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (occur[p] == i)
        {
            ll temp;
            if (p != 0)
                temp = occur[p - 1];
            else
                temp = 0;
            if (p == 0)
                dp[i] = (cum[i - 1] - cum[temp] + 1 + mod) % mod;
            else
                dp[i] = (cum[i - 1] - cum[temp] + 1 * dp[i - 1] + mod) % mod;
            p++;
        }
        else
        {
            dp[i] = dp[i - 1];
        }
        cum[i] = cum[i - 1] + dp[i];
        // cout << dp[i] << " " << cum[i] << "\n";
    }
    ll temp = n * (n + 1);
    ll temp1 = (n - k) * (n - k + 1);
    temp -= temp1;
    temp /= 2;
    cout << temp << " " << dp[n];
}