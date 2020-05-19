#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define N 100005
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
ll n, m;
vector<ll> ans(N);
using S = ll;

struct DSU
{
    S n;
    vector<S> parent;
    vector<S> size;

    DSU(S no)
    {
        n = no;
        parent.resize(n + 1);
        size.resize(n + 1);
        for (S i = 1; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    S find_set(S v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(S a, S b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

struct Edge
{
    S a, b;
    S weight;
    S index;

    Edge(S a1, S b1, S index = 0, S weight1 = 0) : a(a1), b(b1), index(index), weight(weight1){};
};

bool sortweight(Edge a, Edge b)
{
    return a.weight < b.weight;
}
bool sortfirst(Edge a, Edge b)
{
    if (a.a == b.a)
        return a.b < b.b;
    else
        return a.a < b.a;
}

struct Graph
{
    vector<Edge> edges;
    vector<vector<pair<S, S>>> gr;
    vector<vector<pair<S, S>>> gri;
    S n, m;

    Graph(S vertices, S ed)
    {
        n = vertices;
        m = ed;
        gr.resize(n + 1);
        gri.resize(n + 1);
    }

    void addEdge(S a, S b, S index, S weight = 0)
    {
        Edge e(a, b, index, weight);
        edges.push_back(e);
        gr[a].push_back(make_pair(b, weight));
        gr[b].push_back(make_pair(a, weight));
        gri[a].push_back(make_pair(b, index));
        gri[b].push_back(make_pair(a, index));
    }

    void rmvEdge(S a, S b, S weight = 0)
    {
        for (S i = 0; i < edges.size(); i++)
        {
            if (edges[i].a == a && edges[i].b == b && edges[i].weight == weight)
            {
                edges.erase(edges.begin() + i);
            }
        }
        for (S i = 0; i < gr[a].size(); i++)
        {
            if (gr[a][i].first == b && gr[a][i].second == weight)
            {
                gr[a].erase(gr[a].begin() + i);
            }
        }
    }
};

vector<bool> visited;
vector<S> tin, low;
S timer;
vector<vector<S>> adj;
vector<vector<S>> adj1;
void dfs(S u, S p = 0)
{
    visited[u] = true;
    tin[u] = low[u] = timer++;
    for (S i = 0; i < adj[u].size(); i++)
    {
        auto to = adj[u][i];
        if (adj1[u][i] == p)
            continue;
        if (visited[to])
        {
            low[u] = min(low[u], tin[to]);
        }
        else
        {
            dfs(to, adj1[u][i]);
            low[u] = min(low[u], low[to]);
            if (low[to] > tin[u])
            {
                ans[adj1[u][i]] = 1;
            }
        }
    }
}

void find_bridges(ll n1)
{
    timer = 0;
    S n = n1;
    visited.assign(n + 1, false);
    tin.assign(n + 1, -1);
    low.assign(n + 1, -1);
    for (S i = 1; i <= n; ++i)
    {
        if (!visited[i])
            dfs(i);
    }
}

void Kruskal(Graph g)
{
    DSU dsu(g.n);
    sort(ALL(g.edges), sortweight);
    ll m = g.edges.size();
    for (S i = 0; i < m; i++)
    {
        if (i)
            if (g.edges[i].weight == g.edges[i - 1].weight)
                continue;
        v<pair<pair<ll, ll>, ll>> eds;
        v<ll> vertices;
        for (ll j = i; j < m; j++)
        {
            if (g.edges[j].weight != g.edges[i].weight)
                break;
            auto e = g.edges[j];
            if (dsu.find_set(e.a) != dsu.find_set(e.b))
            {
                eds.pb(mp(mp(dsu.find_set(e.a), dsu.find_set(e.b)), e.index));
                vertices.pb(dsu.find_set(e.a));
                vertices.pb(dsu.find_set(e.b));
                ans[e.index] = 2;
            }
        }
        UN(vertices);
        ll size_g = vertices.size(), m1 = eds.size();
        adj.assign(size_g + 1, vector<ll>());
        adj1.assign(size_g + 1, vector<ll>());
        map<ll, ll> ind;
        for (ll j = 0; j < size_g; j++)
        {
            ind[vertices[j]] = j + 1;
        }
        for (ll j = 0; j < m1; j++)
        {
            // cout << i << " " << eds[j].fi.fi << " " << eds[j].fi.se << endl;
            eds[j].fi.fi = ind[eds[j].fi.fi];
            eds[j].fi.se = ind[eds[j].fi.se];
            adj[eds[j].fi.fi].pb(eds[j].fi.se);
            adj[eds[j].fi.se].pb(eds[j].fi.fi);
            adj1[eds[j].fi.fi].pb(eds[j].second);
            adj1[eds[j].fi.se].pb(eds[j].second);
        }
        find_bridges(size_g);
        for (ll j = i; j < m; j++)
        {
            if (g.edges[j].weight != g.edges[i].weight)
                break;
            auto e = g.edges[j];
            if (dsu.find_set(e.a) != dsu.find_set(e.b))
            {
                dsu.union_sets(dsu.find_set(e.a), dsu.find_set(e.b));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    Graph g(n, m);
    for (ll i = 1; i <= m; i++)
    {
        ll a, b, weight;
        cin >> a >> b >> weight;
        g.addEdge(a, b, i, weight);
    }
    Kruskal(g);
    for (ll i = 1; i <= m; i++)
    {
        if (ans[i] == 0)
        {
            cout << "none" << endl;
        }
        else if (ans[i] == 1)
        {
            cout << "any" << endl;
        }
        else
            cout << "at least one" << endl;
    }
    return 0;
}