#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define N 400005
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
using S = ll;
ll n, m;
v<v<pair<S, S>>> adj(N);
v<ll> is_bridge(N);
v<pair<ll, ll>> ans(N);

vector<bool> visited;
vector<S> tin, low;
S timer;

void dfs(S u, S p = -1)
{
    visited[u] = true;
    tin[u] = low[u] = timer++;
    for (pair<S, S> to : adj[u])
    {
        if (to.first == p)
            continue;
        if (visited[to.first])
        {
            low[u] = min(low[u], tin[to.first]);
        }
        else
        {
            dfs(to.first, u);
            low[u] = min(low[u], low[to.first]);
            if (low[to.first] > tin[u])
            {
                is_bridge[to.se] = 1;
            }
        }
    }
}

void find_bridges(S n1)
{
    timer = 0;
    S n = n1; // number of nodes
    visited.assign(n + 1, false);
    tin.assign(n + 1, -1);
    low.assign(n + 1, -1);
    for (S i = 1; i <= n; ++i)
    {
        if (!visited[i])
            dfs(i);
    }
}

void dfs1(ll u, ll &sum)
{
    visited[u] = 1;
    sum++;
    for (ll i = 0; i < adj[u].size(); i++)
    {
        if (!visited[adj[u][i].fi] && is_bridge[adj[u][i].se] == 0)
        {
            dfs1(adj[u][i].fi, sum);
        }
    }
}

void input_graph(long long int n)
{
    for (long long int i = 0; i < n; i++)
    {
        long long int u, v;
        cin >> u >> v;
        adj[u].push_back(mp(v, i));
        adj[v].push_back(mp(u, i));
    }
}
void dfs2(ll u, ll par = -1)
{
    visited[u] = 1;
    // cout << u << " " << par << endl;
    for (ll i = 0; i < adj[u].size(); i++)
    {
        if (adj[u][i].se == par)
            continue;
        if (ans[adj[u][i].se] == mp((ll)0, (ll)0))
            if (is_bridge[adj[u][i].se])
            {
                // cout << u << " " << adj[u][i].fi << " " << par << endl;
                ans[adj[u][i].se] = mp(adj[u][i].fi, u);
            }
            else
                ans[adj[u][i].se] = mp(u, adj[u][i].fi);
        if (!visited[adj[u][i].fi])
        {
            dfs2(adj[u][i].fi, adj[u][i].se);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    input_graph(m);
    find_bridges(n);
    fill(ALL(visited), false);
    ll maxi = 0, vert = 1;
    for (ll i = 1; i <= n; i++)
    {
        ll sum = 0;
        if (!visited[i])
        {
            dfs1(i, sum);
            if (maxi < sum)
            {
                maxi = sum;
                vert = i;
            }
        }
    }
    fill(ALL(visited), false);
    dfs2(vert);
    cout << maxi << endl;
    for (ll i = 0; i < m; i++)
    {
        cout << ans[i].fi << " " << ans[i].se << endl;
    }
}