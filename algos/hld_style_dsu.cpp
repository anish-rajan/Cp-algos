#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 100005

////This is code for dsu on tree in hld style.. Very useful for subtree queries.
using S = long long int;

S cnt[N];
bool big[N];
S sz[N];
vector<S> col(N);
vector<vector<S>> adj(N);

void getsz(S v, S p)
{
    sz[v] = 1; // every vertex has itself in its subtree
    for (auto u : adj[v])
        if (u != p)
        {
            getsz(u, v);
            sz[v] += sz[u]; // add size of child u to its parent(v)
        }
}

void add(S v, S p, S x) /////important function.. Needs to be changed acc to ques.
{
    cnt[col[v]] += x;
    for (auto u : adj[v])
        if (u != p && !big[u])
            add(u, v, x);
}
void dfs(S v, S p, bool keep)
{
    S mx = -1, bigChild = -1;
    for (auto u : adj[v])
        if (u != p && sz[u] > mx)
            mx = sz[u], bigChild = u;
    for (auto u : adj[v])
        if (u != p && u != bigChild)
            dfs(u, v, 0); // run a dfs on small childs and clear them from cnt
    if (bigChild != -1)
        dfs(bigChild, v, 1), big[bigChild] = 1; // bigChild marked as big and not cleared from cnt
    add(v, p, 1);
    //now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
    if (bigChild != -1)
        big[bigChild] = 0;
    if (keep == 0)
        add(v, p, -1);
}