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

ll n, m;
v<v<ll>> adj(N);

using S = ll;
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
        tin[node] = ++timer;
        up[node][0] = p;
        height[node] = h;
        for (S i = 1; i <= l; ++i)
            up[node][i] = up[up[node][i - 1]][i - 1];

        for (S u : adj[node])
        {
            if (u != p)
                dfs(u, node, h + 1);
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

void input_adj(long long int n)
{
    for (long long int i = 0; i < n - 1; i++)
    {
        long long int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n;
    input_adj(n);
    LCA lca(n + 1, 1);
    cin >> m;
    while (m--)
    {
        ll x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        ll l1 = lca.dist(a, b), l2 = lca.dist(a, x), l3 = lca.dist(b, x), l4 = lca.dist(a, y), l5 = lca.dist(b, y);
        ll dist1 = l1, dist2 = l2 + l5 + 1, dist3 = l3 + l4 + 1;
        if (dist1 <= k && (k - dist1) % 2 == 0)
        {
            cout << "YES\n";
        }
        else if (dist2 <= k && (k - dist2) % 2 == 0)
        {
            cout << "YES\n";
        }
        else if (dist3 <= k && (k - dist3) % 2 == 0)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
}