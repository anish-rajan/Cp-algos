#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 4004
vector<ll> b(N);
vector<vector<ll>> dp(N, vector<ll>(N));
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    // cout << n;
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    ll index = 0;
    map<ll, ll> m;
    for (ll i = 0; i < n; i++)
        if (m.find(b[i]) == m.end())
            m[b[i]] = index++;
    for (ll i = 0; i < n; i++)
    {
        b[i] = m[b[i]];
    }
    ll ans = 1;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            dp[i][j] = 1;
        }
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < i; j++)
        {
            dp[i][b[j]] = max(1 + dp[j][b[i]], dp[i][b[j]]);
            // cout << dp[j][b[i]] << "\n";
            ans = max(ans, dp[i][b[j]]);
        }
    }
    cout << ans << "\n";
}