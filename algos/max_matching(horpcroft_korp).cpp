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
#define N 31622779
#define mod 998244353

//Only insert directed edges from A set to B set.

struct Hopcroft_Karp
{
    using S = ll;
    static const ll inf = 1e9;

    ll n;
    vector<ll> matchL, matchR, dist;
    vector<vector<ll>> g;

    Hopcroft_Karp(ll n) : n(n), matchL(n + 1), matchR(n + 1), dist(n + 1), g(n + 1) {}

    void addEdge(ll u, ll v)
    {
        g[u].push_back(v);
    }

    bool bfs()
    {
        queue<ll> q;
        for (ll u = 1; u <= n; u++)
        {
            if (!matchL[u])
            {
                dist[u] = 0;
                q.push(u);
            }
            else
                dist[u] = inf;
        }
        dist[0] = inf;

        while (!q.empty())
        {
            ll u = q.front();
            q.pop();
            for (auto v : g[u])
            {
                if (dist[matchR[v]] == inf)
                {
                    dist[matchR[v]] = dist[u] + 1;
                    q.push(matchR[v]);
                }
            }
        }

        return (dist[0] != inf);
    }

    bool dfs(ll u)
    {
        if (!u)
            return true;
        for (auto v : g[u])
        {
            if (dist[matchR[v]] == dist[u] + 1 && dfs(matchR[v]))
            {
                matchL[u] = v;
                matchR[v] = u;
                return true;
            }
        }
        dist[u] = inf;
        return false;
    }

    ll max_matching()
    {
        ll matching = 0;
        while (bfs())
        {
            for (ll u = 1; u <= n; u++)
            {
                if (!matchL[u])
                    if (dfs(u))
                        matching++;
            }
        }
        return matching;
    }
};