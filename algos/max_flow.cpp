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
#define INF INT64_MAX

typedef ll F;

#define MAXN 1000
#define MAXE 1000

struct maxFlow
{
    struct Edge
    {
        ll x, y;
        F cap, flow;
    };

    ll n, visited[MAXN], prev[MAXN];
    vector<Edge> E;
    vector<ll> g[MAXN];

    maxFlow(ll _N) : n(_N) {}

    ll res[300][300];

    void addEdge(ll x, ll y, F cap)
    {
        Edge e1 = {x, y, cap, 0}, e2 = {y, x, 0, 0};
        g[x].pb(E.size());
        E.pb(e1);
        g[y].pb(E.size());
        E.pb(e2);
    }

    bool bfs(ll s, ll t)
    {
        ll x, y;
        for (ll i = 1; i <= n; i++)
            visited[i] = prev[i] = -1;
        queue<ll> q;
        q.push(s);
        while (!q.empty())
        {
            x = q.front();
            q.pop();

            visited[x] = 1;

            for (auto it = g[x].begin(); it != g[x].end(); it++)
            {
                Edge &e = E[*it];
                y = e.y;

                if (e.cap == 0 or visited[y] == 1)
                    continue;

                visited[y] = 1, prev[y] = *it;
                q.push(y);
            }
        }

        return (visited[t] == 1);
    }

    F maxflow(ll s, ll t)
    {
        ll ans = 0;
        while (bfs(s, t))
        {
            F cap = INF;

            for (ll i = t; i != s; i = E[prev[i]].x)
                cap = min(cap, E[prev[i]].cap);
            for (ll i = t; i != s; i = E[prev[i]].x)
            {
                E[prev[i]].cap -= cap, E[prev[i] ^ 1].cap += cap;
                E[prev[i]].flow += cap;
                if (E[prev[i] ^ 1].flow > 0)
                    E[prev[i] ^ 1].flow -= cap;
            }

            ans += cap;
        }
        return ans;
    }
};