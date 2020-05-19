#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> graph(n + 1);
    vector<ll> dp(n + 1);
    for (ll i = 1; i <= m; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ll ans = -1;
    for (ll i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for (ll j = 0; j < graph[i].size(); j++)
        {
            if (graph[i][j] < i)
                dp[i] = max(dp[i], dp[graph[i][j]] + 1);
        }
        ll temp = graph[i].size() * dp[i];
        ans = max(ans, temp);
    }
    cout << ans << "\n";
}