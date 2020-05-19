#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 300005
vector<char> value(N);
vector<vector<ll>> graph(N);
vector<ll> visited(N), visiting(N), par(N);
vector<vector<ll>> dp(N, vector<ll>(26));
queue<ll> vertices;
ll ans = 0;
bool dfs1(ll u)
{
    visiting[u] = 1;
    // cout << u << "\n";
    for (ll i = 0; i < graph[u].size(); i++)
    {
        if (visiting[graph[u][i]] == 1 && visited[graph[u][i]] == 0)
        {
            return true;
        }
        else if (visiting[graph[u][i]] == 0)
        {
            if (dfs1(graph[u][i]))
            {
                return true;
            }
        }
    }
    visited[u] = 1;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        cin >> value[i];
    }
    for (ll i = 1; i <= m; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        par[v]++;
    }
    for (ll i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (dfs1(i))
            {
                cout << -1 << "\n";
                return 0;
            }
            // cout << 'a' << "\n";
        }
    }
    fill(visited.begin(), visited.begin() + n + 1, 0);
    fill(visiting.begin(), visiting.begin() + n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        if (par[i] == 0)
        {
            vertices.push(i);
            dp[i][value[i] - 'a']++;
        }
    }
    while (!vertices.empty())
    {
        ll u = vertices.front();
        vertices.pop();
        for (ll i = 0; i < graph[u].size(); i++)
        {
            if (par[graph[u][i]])
            {
                par[graph[u][i]]--;
                for (ll j = 0; j < 26; j++)
                {
                    dp[graph[u][i]][j] = max(dp[graph[u][i]][j], dp[u][j]);
                }
                if (!par[graph[u][i]])
                {
                    dp[graph[u][i]][value[graph[u][i]] - 'a']++;
                    vertices.push(graph[u][i]);
                }
            }
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j < 26; j++)
            ans = max(ans, dp[i][j]);
    }
    cout << ans << "\n";
}