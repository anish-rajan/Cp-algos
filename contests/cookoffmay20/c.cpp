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
#define INF INT_MAX

ll t;
v<ll> a(N);

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

struct LCA
{
    long long int n, l;
    vector<long long int> height;
    long long int timer;
    vector<long long int> tin, tout;
    vector<vector<long long int>> up;
    v<pair<ll, ll>> inc, dec;

    LCA(vector<vector<long long int>> &adj, long long int root = 0)
    {
        n = adj.size();
        tin.resize(n);
        height.resize(n);
        inc.resize(n);
        dec.resize(n);
        tout.resize(n);
        timer = 0;
        l = ceil(log2(n));
        up.assign(n, vector<long long int>(l + 1));
        dfs(adj, root, root);
    }

    void dfs(vector<vector<long long int>> &adj, long long int node, long long int p, long long int h = 0)
    {
        tin[node] = ++timer;
        up[node][0] = p;
        height[node] = h;
        for (long long int i = 1; i <= l; ++i)
            up[node][i] = up[up[node][i - 1]][i - 1];
        if (a[p] > a[node])
            inc[node] = mp(inc[p].fi + 1, inc[p].se), dec[node] = mp(0, node);
        else if (a[p] < a[node])
            dec[node] = mp(dec[p].fi + 1, dec[p].se), inc[node] = mp(0, node);
        else
            inc[node] = mp(0, node), dec[node] = mp(0, node);
        for (long long int u : adj[node])
        {
            if (u != p)
                dfs(adj, u, node, h + 1);
        }

        tout[node] = ++timer;
    }

    bool is_ancestor(long long int u, long long int v)
    {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    long long int dist(long long int u, long long int v)
    {
        ll lc = lca(u, v);
        return height[u] + height[v] - 2 * height[lc];
    }

    long long int lca(long long int u, long long int v)
    {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (long long int i = l; i >= 0; --i)
        {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }
    ll qry(ll x, ll y)
    {
        ll s = lca(x, y);
        ll t1 = dist(s, x), t2 = dist(s, y);
        if (inc[x].fi >= t1)
        {
            if (inc[y].fi >= t2)
                return true;
            else if (dec[inc[y].se].fi >= dist(s, inc[y].se))
                return true;
            return false;
        }
        else if (dec[inc[x].se].fi >= dist(s, inc[x].se))
        {
            if (inc[y].fi >= t2)
                return true;
            else
                return false;
        }
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        ll n, q;
        cin >> n >> q;
        v<v<ll>> adj(n + 1);
        for (ll i = 0; i < n - 1; i++)
        {
            ll x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        for (ll i = 1; i <= n; i++)
            cin >> a[i];
        LCA lca(adj, 1);
        string s;
        for (ll i = 0; i < q; i++)
        {
            ll x, y;
            cin >> x >> y;
            s += lca.qry(x, y) + 48;
        }
        cout << s << "\n";
    }
}