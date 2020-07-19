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
#define mod 1000000009
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

v<ll> fact(N);
v<ll> prime_check(1e7 + 2);
v<ll> primes;

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

void Sieve()
{
    for (ll i = 2; i <= 1e7 + 1; i++)
    {
        if (prime_check[i])
            continue;
        primes.pb(i);
        for (ll j = 2 * i; j <= 1e7 + 1; j += i)
            prime_check[j] = i;
    }
}
ll phi(ll n)
{
    ll i, res = n;
    for (i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            res -= res / i;
        }
    if (n > 1)
        res -= res / n;
    return res;
}

/////////////////////////////////////START CODE HERE/////////////////////////////////////////////

struct DSU
{
    using S = long long int;
    S n;
    vector<S> parent;
    v<S> added;
    vector<S> size;

    DSU(S no)
    {
        n = no;
        parent.resize(n + 1);
        added.resize(n + 1);
        size.resize(n + 1);
        for (S i = 1; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
            added[i] = 0;
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

ll n, m;
v<v<pair<ll, ll>>> adj(N), adj1(N);
v<pair<pair<ll, ll>, pair<ll, ll>>> edges;
v<ll> ans(N), ans2(N);

using S = ll;
struct LCA
{
    S n, l;
    vector<S> height;
    S timer;
    vector<S> tin, tout;
    vector<vector<S>> up, maxi;

    LCA(ll no, vector<vector<pair<S, S>>> &adj, S root = 0)
    {
        n = no;
        tin.resize(n);
        height.resize(n);
        tout.resize(n);
        timer = 0;
        l = ceil(log2(n));
        up.assign(n, vector<S>(l + 1));
        maxi.assign(n, vector<S>(l + 1));
        dfs(adj, root, root);
    }

    void dfs(vector<vector<pair<S, S>>> &adj, S node, S p, S h = 0)
    {
        tin[node] = ++timer;
        up[node][0] = p;
        maxi[node][0] = 0;
        for (auto u : adj[node])
            if (u.fi == p)
                maxi[node][0] = u.se;
        height[node] = h;
        for (S i = 1; i <= l; ++i)
            up[node][i] = up[up[node][i - 1]][i - 1], maxi[node][i] = max(maxi[node][i - 1], maxi[up[node][i - 1]][i - 1]);

        for (auto u : adj[node])
        {
            if (u.fi != p)
                dfs(adj, u.fi, node, h + 1);
        }

        tout[node] = ++timer;
    }

    S dist(S u, S v)
    {
        return height[u] + height[v] - 2 * height[lca(u, v)];
    }
    S find_max(S node, S d)
    {
        ll ans = 0, c = 0;
        while (d > 0)
        {
            if (d % 2)
                ans = max(ans, maxi[node][c]), node = up[node][c];
            d /= 2;
            c++;
        }
        return ans;
    }

    bool is_ancestor(S u, S v)
    {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    S lca(S u, S v)
    {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (S i = l; i >= 0; --i)
        {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }
};

void input_adj(long long int n)
{
    for (long long int i = 0; i < n - 1; i++)
    {
        long long int u, v, w;
        cin >> u >> v >> w;
        edges.pb({{u, v}, {w, i}});
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n >> m;
    input_adj(m + 1);
    sort(edges.begin(), edges.end(), [](auto a, auto b) {
        return a.se.fi < b.se.fi;
    });
    ll maxedge = 0;
    DSU dsu(n);
    ll ans1 = 0;
    for (ll i = 0; i < m;)
    {
        ll j = i;
        while (j < m && edges[j].se.fi == edges[i].se.fi)
        {
            ll a = edges[j].fi.fi, b = edges[j].fi.se;
            if (dsu.find_set(a) != dsu.find_set(b))
            {
                ans[j] = 1;
                maxedge = max(maxedge, edges[j].se.fi);
            }
            j++;
        }
        j = i;
        while (j < m && edges[j].se.fi == edges[i].se.fi)
        {
            ll a = edges[j].fi.fi, b = edges[j].fi.se;
            if (dsu.find_set(a) != dsu.find_set(b))
            {
                ans1 += edges[j].se.fi;
                dsu.union_sets(a, b);
                adj1[a].pb({b, edges[j].se.fi});
                adj1[b].pb({a, edges[j].se.fi});
            }
            j++;
        }
        i = j;
    }
    // for (ll i = 0; i < m; i++)
    // {
    //     cout << edges[i].se.se << " " << ans[i] << "\n";
    // }
    LCA lca(n + 1, adj1, 1);
    for (ll i = 0; i < m; i++)
    {
        if (ans[i] == 1)
            ans2[edges[i].se.se] = ans1;
        else
        {
            ll x = edges[i].fi.fi, y = edges[i].fi.se;
            ll p = lca.lca(x, y);
            ll ans3 = lca.find_max(x, lca.dist(p, x));
            ans3 = max(ans3, lca.find_max(y, lca.dist(p, y)));
            ans2[edges[i].se.se] = ans1 - ans3 + edges[i].se.fi;
        }
    }
    for (ll i = 0; i < m; i++)
        cout << ans2[i] << "\n";
}