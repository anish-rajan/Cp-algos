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
#define N 500005
ll mod = 1000000007;
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

using S = ll;
vector<vector<S>> adj(N), adj1(N); // adjacency list representation
S n, m;                            // number of nodes

pair<S, string> bfs()
{
    queue<S> q;
    vector<S> d(n + 1, INF), b(n + 1, INF), r(n + 1, INF);
    q.push(n);
    d[n] = b[n] = r[n] = 0;
    while (!q.empty())
    {
        S v = q.front();
        q.pop();
        for (S u : adj[v])
        {
            if (b[u] >= n)
            {
                b[u] = d[v] + 1;
                if (max(b[u], r[u]) < n)
                    q.push(u);
                d[u] = max(b[u], r[u]);
            }
        }
        for (S u : adj1[v])
        {
            if (r[u] >= n)
            {
                r[u] = d[v] + 1;
                if (max(r[u], b[u]) < n)
                    q.push(u);
                d[u] = max(b[u], r[u]);
            }
        }
    }
    pair<ll, string> temp;
    for (ll i = 1; i <= n; i++)
        temp.se += '1';
    if (d[1] >= n)
        temp.fi = -1;
    else
        temp.fi = d[1];
    for (ll i = 1; i <= n; i++)
        if (b[i] > r[i])
            temp.se[i - 1] = '0';
    return temp;
}

void input_adj(long long int m)
{
    for (long long int i = 0; i < m - 1; i++)
    {
        long long int u, v, z;
        cin >> u >> v >> z;
        if (z == 0)
            adj[v].push_back(u);
        else
            adj1[v].pb(u);
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
    auto temp = bfs();
    cout << temp.fi << "\n";
    cout << temp.se << "\n";
}
