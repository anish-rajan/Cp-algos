#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double ld;
#define N 202
vector<vector<ll>> graph(N);
vector<ll> visited(N), dp(N);
vector<pair<ll, ll>> edgelist;
ll n;
ll diameter(ll u)
{
    visited[u] = 1;
    ll ans = 0;
    dp[u] = 0;
    ll firstmax = 0, secondmax = 0;
    for (ll i = 0; i < graph[u].size(); i++)
    {
        if (!visited[graph[u][i]])
        {
            ans = max(ans, diameter(graph[u][i]));
            dp[u] = max(dp[u], dp[graph[u][i]] + 1);
            if (firstmax <= dp[graph[u][i]])
            {
                secondmax = firstmax;
                firstmax = dp[graph[u][i]];
            }
            else if (secondmax < dp[graph[u][i]])
            {
                secondmax = dp[graph[u][i]];
            }
        }
    }
    if (graph[u].size() >= 2)
        ans = max(ans, firstmax + secondmax + 2);
    ans = max(ans, dp[u]);
    // cout << u << " " << dp[u] << " " << ans << " " << firstmax << " " << secondmax << "\n";

    return ans;
}

void deleteEdge(ll u, ll v)
{
    for (ll j = 0; j < graph[u].size(); j++)
    {
        if (graph[u][j] == v)
        {
            graph[u].erase(graph[u].begin() + j);
            break;
        }
    }
    for (ll j = 0; j < graph[v].size(); j++)
    {
        if (graph[v][j] == u)
        {
            graph[v].erase(graph[v].begin() + j);
            break;
        }
    }
}
void addEdge(ll u, ll v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}
void input_graph()
{
    for (long long int i = 0; i < n - 1; i++)
    {
        long long int u, v;
        cin >> u >> v;
        edgelist.push_back(make_pair(u, v));
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    input_graph();
    ll ans = 0;
    for (ll i = 0; i < n - 1; i++)
    {
        ll u = edgelist[i].first, v = edgelist[i].second;
        deleteEdge(u, v);
        vector<ll> diacomp;
        fill(visited.begin(), visited.end(), 0);
        fill(dp.begin(), dp.end(), 0);
        for (ll j = 1; j <= n; j++)
        {
            if (!visited[j])
            {
                ll temp = diameter(j);
                diacomp.push_back(temp);
                // cout << u << " " << v << " " << temp << "\n";
            }
        }
        ans = max(ans, diacomp[0] * diacomp[1]);
        addEdge(u, v);
    }
    cout << ans << "\n";
}