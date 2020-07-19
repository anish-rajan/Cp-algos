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
#define N 500005
#define mod 1000000009
#define INF INT_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

// v<ll> fact(N);
// v<ll> prime_check(1e6 + 2);
// v<ll> primes;

// long long powmod(long long x, long long y, long long m)
// {
//     long long res = 1LL;
//     while (y)
//     {
//         if (y & 1)
//             res = (res * x) % m;
//         x = (x * x) % m;
//         y /= 2;
//     }
//     return res;
// }

// void init_fact()
// {
//     fact[0] = 1;
//     for (ll i = 1; i < N; i++)
//     {
//         fact[i] = (fact[i - 1] * i) % mod;
//     }
// }

// ll C(ll n, ll r)
// {
//     if (n < r)
//         return 0;
//     ll temp = fact[n] * powmod(fact[r], mod - 2, mod) % mod;
//     temp *= powmod(fact[n - r], mod - 2, mod);
//     temp %= mod;
//     return temp;
// }

// void Sieve()
// {
//     for (ll i = 2; i <= 1e6 + 1; i++)
//     {
//         if (prime_check[i])
//             continue;
//         primes.pb(i);
//         for (ll j = 2 * i; j <= 1e6 + 2; j += i)
//             prime_check[j] = i;
//     }
// }
// ll phi(ll n)
// {
//     ll i, res = n;
//     for (i = 2; i * i <= n; i++)
//         if (n % i == 0)
//         {
//             while (n % i == 0)
//                 n /= i;
//             res -= res / i;
//         }
//     if (n > 1)
//         res -= res / n;
//     return res;
// }

/////////////////////////////////////START CODE HERE/////////////////////////////////////////////

ll n, timer, m;
vector<vector<ll>> adj(N);
vector<ll> visited(N), tin(N), tout(N);

using S = ll;

struct ST
{
    struct data
    {
        S val;
    };
    vector<data> tree;
    vector<ll> lazy;
    ST()
    {
        tree.resize(8 * N);
        lazy.resize(8 * N);
    }
    data combine(data l, data r)
    {
        data res;
        res.val = max(l.val, r.val);
        return res;
    }
    data make_data(S val)
    {
        data res;
        res.val = val;
        return res;
    }
    void push(S node)
    {
        if (lazy[node] != 0)
        {
            tree[node * 2].val = lazy[node];
            lazy[node * 2] = lazy[node];
            tree[node * 2 + 1].val = lazy[node];
            lazy[node * 2 + 1] = lazy[node];
            lazy[node] = 0;
        }
    }

    void lazy_update(S node, S tl, S tr, S l, S r, S addend)
    {
        if (l > r)
            return;
        if (l == tl && tr == r)
        {
            tree[node].val = addend;
            lazy[node] = addend;
        }
        else
        {
            push(node);
            S tm = (tl + tr) / 2;
            lazy_update(node * 2, tl, tm, l, min(r, tm), addend);
            lazy_update(node * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
            tree[node] = combine(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    data lazy_query(S node, S tl, S tr, S l, S r)
    {
        if (l > r)
            return make_data(0);
        if (l <= tl && tr <= r)
            return tree[node];
        push(node);
        S tm = (tl + tr) / 2;
        data temp = combine(lazy_query(node * 2, tl, tm, l, min(r, tm)), lazy_query(node * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
        return temp;
    }
};

void dfs(ll u)
{
    visited[u] = 1;
    tin[u] = ++timer;
    for (ll i = 0; i < adj[u].size(); i++)
    {
        if (!visited[adj[u][i]])
        {
            dfs(adj[u][i]);
        }
    }
    tout[u] = ++timer;
}

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
    dfs(1);
    ST st1, st2;
    cin >> m;
    for (ll i = 1; i <= m; i++)
    {
        ll c, u;
        cin >> c >> u;
        if (c == 1)
        {
            st1.lazy_update(1, 1, 2 * N, tin[u], tout[u], i);
        }
        else if (c == 2)
        {
            st2.lazy_update(1, 1, 2 * N, tin[u], tin[u], i);
            st2.lazy_update(1, 1, 2 * N, tout[u], tout[u], i);
        }
        else
        {
            ll t1 = st1.lazy_query(1, 1, 2 * N, tin[u], tin[u]).val;
            ll t2 = st2.lazy_query(1, 1, 2 * N, tin[u], tout[u]).val;
            if (t1 <= t2)
                cout << 0 << "\n";

            else
                cout << 1 << "\n";
        }
    }
}