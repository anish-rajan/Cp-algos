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
#define mod 1000000007
#define INF INT_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

v<ll> fact(N);
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

ll n, m, k;
v<v<ll>> adj(N);
v<ll> color(N);
vector<ll> visited(N), par(N);
v<ll> one, zero;

void dfs(ll u, ll col)
{
    visited[u] = 1;
    if (col == 0)
        zero.pb(u);
    else
        one.pb(u);
    for (ll i = 0; i < adj[u].size(); i++)
    {
        if (!visited[adj[u][i]])
        {
            dfs(adj[u][i], col ^ 1);
        }
    }
}

v<ll> cycle, nob;

void printc(ll u, ll x)
{
    cout << 2 << "\n";
    while (u != x)
        cycle.pb(u), u = par[u];
    cycle.pb(x);
    cout << cycle.size() << "\n";
    for (ll i = 0; i < cycle.size(); i++)
        cout << cycle[i] << " ";
    cout << "\n";
    exit(0);
}
void print()
{
    cout << 1 << "\n";
    // cout << nob.size() << "\n";
    ll j = 0;
    for (ll i = 0; j < (k / 2 + k % 2); i += 2)
        cout << nob[i] << " ", j++;
    cout << "\n";
    exit(0);
}

void dfs1(ll u, ll p)
{
    if (nob.size() >= k)
        print();
    visited[u] = 1;
    par[u] = p;
    for (auto x : adj[u])
    {
        if (x == p)
            continue;
        if (visited[x])
            printc(u, x);
    }
    nob.pb(u);
    if (nob.size() >= k)
        print();
    for (auto x : adj[u])
    {
        if (!visited[x])
            dfs1(x, u);
    }
    nob.pop_back();
    // cout << u << " " << nob.size() << "\n";
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
    cin >> n >> m >> k;
    input_adj(m + 1);
    if (m == n - 1)
    {
        dfs(1, 0);
        v<ll> ans = one.size() > zero.size() ? one : zero;
        cout << 1 << "\n";
        for (ll i = 0; i < k / 2 + k % 2; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
    else
        dfs1(1, 0);
}