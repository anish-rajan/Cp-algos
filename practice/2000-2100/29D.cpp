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
#define N 303
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

ll n, k, st;
v<v<ll>> adj(N);
v<set<ll>> leaves(N);
v<ll> visited(N), order, ans;

void dfs(ll u, ll p)
{
    if (adj[u].size() == 1 && u != 1)
        leaves[u].insert(u);
    for (auto x : adj[u])
    {
        if (x != p)
        {
            dfs(x, u);
            leaves[u].insert(leaves[x].begin(), leaves[x].end());
        }
    }
}

void dfs1(ll u, ll p = 0)
{
    ans.pb(u);
    if (adj[u].size() == 1 && u != 1)
    {
        st++, visited[u] = 1;
        return;
    }
    for (;;)
    {
        ll node = order[st];
        if (leaves[u].find(node) != leaves[u].end())
        {
            for (auto x : adj[u])
            {
                if (x != p && leaves[x].find(node) != leaves[x].end())
                {
                    dfs1(x, u);
                    visited[u] += visited[x];
                    ans.pb(u);
                    break;
                }
            }
        }
        else
        {
            cout << -1 << "\n";
            exit(0);
        }
        if (visited[u] == leaves[u].size())
            break;
    }
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
    for (ll i = 2; i <= n; i++)
        if (adj[i].size() == 1)
            k++;
    for (ll i = 1; i <= k; i++)
    {
        ll x;
        cin >> x;
        order.pb(x);
    }
    dfs(1, 0);
    // for (ll i = 1; i <= n; i++)
    //     cout << leaves[i].size() << " ";
    dfs1(1);
    for (ll i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << "\n";
}