#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double ld;
#define N 100005
#define mod 1000000007
vector<ll> arr(N);
ll n, t;
ll power(ll x, ll y, ll p)
{
    ll res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
               // equal to p

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
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<ll> dp(N);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        dp[0] = 1;
        for (ll i = 1; i < n; i++)
        {
            ll temp = __builtin_popcount(arr[i - 1]);
            ll temp1 = arr[i], temp2 = arr[i - 1];
            while (temp2)
            {
                if (temp2 % 2 == 1)
                {
                    if (temp1 % 2 == 1)
                    {
                        temp1 /= 2, temp2 /= 2;
                    }
                    else
                    {
                        dp[i - 1] = 0;
                        break;
                    }
                }
                else
                {
                    temp2 /= 2, temp1 /= 2;
                }
            }
            dp[i] = (dp[i - 1] * power(2, temp, mod)) % mod;
            // cout << dp[i] << " ";
        }
        cout << dp[n - 1] << "\n";
    }
}