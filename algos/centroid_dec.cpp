#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 100005

using S = long long int;

S subtree[N], parentcentroid[N];
set<S> g[N];
S nodes;

void dfs(S k, S par)
{
    nodes++;
    subtree[k] = 1;
    for (auto it : g[k])
    {
        if (it == par)
            continue;
        dfs(it, k);
        subtree[k] += subtree[it];
    }
}

S centroid(S k, S par)
{
    for (auto it : g[k])
    {
        if (it == par)
            continue;
        if (subtree[it] > (nodes >> 1))
            return centroid(it, k);
    }
    return k;
}

void decompose(S k, S par)
{
    nodes = 0;
    dfs(k, k);
    S node = centroid(k, k);
    parentcentroid[node] = par;
    for (auto it : g[node])
    {
        g[it].erase(node);
        decompose(it, node);
    }
}