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
#define N 200005
#define mod 1000000007
#define INF INT_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

v<ll> fact(N);

long long powmod(long long x, long long y, long long m)
{
    long long res = 1LL;
    while (y)
    {
        if (y & 1)
            res = (res * x) % m;
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

ll t;

using S = long long int;
vector<vector<S>> adj(N), adjT(N);
v<pair<ll, ll>> ed;
v<v<ll>> rem(N);
v<ll> marked(N);
map<pair<ll, ll>, ll> edtoind;

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

void input_adj(long long int n)
{
    for (long long int i = 0; i < n - 1; i++)
    {
        long long int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        adjT[u].pb(v), adjT[v].pb(u);
        ed.pb(mp(u, v));
        edtoind[mp(u, v)] = i;
    }
}

bool comp(ll a, ll b)
{
    return rem[a].size() > rem[b].size();
}

struct SCC
{
    vector<bool> visited;
    vector<S> order, component;
    vector<S> belong;
    vector<S> condsz;
    vector<vector<S>> cond;
    vector<S> comps, one;
    S noc, n;

    SCC(S no)
    {
        n = no;
        visited.resize(n + 1, false);
        belong.resize(n + 1);
        cond.resize(n + 1);
        condsz.resize(n + 1);
        one.resize(n + 1);

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
                comps.pb(noc);
                for (auto x : component)
                    belong[x] = noc, one[noc] = x;
                condsz[noc] = component.size();
                component.clear();
            }
        }
        make_cond();
        extra_edges();
        sort(comps.begin(), comps.end(), comp);
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
    void extra_edges()
    {
        DSU dsu(n);
        for (ll i = 0; i < ed.size(); i++)
        {
            ll a = ed[i].fi, b = ed[i].se;
            if (dsu.find_set(a) == dsu.find_set(b))
            {
                rem[belong[a]].pb(i);
            }
            dsu.union_sets(a, b);
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        input_adj(m + 1);
        SCC scc(n);
        v<ll> currex;
        for (auto x : rem[scc.comps[0]])
            currex.pb(x);
        ll inc = 0;
        for (ll i = 1; i < scc.noc; i++)
        {
            ll u = scc.comps[i], u1 = scc.comps[i - 1];
            if (currex.size() > 0)
            {
                if (rem[u].size() == 0 && scc.condsz[u] == 0)
                {
                    inc += 2;
                    ll a = scc.one[u];
                    auto b = ed[currex.back()];
                    marked[currex.back()]++;
                    currex.pop_back();
                    ed.pb(mp(a, b.fi)), ed.pb(mp(a, b.se));
                    edtoind[mp(a, b.fi)] = (ll)ed.size() - 2, edtoind[mp(a, b.se)] = (ll)ed.size() - 1;
                    currex.pb((ll)ed.size() - 1);
                }
                else if (rem[u].size() == 0)
                {
                    ll a = scc.one[u], a1 = adj[a][0];
                    if (edtoind.find(mp(a, a1)) != edtoind.end())
                        marked[edtoind[mp(a, a1)]]++;
                    else
                        marked[edtoind[mp(a1, a)]]++;
                    auto b = ed[currex.back()];
                    marked[currex.back()]++;
                    currex.pop_back();
                    ed.pb(mp(a, b.fi)), ed.pb(mp(a1, b.se));
                    edtoind[mp(a, b.fi)] = (ll)ed.size() - 2, edtoind[mp(a1, b.se)] = (ll)ed.size() - 1;
                }
                else
                {
                    auto a = ed[rem[u].back()];
                    marked[rem[u].back()]++;
                    rem[u].pop_back();
                    auto b = ed[currex.back()];
                    marked[currex.back()]++;
                    currex.pop_back();
                    ed.pb(mp(a.fi, b.fi)), ed.pb(mp(a.se, b.se));
                    edtoind[mp(a.fi, b.fi)] = (ll)ed.size() - 2, edtoind[mp(a.se, b.se)] = (ll)ed.size() - 1;
                    currex.pb((ll)ed.size() - 1);
                    for (auto y : rem[u])
                        currex.pb(y);
                }
            }
            else
            {
                if (rem[u].size() == 0 && scc.condsz[u] == 0)
                {
                    inc += 2;
                    ll a = scc.one[u];
                    ll b = scc.one[u1];
                    ed.pb(mp(a, b));
                    edtoind[mp(a, b)] = (ll)ed.size() - 1;
                }
                else if (rem[u].size() == 0)
                {
                    inc += 2;
                    ll a = scc.one[u];
                    ll b = scc.one[u1];
                    ed.pb(mp(a, b));
                    edtoind[mp(a, b)] = (ll)ed.size() - 1;
                }
                else
                {
                    auto a = ed[rem[u].back()];
                    marked[rem[u].back()]++;
                    rem[u].pop_back();
                    ll b = scc.one[scc.comps[0]], b1 = adj[b][0];
                    marked[edtoind[mp(b, b1)]]++;
                    ed.pb(mp(a.fi, b)), ed.pb(mp(a.se, b1));
                    for (auto y : rem[u])
                        currex.pb(y);
                }
            }
        }
        ll edges = 0;
        for (ll i = 0; i < ed.size(); i++)
            if (!marked[i])
                edges++;
        cout << inc << " " << 0 << "\n";
        for (ll i = 0; i < ed.size(); i++)
            if (!marked[i])
                cout << ed[i].fi << " " << ed[i].se << "\n";

        ////////Clearing
        ed.clear(), edtoind.clear();
        for (ll i = 0; i <= max(n, m); i++)
        {
            adj[i].clear(), adjT[i].clear(), marked[i] = 0, rem[i].clear();
        }
    }
}