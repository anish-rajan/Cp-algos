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
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

// v<ll> fact(N);
// v<ll> prime_check(N);
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
//     for (ll i = 2; i < 1e8; i++)
//     {
//         if (prime_check[i])
//             continue;
//         primes.pb(i);
//         for (ll j = 2 * i; j < 1e8; j += i)
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

ll t, n;
vector<vector<ll>> adj(N), adj1(N);
vector<ll> visited(N), p(N), a(N), b(N), ans(N), ind(N);
v<ll> arr;

using S = ll;
struct LCA
{
    S n, l;
    vector<S> height;
    vector<vector<S>> up;

    LCA(vector<vector<S>> &adj, S no, S root = 0)
    {
        n = no + 1;
        height.resize(n);
        l = ceil(log2(n));
        up.assign(n, vector<S>(l + 1));
        dfs(adj, root, root);
    }

    void dfs(vector<vector<S>> &adj, S node, S p, S h = 0)
    {
        up[node][0] = p;
        height[node] = h;
        for (S i = 1; i <= l; ++i)
            up[node][i] = up[up[node][i - 1]][i - 1];

        for (S u : adj[node])
        {
            if (u != p)
                dfs(adj, u, node, h + 1);
        }
    }
    S findkday(S u, S k)
    {
        ll cur = u, cnt = 0;
        while (k > 0)
        {
            if (k % 2)
                cur = up[cur][cnt];
            cnt++;
            k /= 2;
        }
        return ind[cur];
    }
};

struct DSU
{
    using S = ll;
    S n;
    vector<S> parent;
    vector<S> size;
    vector<S> join;

    DSU(S no)
    {
        n = no;
        parent.resize(n + 1);
        size.resize(n + 1);
        join.resize(n + 1);
        for (S i = 1; i <= n; i++)
        {
            parent[i] = i;
            join[i] = i;
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

void dfs(ll u, LCA &lca)
{
    visited[u] = 1;
    if (arr.size() > 0)
        arr.pb(arr.back() + a[u]);
    else
        arr.pb(a[u]);
    ll temp = lower_bound(arr.begin(), arr.end(), b[u]) - arr.begin();
    if (temp == arr.size())
        ans[u] = -1;
    else
        ans[u] = lca.findkday(u, arr.size() - 1 - temp);
    for (auto x : adj1[u])
        if (!visited[x])
            dfs(x, lca);
    arr.pop_back();
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
    cin >> t;
    while (t--)
    {
        cin >> n;
        input_adj(n);
        for (ll i = 1; i <= n; i++)
            cin >> p[i], ind[p[i]] = i;
        for (ll i = 1; i <= n; i++)
            cin >> a[i];
        for (ll i = 1; i <= n; i++)
            cin >> b[i];
        DSU dsu(n);
        for (ll i = n; i >= 1; i--)
        {
            ll y = dsu.find_set(p[i]);
            visited[p[i]] = 1;
            for (auto x : adj[p[i]])
            {
                if (visited[x])
                {
                    ll z = dsu.join[dsu.find_set(x)];
                    adj1[p[i]].pb(z);
                    dsu.union_sets(y, dsu.find_set(x));
                    y = dsu.find_set(y);
                }
            }
            dsu.join[dsu.find_set(y)] = p[i];
        }
        LCA lca(adj1, n, p[1]);
        fill(visited.begin(), visited.begin() + n + 1, false);
        dfs(p[1], lca);
        for (ll i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << "\n";
        for (ll i = 0; i <= n; i++)
            adj[i].clear(), adj1[i].clear(), visited[i] = 0;
        arr.clear();
    }
}
