#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 100005
vector<ll> arr(N), dp(N), dp1(N);
int main()
{
    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    dp1[1] = 1;
    for (ll i = 2; i <= n; i++)
    {
        dp1[i] = arr[i] <= arr[i - 1] ? dp1[i - 1] + 1 : 1;
    }
    dp[n] = 1;
    for (ll i = n - 1; i >= 1; i--)
    {
        dp[i] = arr[i] <= arr[i + 1] ? dp[i + 1] + 1 : 1;
    }
    while (m--)
    {
        ll l, r;
        cin >> l >> r;
        if (dp[l] + l - 1 >= r - dp1[r] + 1)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}