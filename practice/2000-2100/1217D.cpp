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
#define N 5005
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

ll n, m;
vector<vector<pair<ll, ll>>> adj(N);
vector<ll> visited(N);
v<pair<ll, ll>> edges;
v<ll> c(N);
ll ans;
ll timer;
v<ll> tin(N), tout(N);

void dfs(ll u)
{
    visited[u] = true;
    tin[u] = timer++;
    for (auto to : adj[u])
    {
        if (!visited[to.fi])
        {
            c[to.se] = 1;
            dfs(to.fi);
        }
        else if (tin[to.fi] < tin[u] && !tout[to.fi])
        {

            c[to.se] = 2, ans = 2;
        }
        else
            c[to.se] = 1;
    }
    // cout << u << " ";
    tout[u] = timer++;
}

void input_adj(long long int n)
{
    for (long long int i = 0; i < n - 1; i++)
    {
        long long int u, v;
        cin >> u >> v;
        adj[u].push_back(mp(v, i));
        edges.pb(mp(u, v));
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
    for (ll i = 1; i <= n; i++)
        if (!visited[i])
            dfs(i);
    if (ans == 0)
        cout << 1 << "\n";
    else
        cout << 2 << "\n";
    for (ll i = 0; i < m; i++)
    {
        cout << c[i] << " ";
    }
    cout << "\n";
}