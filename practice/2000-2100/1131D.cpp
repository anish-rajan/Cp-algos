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
#define N 1003
#define mod 1000000007
#define INF 1e15

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

// v<ll> fact(N);
v<ll> prime_check(N);
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

ll n, m;
v<string> a(N);
v<ll> ans1(2 * N), visited(2 * N);
v<v<ll>> adj(2 * N);

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

ll dfs(ll u)
{
    if (visited[u] == 1)
        return ans1[u];
    visited[u] = 1;
    ll val = 0;
    for (auto x : adj[u])
    {
        val = max(val, dfs(x));
    }
    ans1[u] = val + 1;
    return ans1[u];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n >> m;
    DSU dsu(n + m + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i].insert(a[i].begin(), '0');
        for (ll j = 1; j <= m; j++)
        {
            if (a[i][j] == '=')
                dsu.union_sets(i, j + n);
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            if (a[i][j] == '>')
                adj[dsu.find_set(i)].pb(dsu.find_set(j + n));
            else if (a[i][j] == '<')
                adj[dsu.find_set(j + n)].pb(dsu.find_set(i));
        }
    }
    for (ll i = 1; i <= n + m; i++)
    {
        if (!visited[dsu.find_set(i)])
            dfs(dsu.find_set(i));
    }
    ll pos = 1;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            ll x = dsu.find_set(i), y = dsu.find_set(j + n);
            if (a[i][j] == '<' && ans1[x] >= ans1[y])
                pos = 0;
            else if (a[i][j] == '>' && ans1[x] <= ans1[y])
                pos = 0;
            else if (a[i][j] == '=' && ans1[x] != ans1[y])
                pos = 0;
        }
    }
    if (pos == 0)
    {
        cout << "No\n";
        return 0;
    }
    else
        cout << "Yes\n";
    for (ll i = 1; i <= n; i++)
    {
        cout << ans1[dsu.find_set(i)] << " ";
    }
    cout << "\n";
    for (ll i = n + 1; i <= n + m; i++)
        cout << ans1[dsu.find_set(i)] << " ";
    cout << "\n";
}
