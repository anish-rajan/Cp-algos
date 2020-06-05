#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 100005
#define mod 998244353

using S = long long int;
vector<vector<S>> adj(N), adjT(N);
struct SCC
{
    vector<bool> visited;
    vector<S> order, component;
    vector<S> belong;
    vector<S> condsz;
    vector<vector<S>> cond;
    S noc, n;

    SCC(S no)
    {
        n = no;
        visited.resize(n + 1, false);
        belong.resize(n + 1);
        cond.resize(n + 1);
        condsz.resize(n + 1);
        noc = 0;
        for (S i = 1; i <= n; ++i)
            if (!visited[i])
                dfs1(i);
        fill(visited.begin(), visited.begin() + n + 1, false);
        for (S i = 0; i < n; ++i)
        {
            S v = order[n - 1 - i];
            if (!visited[v])
            {
                dfs2(v);
                noc++;
                for (auto x : component)
                    belong[x] = noc;
                condsz[noc] = component.size();
                component.clear();
            }
        }
        make_cond();
    }

    void make_cond()
    {
        for (ll i = 1; i <= n; i++)
        {
            for (auto x : adj[i])
            {
                if (belong[x] != belong[i])
                    cond[belong[i]].pb(belong[x]);
            }
        }
    }

    void dfs1(S v)
    {
        visited[v] = true;
        for (S i = 0; i < adj[v].size(); ++i)
            if (!visited[adj[v][i]])
                dfs1(adj[v][i]);
        order.push_back(v);
    }

    void dfs2(S v)
    {
        visited[v] = true;
        component.push_back(v);
        for (S i = 0; i < adjT[v].size(); ++i)
            if (!visited[adjT[v][i]])
                dfs2(adjT[v][i]);
    }
};