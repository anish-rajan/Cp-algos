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
#define mod = 1000000007;
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
vector<vector<ll>> adj(N);
v<ll> excess(N), req(N), c(N), parity(N);
ll ans;

void dfs(ll u, ll pty, ll parent = 0)
{
    excess[u] = (pty == parity[u]);
    req[u] = (c[u] == 0);
    for (auto x : adj[u])
        if (x != parent)
        {
            dfs(x, pty, u);
            excess[u] += excess[x];
            req[u] += req[x];
        }
    ll temp = min(excess[u], req[u]);
    excess[u] -= temp;
    req[u] -= temp;
    ans += excess[u] + req[u];
}

void dfs1(ll u, ll pty, ll par = 0)
{
    parity[u] = pty;
    for (auto x : adj[u])
        if (x != par)
            dfs1(x, pty ^ 1, u);
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
    for (ll i = 1; i <= t; i++)
    {
        cin >> n;
        input_adj(n);
        string s;
        cin >> s;
        for (ll i = 0; i < s.size(); i++)
            c[i + 1] = (s[i] - '0');
        dfs1(1, 0);
        ll fin = INF;
        ans = 0;
        dfs(1, 0);
        if (excess[1] == req[1])
            fin = min(fin, ans);
        ans = 0;
        dfs(1, 1);
        if (excess[1] == req[1])
            fin = min(fin, ans);
        if (fin == INF)
        {
            fin = -1;
        }
        cout << fin << "\n";
        for (ll i = 0; i <= n; i++)
        {
            adj[i].clear();
            parity[i] = c[i] = excess[i] = req[i] = 0;
        }
    }
}
