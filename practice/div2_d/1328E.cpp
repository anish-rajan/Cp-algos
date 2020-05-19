#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define N 200005
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
ll n, m;
v<v<ll>> gr(N);

struct LCA
{
    long long int n, l;
    vector<long long int> height;
    long long int timer;
    vector<long long int> tin, tout;
    vector<vector<long long int>> up;

    LCA(vector<vector<long long int>> &adj, long long int root = 0)
    {
        n = adj.size();
        tin.resize(n);
        height.resize(n);
        tout.resize(n);
        timer = 0;
        l = ceil(log2(n));
        up.assign(n, vector<long long int>(l + 1));
        dfs(adj, root, root);
    }

    void dfs(vector<vector<long long int>> &adj, long long int node, long long int p, long long int h = 0)
    {
        tin[node] = ++timer;
        up[node][0] = p;
        height[node] = h;
        for (long long int i = 1; i <= l; ++i)
            up[node][i] = up[up[node][i - 1]][i - 1];

        for (long long int u : adj[node])
        {
            if (u != p)
                dfs(adj, u, node, h + 1);
        }

        tout[node] = ++timer;
    }

    bool is_ancestor(long long int u, long long int v)
    {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    long long int lca(long long int u, long long int v)
    {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (long long int i = l; i >= 0; --i)
        {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        gr[u].pb(v);
        gr[v].pb(u);
    }
    LCA lca(gr, 1);
    while (m--)
    {
        ll k;
        vector<ll> ver;
        cin >> k;
        ll maxh = 0, ve;
        for (ll i = 0; i < k; i++)
        {
            ll vert;
            cin >> vert;
            if (maxh < lca.height[vert])
            {
                maxh = lca.height[vert];
                ve = vert;
            }
            ver.push_back(vert);
        }
        ll pos = 1;
        for (ll i = 0; i < k; i++)
        {
            ll temp = lca.lca(ve, ver[i]);
            ll dist = lca.height[ver[i]] - lca.height[temp];
            if (dist > 1)
                pos = 0;
        }
        if (pos == 0)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}