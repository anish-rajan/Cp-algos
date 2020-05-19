#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 50005
#define K 505
vector<ll> visited(N);
vector<vector<ll>> graph(N), dp(N, vector<ll>(K));
void dfs1(ll u, ll k)
{
    visited[u] = 1;
    for (ll i = 0; i < graph[u].size(); i++)
    {
        if (!visited[graph[u][i]])
        {
            dp[u][1]++;
            dfs1(graph[u][i], k);
            for (ll j = 2; j <= k; j++)
                dp[u][j] += dp[graph[u][i]][j - 1];
        }
    }
}
void dfs2(ll u, ll v, ll k)
{

    visited[u] = 1;
    if (v != 0)
    {
        for (ll j = k; j >= 2; j--)
            dp[u][j] = dp[u][j] + dp[v][j - 1] - dp[u][j - 2];
        dp[u][1]++;
    }
    for (ll i = 0; i < graph[u].size(); i++)
    {
        if (!visited[graph[u][i]])
        {
            dfs2(graph[u][i], u, k);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    if (n == 1)
    {
        cout << n - 1 << "\n";
        return 0;
    }
    ll tmp = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (graph[i].size() == 1)
            tmp = i;
        dp[i][0] = 1;
    }
    dfs1(tmp, k);
    // for (ll i = 1; i <= n; i++)
    // {
    //     cout << dp[i][k] << " ";
    // }
    fill(visited.begin(), visited.end(), 0);
    dfs2(tmp, 0, k);
    // for (ll i = 1; i <= n; i++)
    // {
    //     cout << dp[i][3] << " ";
    // }
    ll sum = 0;
    for (ll i = 1; i <= n; i++)
    {
        sum += dp[i][k];
    }
    cout << sum / 2 << "\n";
}