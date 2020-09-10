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
#define mod 1000000007
#define INF 1e15

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

ll t, n, m, ed;
v<v<ll>> adj(N), adj1(N);
v<ll> visited(N);
v<ll> p(N);

void dfs(ll u)
{
    visited[u] = 1;
    for (auto x : adj[u])
        if (!visited[x])
        {
            p[x] = u;
            adj1[u].pb(x);
            dfs(x);
        }
}
void dfs1(ll u)
{
    visited[u] = 1;
    for (auto x : adj1[u])
        if (!visited[x])
            dfs1(x), ed++;
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
        cin >> n >> m;
        ed = 0;
        input_adj(m + 1);
        for (ll i = 1; i <= n; i++)
        {
            sort(adj[i].begin(), adj[i].end(), [&](ll a, ll b) {
                return adj[a].size() > adj[b].size();
            });
        }
        ll pos = 1, root = 0;
        for (ll i = 1; i <= n; i++)
        {
            if (adj[i].size() == n - 1)
            {
                dfs(i);
                root = i;
                break;
            }
        }
        fill(visited.begin(), visited.begin() + n + 1, false);
        dfs1(root);
        for (ll i = 1; i <= n; i++)
            if (!visited[i])
                pos = 0;
        if (ed != n - 1)
            pos = 0;
        if (pos == 0)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            for (ll i = 1; i <= n; i++)
                cout << p[i] << " ";
            cout << "\n";
        }
        for (ll i = 0; i <= n; i++)
            adj[i].clear(), adj1[i].clear(), visited[i] = false, p[i] = 0;
    }
}

/*


1
16 35
1 2 
1 3 
2 3 
1 4 
2 4 
1 9 
2 9 
4 9 
1 5 
2 5 
4 5 
1 6 
2 6 
4 6 
5 6 
1 7 
1 8  
7 8 
1 10 
7 10
1 12
7 12
10 12
1 11
7 11
10 11
1 13
1 14
13 14
1 15
13 15
14 15
1 16
13 16
14 16


*/