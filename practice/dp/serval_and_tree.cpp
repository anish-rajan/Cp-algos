#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 300005
vector<vector<ll>> graph(N);
vector<ll> pol(N), visited(N), dp(N), leaves(N);
ll k = 0;
void dfs(ll u)
{
    visited[u] = 1;
    if (graph[u].size() == 1)
    {
        leaves[u] = 1;
        dp[u] = 1;
        return;
    }
    ll sum = 0;
    ll minimum = INT64_MAX;
    for (ll i = 0; i < graph[u].size(); i++)
    {
        if (!visited[graph[u][i]])
        {
            dfs(graph[u][i]);
            leaves[u] += leaves[graph[u][i]];
            sum += dp[graph[u][i]] - 1;
            minimum = min(minimum, leaves[graph[u][i]] - dp[graph[u][i]]);
        }
    }
    if (pol[u] == 1)
    {
        dp[u] = leaves[u] - minimum;
    }
    else
    {
        dp[u] = 1 + sum;
    }
}
int main()
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> pol[i];
    }
    for (ll i = 2; i <= n; i++)
    {
        ll u;
        cin >> u;
        graph[u].push_back(i);
        graph[i].push_back(u);
    }
    for (ll i = 2; i <= n; i++)
    {
        if (graph[i].size() == 1)
            k++;
    }
    dfs(1);
    // for (ll i = 1; i <= n; i++)
    // {
    //     cout << dp[i] << " ";
    // }
    // cout << "\n";
    cout << dp[1] << "\n";
}
