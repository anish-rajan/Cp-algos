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
#define mod 1000000009
#define INF INT64_MAX

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

ll n, m, timer, L;
vector<vector<ll>> adj(N);
v<v<ll>> l(N), up(N, v<ll>(log2(N) + 1));
v<ll> par(N), tin(N), tout(N), height(N);

using S = ll;

void dfs(S node, S p, S h = 1)
{
    tin[node] = ++timer;
    up[node][0] = p;
    height[node] = h;
    l[h].pb(tin[node]);
    for (S i = 1; i <= L; ++i)
        up[node][i] = up[up[node][i - 1]][i - 1];

    for (S u : adj[node])
    {
        dfs(u, node, h + 1);
    }
    tout[node] = ++timer;
}

ll findp(ll u, ll p)
{
    ll dep = height[u];
    ll node = u, no = 0;
    while (p > 0)
    {
        if (p % 2)
            node = up[node][no];
        p /= 2, no++;
    }
    ll st = tin[node], en = tout[node];
    auto ind = lower_bound(l[dep].begin(), l[dep].end(), st) - l[dep].begin();
    auto ind1 = upper_bound(l[dep].begin(), l[dep].end(), en) - l[dep].begin();
    // cout << ind << " " << ind1 << " ";
    return ind1 - ind;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n;
    L = ceil(log2(n));
    for (ll i = 1; i <= n; i++)
    {
        cin >> par[i];
        adj[par[i]].pb(i);
    }
    for (ll i = 1; i <= n; i++)
    {
        if (par[i] == 0)
            dfs(i, 0);
    }
    // for (ll i = 1; i <= n; i++)
    // {
    //     for (auto x : l[i])
    //         cout << x << " ";
    //     cout << "\n";
    // }
    cin >> m;
    for (ll i = 1; i <= m; i++)
    {
        ll x, p;
        cin >> x >> p;
        cout << max(findp(x, p) - 1, 0LL) << " ";
    }
    cout << "\n";
}