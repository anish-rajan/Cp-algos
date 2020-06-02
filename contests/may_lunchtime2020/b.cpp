#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
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

using S = ll;
struct LCA
{
    S n, l;
    vector<S> height;
    S timer;
    vector<S> tin, tout;
    vector<vector<S>> up;
    v<v<S>> nos;

    LCA(vector<vector<S>> &adj, S root = 0)
    {
        n = adj.size();
        tin.resize(n);
        height.resize(n);
        nos.resize(n);
        tout.resize(n);
        timer = 0;
        l = ceil(log2(n));
        up.assign(n, vector<S>(l + 1));
        dfs(adj, root, root);
    }

    void dfs(vector<vector<S>> &adj, S node, S p, S h = 0)
    {
        tin[node] = ++timer;
        up[node][0] = p;
        height[node] = h;
        for (S i = 1; i <= l; ++i)
            up[node][i] = up[up[node][i - 1]][i - 1];
        nos[node].resize(101);
        nos[node] = nos[p];
        nos[node][a[node]]++;

        for (S u : adj[node])
        {
            if (u != p)
                dfs(adj, u, node, h + 1);
        }

        tout[node] = ++timer;
    }

    S dist(S u, S v)
    {
        return height[u] + height[v] - 2 * height[lca(u, v)];
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
    S qry(S a1, S b)
    {
        ll ans = 100;
        ll p = lca(a1, b);
        v<S> arr(101), newarr;
        for (ll i = 1; i <= 100; i++)
        {
            arr[i] = nos[a1][i] + nos[b][i] - 2 * nos[p][i];
        }
        arr[a[p]]++;
        for (ll i = 1; i <= 100; i++)
        {
            if (arr[i] >= 2)
                ans = 0;
            if (arr[i] >= 1)
                newarr.pb(i);
        }
        for (ll i = 0; i < newarr.size() - 1; i++)
            ans = min(ans, abs(newarr[i] - newarr[i + 1]));
        return ans;
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
        for (ll i = 1; i <= n; i++)
            cin >> a[i];
        for (ll i = 1; i <= n - 1; i++)
        {
            ll u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        LCA lca(adj, 1);
        while (q--)
        {
            ll a, b;
            cin >> a >> b;
            cout << lca.qry(a, b) << "\n";
        }
    }
}