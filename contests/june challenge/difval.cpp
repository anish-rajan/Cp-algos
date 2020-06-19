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

ll t, n, m;
v<v<ll>> adj(N), c1(N), del(N);
v<ll> c(N), sz(N), visited(N), height(N);

struct LCA
{
    S n, l;
    S timer;
    vector<S> tin, tout;
    vector<vector<S>> up;

    LCA(S no, S root = 0)
    {
        n = no;
        tin.resize(n);
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

struct Vertex
{
    ll Sum;
    Vertex *left, *right;
    Vertex(ll val) : left(nullptr), right(nullptr), Sum(val) {}
    Vertex(Vertex *l, Vertex *r) : left(l), right(r), Sum(0)
    {
        if (l)
            Sum += l->Sum;
        if (r)
            Sum += r->Sum;
    }
    Vertex(ll _Sum, Vertex *_left, Vertex *_right)
    {
        Sum = _Sum;
        left = _left;
        right = _right;
    }
};

struct DST
{
    using S = ll;

    Vertex *root;
    DST()
    {
        root = new Vertex(0, NULL, NULL);
    }
    DST(Vertex *newroot) : root(newroot) {}

    Vertex *update1(Vertex *root, S l, S r, S pos, S value)
    {
        if (l == r)
        {
            return new Vertex(root->Sum + value);
        }
        if (root->left == NULL)
            root->left = new Vertex(0, NULL, NULL);
        if (root->right == NULL)
            root->right = new Vertex(0, NULL, NULL);
        ll mid = (l + r) / 2;
        if (pos <= mid)
            return new Vertex(update1(root->left, l, mid, pos, value), root->right);
        else
            return new Vertex(root->left, update1(root->right, mid + 1, r, pos, value));
    }

    S query(Vertex *root, S tl, S tr, S l, S r)
    {
        if (root == NULL || tl > r || l > tr)
            return 0;
        if (l <= tl && tr <= r)
            return root->Sum;
        if (root->left == NULL)
            root->left = new Vertex(0, NULL, NULL);
        if (root->right == NULL)
            root->right = new Vertex(0, NULL, NULL);
        ll mid = (tl + tr) / 2;
        return query(root->left, tl, mid, l, r) + query(root->right, mid + 1, tr, l, r);
    }
};

Vertex *merge(Vertex *root1, Vertex *root2)
{
    if (root1 == NULL && root2 == NULL)
        return NULL;
    else if (root1 == NULL && root2 != NULL)
    {
        return root2;
    }
    else if (root1 != NULL && root2 == NULL)
        return root1;
    else
    {
        Vertex *newroot = new Vertex(root1->Sum + root2->Sum, merge(root1->left, root2->left), merge(root1->right, root2->right));
        return newroot;
    }
}

void del_desc(Vertex *root)
{
    if (root == NULL)
        return;
    del_desc(root->left);
    del_desc(root->right);
    delete (root);
}

v<DST> dst(N);

void dfs(S u, S par = 0)
{
    visited[u] = 1;
    for (auto x : adj[u])
    {
        if (!visited[x])
            dfs(x, u);
    }
    dst[u].root = new Vertex(0, NULL, NULL);
    for (auto x : adj[u])
    {
        if (x != par)
        {
            dst[u].root = merge(dst[u].root, dst[x].root);
        }
    }
    for (auto x : del[u])
        dst[u].root = dst[u].update1(dst[u].root, 0, N, height[x], -1);
    dst[u].root = dst[u].update1(dst[u].root, 0, N, height[u], 1);
    // cout << u << " " << dst[u].query(dst[u].root, 0, N, height[u], height[u] + 2) << "\n";
}

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
        adj[i].clear();
        c[i] = 0;
        c1[i].clear();
        del[i].clear();
        visited[i] = 0;
        height[i] = 0;
        sz[i] = 0;
        del_desc(dst[i].root);
    }
    height[0] = -1;
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
            auto cmp = [=](ll a, ll b) { return lca.tin[a] < lca.tin[b]; };
            set<ll, decltype(cmp)> c3(cmp);
            v<ll> c2 = c1[i];
            sort(c2.begin(), c2.end(), [&](ll a, ll b) {
                return height[a] < height[b];
            });
            for (auto x : c2)
            {
                auto itr = c3.lower_bound(x);
                ll l1 = 0, l2 = 0;
                auto itr2 = itr;
                if (!c3.empty() && itr2 != c3.begin())
                {
                    itr2--;
                    l1 = lca.lca(*itr2, x);
                }
                if (!c3.empty() && itr != c3.end())
                {
                    l2 = lca.lca(*itr, x);
                }
                ll l = height[l1] > height[l2] ? l1 : l2;
                del[l].pb(x);
                c3.insert(x);
            }
        }
    }
    // //////////////find node deletion over///////////////////////

    // ///////////////////dfs for merging using persistence and dst//////////
    dfs(1);
    // //////////////////////////done merging with persistence//////////////////

    ////////////////////////queries//////////////////////////////////////////
    ll ans = 0;
    cin >> m;
    while (m--)
    {
        ll x, d;
        cin >> x >> d;
        x = x ^ ans, d = d ^ ans;
        ans = dst[x].query(dst[x].root, 0, N, height[x], height[x] + d);
        cout << ans << "\n";
    }
    //////////////////////done///////////////////////////////////////////
    // DST dst1;
    // dst1.root = dst1.update1(dst1.root, 0, 1e9, 2, 3);
    // dst1.root = dst1.update1(dst1.root, 0, 1e9, 2, -1);
    // cout << dst1.query(dst1.root, 0, 1e9, 2, 3);
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