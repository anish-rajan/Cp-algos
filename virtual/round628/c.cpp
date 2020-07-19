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
#define N 300005
#define mod 1000000009
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

v<ll> fact(N);
v<ll> prime_check(1e6 + 2);
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
    for (ll i = 2; i <= 1e6 + 1; i++)
    {
        if (prime_check[i])
            continue;
        primes.pb(i);
        for (ll j = 2 * i; j <= 1e6 + 2; j += i)
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

ll n;

vector<vector<pair<ll, ll>>> adj(N);
vector<ll> visited(N);
v<ll> ans(N);
set<ll> nos;

void dfs(ll u, ll ind, ll x)
{
    visited[u] = 1;
    if (adj[u].size() != 1 && u != x)
    {
        auto itr = nos.end();
        itr--;
        ans[ind] = *itr;
        nos.erase(itr);
    }
    else if (u != x)
    {
        auto itr = nos.begin();
        ans[ind] = *itr;
        nos.erase(itr);
    }
    for (ll i = 0; i < adj[u].size(); i++)
    {
        if (!visited[adj[u][i].fi])
        {
            dfs(adj[u][i].fi, adj[u][i].se, x);
        }
    }
}

void input_adj(long long int n)
{
    for (long long int i = 0; i < n - 1; i++)
    {
        long long int u, v;
        cin >> u >> v;
        adj[u].push_back(mp(v, i));
        adj[v].push_back(mp(u, i));
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
    for (ll i = 0; i <= n - 2; i++)
        nos.insert(i);
    for (ll i = 1; i <= n; i++)
    {
        if (adj[i].size() >= 2)
            dfs(i, -1, i);
    }
    if (!visited[1])
        dfs(1, -1, 1);
    for (ll i = 0; i <= n - 2; i++)
        cout << ans[i] << "\n";
}