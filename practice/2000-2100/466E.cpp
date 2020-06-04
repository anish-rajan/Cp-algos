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
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

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

/////////////////////////////////////START CODE HERE////////////////////////////////////////////

ll n, m;
v<v<ll>> adj(N);
v<v<pair<ll, ll>>> q23(N);
v<ll> par(N);
v<ll> q2, ans(N);

struct Query
{
    ll t, x, y, time;
};
v<Query> q12;

using S = ll;
struct LCA
{
    S n;
    S timer;
    vector<S> tin, tout, visited;

    LCA(S n, S root = 0)
    {
        tin.resize(n);
        visited.resize(n, 0);
        tout.resize(n);
        timer = 0;
        for (ll i = 1; i < n; i++)
        {
            if (!visited[i])
            {
                ll p1 = i;
                while (par[p1] != 0)
                    p1 = par[p1];
                dfs(p1, 0);
            }
        }
    }

    void dfs(S node, S p, S h = 0)
    {
        visited[node] = 1;
        tin[node] = ++timer;
        for (S u : adj[node])
        {
            if (u != p)
                dfs(u, node, h + 1);
        }
        tout[node] = ++timer;
    }

    bool is_ancestor(S u, S v)
    {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
};

struct DSU
{
    using S = long long int;
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    cin >> n >> m;
    ll timer = 0;
    ll ind = 0;
    while (m--)
    {
        ll t, x, y;
        cin >> t;
        if (t == 1)
        {
            cin >> x >> y;
            adj[y].pb(x);
            par[x] = {y};
            q12.pb({t, x, y, timer++});
        }
        else if (t == 2)
        {
            cin >> x;
            q2.pb(x);
            q12.pb({t, x, (ll)q2.size() - 1, timer++});
        }
        else
        {
            cin >> x >> y;
            q23[y - 1].pb(mp(x, ind++));
        }
    }
    LCA lca(n + 1);
    DSU dsu(n);
    for (ll i = 0; i < q12.size(); i++)
    {
        if (q12[i].t == 1)
        {
            dsu.union_sets(q12[i].x, q12[i].y);
        }
        else
        {
            ll p1 = q12[i].y;
            for (ll j = 0; j < q23[p1].size(); j++)
            {
                ll p2 = q23[p1][j].fi, p3 = q2[p1];
                if (dsu.find_set(p2) == dsu.find_set(p3) && lca.is_ancestor(p2, p3))
                    ans[q23[p1][j].se] = 1;
            }
        }
    }
    for (ll i = 0; i < ind; i++)
    {
        if (ans[i] == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}