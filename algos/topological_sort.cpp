#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using S = long long int;

S n;                  // number of vertices
vector<vector<S>> gr; // gracency list of graph
vector<bool> visited;
vector<S> ts;

void dfs(S v)
{
    visited[v] = true;
    for (S u : gr[v])
    {
        if (!visited[u])
            dfs(u);
    }
    ts.push_back(v);
}

void topological_sort()
{
    visited.assign(n + 1, false);
    ts.clear();
    for (S i = 1; i <= n; ++i)
    {
        if (!visited[i])
            dfs(i);
    }
    reverse(ts.begin(), ts.end());
}