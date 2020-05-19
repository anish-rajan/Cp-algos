#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 100005
vector<vector<ll>> graph(N);
vector<ll> visited(N);
void dfs(ll u, ll &ans, ll &counted)
{
    visited[u] = 1;
    ll count = 0;
    for (ll i = 0; i < graph[u].size(); i++)
    {
        if (!visited[graph[u][i]])
        {
            dfs(graph[u][i], ans, count);
        }
    }
    counted += count + 1;
    if ((count + 1) % 2 == 0)
        ans++;
    // cout << ans << " " << u << " " << counted << "\n";
}
int main()
{
    ll n;
    cin >> n;
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    if (n % 2 == 1)
    {
        cout << -1 << "\n";
        return 0;
    }
    visited = {0};
    ll counted = 0, ans = 0;
    dfs(1, ans, counted);
    cout << ans - 1 << "\n";
}