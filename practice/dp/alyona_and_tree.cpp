#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 100005
vector<vector<pair<ll, ll>>> graph(N);
vector<ll> visited(N), sub(N), mark(N), arr(N);
void dfs1(ll u, ll sum)
{
    if (sum > arr[u] && u != 1)
    {
        mark[u] = 1;
        // cout << u << "\n";
        return;
    }
    if (sum < 0)
        sum = 0;
    visited[u] = 1;
    for (ll i = 0; i < graph[u].size(); i++)
    {
        if (!visited[graph[u][i].first])
        {
            dfs1(graph[u][i].first, sum + graph[u][i].second);
        }
    }
}
ll dfs2(ll u)
{
    visited[u] = 1;
    ll counter = 1;
    for (ll i = 0; i < graph[u].size(); i++)
    {
        if (!visited[graph[u][i].first])
        {
            counter += dfs2(graph[u][i].first);
        }
    }
    sub[u] = counter;
    return counter;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (ll i = 1; i <= n - 1; i++)
    {
        ll u = i + 1;
        ll v, weight;
        cin >> v >> weight;
        graph[u].push_back(make_pair(v, weight));
        graph[v].push_back(make_pair(u, weight));
    }
    dfs1(1, 0);
    fill(visited.begin(), visited.begin() + n + 1, 0);
    dfs2(1);
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        // cout << sub[i] << " ";
        if (mark[i] == 1)
        {
            ans += sub[i];
        }
    }
    cout << ans << "\n";
}