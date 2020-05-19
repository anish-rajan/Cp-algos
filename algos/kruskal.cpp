#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using S = long long int;
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

    Edge(S a1, S b1, S weight1 = 0) : a(a1), b(b1), weight(weight1){};
};

bool sortweight(Edge a, Edge b)
{
    return a.weight < b.weight;
}
bool sortfirst(Edge a, Edge b)
{
    return a.a < b.a;
}

struct Graph
{
    vector<Edge> edges;
    vector<vector<pair<S, S>>> gr;
    S n, m;

    Graph(S vertices, S ed)
    {
        n = vertices;
        m = ed;
        gr.resize(n + 1);
    }

    void addEdge(S a, S b, S weight = 0)
    {
        Edge e(a, b, weight);
        edges.push_back(e);
        gr[a].push_back(make_pair(b, weight));
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

pair<vector<Edge>, S> Kruskal(Graph g)
{
    S cost = 0;
    vector<Edge> result;
    DSU dsu(g.n);
    sort(g.edges.begin(), g.edges.end(), sortweight);
    for (Edge e : g.edges)
    {
        if (dsu.find_set(e.a) != dsu.find_set(e.b))
        {
            cost += e.weight;
            result.push_back(e);
            dsu.union_sets(e.a, e.b);
        }
    }
    return make_pair(result, cost);
}
