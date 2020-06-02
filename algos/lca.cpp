#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 100005

using S = ll;
struct LCA
{
    S n, l;
    vector<S> height;
    S timer;
    vector<S> tin, tout;
    vector<vector<S>> up;

    LCA(vector<vector<S>> &adj, S root = 0)
    {
        n = adj.size();
        tin.resize(n);
        height.resize(n);
        tout.resize(n);
        timer = 0;
        l = ceil(log2(n));
        up.assign(n, vector<S>(l + 1));
        dfs(adj, root, root);
    }

    void dfs(vector<vector<S>> &adj, S node, S p, S h = 0)
    {
        tin[node] = ++timer;
        up[node][0] = p;
        height[node] = h;
        for (S i = 1; i <= l; ++i)
            up[node][i] = up[up[node][i - 1]][i - 1];

        for (S u : adj[node])
        {
            if (u != p)
                dfs(adj, u, node, h + 1);
        }

        tout[node] = ++timer;
    }

    S dist(S u, S v)
    {
        return height[u] + height[v] - 2 * height[lca(u, v)];
    }

    bool is_ancestor(S u, S v)
    {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    S lca(S u, S v)
    {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (S i = l; i >= 0; --i)
        {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }
};