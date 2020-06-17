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
#define N 3003
#define mod 1000000007
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

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

using S = ll;

ll t, n;
v<v<ll>> adj(N), c1(N), del(N);
v<ll> c(N), sz(N);

struct LCA
{
    S n, l;
    vector<S> height;
    S timer;
    vector<S> tin, tout;
    vector<vector<S>> up;

    LCA(S no, S root = 0)
    {
        n = no;
        tin.resize(n);
        height.resize(n);
        tout.resize(n);
        timer = 0;
        l = ceil(log2(n));
        up.assign(n, vector<S>(l + 1));
        dfs(root, root);
    }

    void dfs(S node, S p, S h = 0)
    {
        sz[node] = 1;
        tin[node] = ++timer;
        up[node][0] = p;
        height[node] = h;
        for (S i = 1; i <= l; ++i)
            up[node][i] = up[up[node][i - 1]][i - 1];

        for (S u : adj[node])
        {
            if (u != p)
                dfs(u, node, h + 1), sz[node] += sz[u];
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
};

struct DST
{
    using S = ll;

    struct Vertex
    {
        ll Sum;
        Vertex *left, *right;
        Vertex(ll val) : left(nullptr), right(nullptr), Sum(val) {}
        Vertex(ll _Sum, Vertex *_left, Vertex *_right)
        {
            Sum = _Sum;
            left = _left;
            right = _right;
        }
    };

    Vertex *update(Vertex *root, S l, S r, S s, S e, S value)
    {
        if (s > r || l > e)
            return NULL;
        if (l >= s && r <= e)
        {
            return new Vertex(root->Sum + value);
        }
        S mid = (l + r) / 2;
        Vertex *newroot;
        newroot = new Vertex(0, NULL, NULL);
        newroot->left = update(root->left, l, (l + r) / 2, s, e, value);
        newroot->right = update(root->right, (l + r) / 2 + 1, r, s, e, value);
        newroot->Sum = newroot->left->Sum + newroot->right->Sum;
        return newroot;
    }

    S query(Vertex *root, S tl, S tr, S l, S r)
    {
        if (root == NULL || tl > r || l > tr)
            return 0;
        if (l <= tl && tr <= r)
            return root->Sum;
        ll mid = (tl + tr) / 2;
        return query(root->left, tl, mid, l, r) + query(root->right, mid + 1, tr, l, r);
    }
};

// void dfs(S v, S p, bool keep)
// {
//     S mx = -1, bigChild = -1;
//     for (auto u : adj[v])
//         if (u != p && sz[u] > mx)
//             mx = sz[u], bigChild = u;
//     for (auto u : adj[v])
//         if (u != p && u != bigChild)
//             dfs(u, v, 0); // run a dfs on small childs and clear them from cnt
//     if (bigChild != -1)
//         dfs(bigChild, v, 1), big[bigChild] = 1; // bigChild marked as big and not cleared from cnt
//     add(v, p, 1);
//     //now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
//     if (bigChild != -1)
//         big[bigChild] = 0;
//     if (keep == 0)
//         add(v, p, -1);
// }

void input_adj(long long int n)
{
    for (long long int i = 2; i <= n; i++)
    {
        ll u;
        cin >> u;
        adj[u].pb(i);
        adj[i].pb(u);
    }
}

void solve()
{
    cin >> n;
    ///////////////////cache clearance////////////////////////////////
    for (ll i = 0; i <= n; i++)
    {
        adj[i].clear(), c[i] = 0, c1[i].clear(), del[i].clear();
    }
    ///////////////////over///////////////////////////////////////

    //////////////////////////input//////////////////////////
    input_adj(n);
    LCA lca(n + 1, 1);
    for (ll i = 1; i <= n; i++)
        cin >> c[i], c1[c[i]].pb(i);
    ////////////////////////input over////////////////////////

    ////////////Finding where node will be deleted..//////////////////
    for (ll i = 1; i <= n; i++)
    {
        if (c1[i].size())
        {
            auto cmp = [&](ll a, ll b) { return lca.tin[a] < lca.tin[b]; };
            set<ll, decltype(cmp)> c3(cmp);
            v<ll> c2 = c1[i];
            sort(c2.begin(), c2.end(), [&](ll a, ll b) {
                return lca.height[a] < lca.height[b];
            });
            for (auto x : c2)
            {
                auto itr = c3.lower_bound(lca.tin[x]);
                ll l1 = 0, l2 = 0;
                auto itr2 = itr;
                if (itr2 != c3.begin())
                {
                    itr2--;
                    l1 = lca.lca(*itr2, x);
                }
                if (itr != c3.end())
                {
                    l2 = lca.lca(*itr, x);
                }
                ll l = lca.height[l1] > lca.height[l2] ? l1 : l2;
                del[l].pb(x);
                c3.insert(x);
            }
        }
    }
    ////////////////find node deletion over///////////////////////

    /////////////////////dfs for small to large merging using persistence and dst//////////
    // dfs(1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> t;
    for (ll i = 1; i <= t; i++)
        solve();
}