#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define v vector
#define inp_push(no, v) \
    ll no;              \
    cin >> no;          \
    v.push_back(no);
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 100005
#define mod 1000000007
#define INF INT_MAX
v<ll> fact(N);
long long powmod(long long x, long long y, long long m)
{
    long long res = 1LL;
    while (y)
    {
        if (y & 1)
            res = (res * x) % m;
        // cout << x << " " << mod << "\n";
        x = (x * x) % m;
        y /= 2;
    }
    return res;
}

void init_fact()
{
    fact[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

ll C(ll n, ll r)
{
    if (n < r)
        return 0;
    ll temp = fact[n] * powmod(fact[r], mod - 2, mod) % mod;
    temp *= powmod(fact[n - r], mod - 2, mod);
    temp %= mod;
    return temp;
}

/* Start code here */
ll n, m;
v<set<ll>> adj(N);
v<ll> isr(N), mindist(N);

using S = ll;

struct CentroidTree
{
    using S = int;
    using T = int;
    S start, numNodes;
    vector<S> subtree;
    vector<S> parentCentroid;
    CentroidTree(S s, S nodes)
    {
        start = s;
        subtree.resize(nodes);
        parentCentroid.resize(nodes);
    }
    void addEdge(T a, T b)
    {
        adj[a].insert(b);
        adj[b].insert(a);
    }
    void calcSubtree(S node, S parent)
    {
        numNodes++;
        subtree[node] = 1;
        for (auto i : adj[node])
        {
            if (i == parent)
                continue;
            calcSubtree(i, node);
            subtree[node] += subtree[i];
        }
    }
    S getCentroid(S node, S parent)
    {
        for (auto i : adj[node])
        {
            if (i == parent)
                continue;
            if (subtree[i] > (numNodes / 2))
                return getCentroid(i, node);
        }
        return node;
    }
    void decompose(S node, S parent)
    {
        numNodes = 0;
        calcSubtree(node, node);
        S centroid = getCentroid(node, node);
        parentCentroid[centroid] = parent;
        for (auto i : adj[centroid])
        {
            adj[i].erase(centroid);
            decompose(i, centroid);
        }
    }
};

struct LCA
{
    S n, l;
    vector<S> height;
    S timer;
    vector<S> tin, tout;
    vector<vector<S>> up;

    LCA(S n, S root = 0)
    {
        tin.resize(n);
        height.resize(n);
        tout.resize(n);
        timer = 0;
        l = ceil(log2(n));
        up.assign(n, vector<S>(l + 1));
        dfs(root, root);
    }

    void dfs(S node, S p, S h = 0)
    {
        tin[node] = ++timer;
        up[node][0] = p;
        height[node] = h;
        for (S i = 1; i <= l; ++i)
            up[node][i] = up[up[node][i - 1]][i - 1];

        for (S u : adj[node])
        {
            if (u != p)
                dfs(u, node, h + 1);
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    cin >> n >> m;
    for (ll i = 1; i <= n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    LCA lca(n + 1, 1);
    CentroidTree ct(1, n + 1);
    ct.decompose(1, 0);
    isr[1] = 1;
    for (ll i = 1; i <= n; i++)
    {
        mindist[i] = lca.dist(1, i);
        // cout << ct.parentCentroid[i] << " ";
    }
    while (m--)
    {
        ll qry, vert;
        cin >> qry >> vert;
        if (qry == 1)
        {
            isr[vert] = 1;
            ll par = vert;
            while (par != 0)
            {
                mindist[par] = min(mindist[par], lca.dist(par, vert));
                par = ct.parentCentroid[par];
            }
        }
        else
        {
            ll ans = INF;
            ll par = vert;
            while (par != 0)
            {
                ans = min(ans, lca.dist(par, vert) + mindist[par]);
                par = ct.parentCentroid[par];
            }
            cout << ans << "\n";
        }
    }
}