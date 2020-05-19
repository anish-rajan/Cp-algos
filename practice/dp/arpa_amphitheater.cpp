#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 1003
vector<vector<ll>> graph(N), comp, dp(N, vector<ll>(N));
vector<ll> bea(N), weight(N), visited(N);
void dfs(ll u, vector<ll> &nos)
{
    visited[u] = 1;
    nos.push_back(u);
    for (ll i = 0; i < graph[u].size(); i++)
    {
        if (!visited[graph[u][i]])
        {
            dfs(graph[u][i], nos);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, w;
    cin >> n >> m >> w;
    for (ll i = 1; i <= n; i++)
    {
        cin >> weight[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        cin >> bea[i];
    }
    for (ll i = 1; i <= m; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (ll i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            vector<ll> nos;
            dfs(i, nos);
            comp.push_back(nos);
        }
    }
    for (ll j = 1; j <= w; j++)
    {
        ll sum = 0;
        ll sumb = 0;
        for (ll k = 0; k < comp[0].size(); k++)
        {
            sum += weight[comp[0][k]];
            sumb += bea[comp[0][k]];
            if (j - weight[comp[0][k]] >= 0)
            {
                dp[0][j] = max(bea[comp[0][k]], dp[0][j]);
            }
        }
        if (j - sum >= 0)
        {
            dp[0][j] = max(sumb, dp[0][j]);
        }
    }
    for (ll i = 1; i < comp.size(); i++)
    {
        for (ll j = 1; j <= w; j++)
        {
            ll sum = 0;
            ll sumb = 0;
            for (ll k = 0; k < comp[i].size(); k++)
            {
                sum += weight[comp[i][k]];
                sumb += bea[comp[i][k]];
                if (j - weight[comp[i][k]] >= 0)
                {
                    dp[i][j] = max(dp[i - 1][j - weight[comp[i][k]]] + bea[comp[i][k]], dp[i][j]);
                }
            }
            if (j - sum >= 0)
            {
                dp[i][j] = max(dp[i - 1][j - sum] + sumb, dp[i][j]);
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    ll ans = 0;
    for (ll i = 0; i < comp.size(); i++)
    {
        ans = max(ans, dp[i][w]);
        // cout << ans << " ";
    }
    cout << ans << "\n";
}