#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 200005
vector<vector<ll>> graph(N);
vector<ll> pl(N), visited(N), dp(N);
ll ans = INT64_MIN;
ll dfs(ll u)
{
    visited[u] = 1;
    ll max1 = INT64_MIN, max2 = INT64_MIN;
    for (ll i = 0; i < graph[u].size(); i++)
    {
        if (!visited[graph[u][i]])
        {
            ll max = dfs(graph[u][i]);
            if (max >= max1)
            {
                max2 = max1;
                max1 = max;
            }
            else if (max > max2)
            {
                max2 = max;
            }
            dp[u] += dp[graph[u][i]];
        }
    }
    // cout << u << " " << dp[u] << " " << max1 << " " << max2 << "\n";
    if (max1 != INT64_MIN && max2 != INT64_MIN)
        ans = max(ans, max1 + max2);
    return max(max1, dp[u]);
}
int main()
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> pl[i];
        dp[i] = pl[i];
    }
    for (ll i = 1; i <= n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1);
    if (ans != INT64_MIN)
        cout << ans << "\n";
    else
        cout << "Impossible\n";
}