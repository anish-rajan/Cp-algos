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
#define N 102
#define mod 1000000007
#define INF INT64_MAX

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
set<ll> facts;
v<ll> a(N), a1(N);
v<v<ll>> vert(N);
v<pair<ll, ll>> edges(N);

struct Hopcroft_Karp
{
    using S = ll;
    static const ll inf = 1e9;

    ll n;
    vector<ll> matchL, matchR, dist;
    vector<vector<ll>> g;

    Hopcroft_Karp(ll n) : n(n), matchL(n + 1), matchR(n + 1), dist(n + 1), g(n + 1) {}

    void addEdge(ll u, ll v)
    {
        g[u].push_back(v);
    }

    bool bfs()
    {
        queue<ll> q;
        for (ll u = 1; u <= n; u++)
        {
            if (!matchL[u])
            {
                dist[u] = 0;
                q.push(u);
            }
            else
                dist[u] = inf;
        }
        dist[0] = inf;

        while (!q.empty())
        {
            ll u = q.front();
            q.pop();
            for (auto v : g[u])
            {
                if (dist[matchR[v]] == inf)
                {
                    dist[matchR[v]] = dist[u] + 1;
                    q.push(matchR[v]);
                }
            }
        }

        return (dist[0] != inf);
    }

    bool dfs(ll u)
    {
        if (!u)
            return true;
        for (auto v : g[u])
        {
            if (dist[matchR[v]] == dist[u] + 1 && dfs(matchR[v]))
            {
                matchL[u] = v;
                matchR[v] = u;
                return true;
            }
        }
        dist[u] = inf;
        return false;
    }

    ll max_matching()
    {
        ll matching = 0;
        while (bfs())
        {
            for (ll u = 1; u <= n; u++)
            {
                if (!matchL[u])
                    if (dfs(u))
                        matching++;
            }
        }
        return matching;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        ll x = a[i];
        for (ll j = 2; j <= sqrt(a[i]); j++)
        {
            while (x % j == 0)
                x /= j, facts.insert(j);
        }
        if (x != 1)
            facts.insert(x);
    }
    for (ll i = 1; i <= m; i++)
    {
        cin >> edges[i].fi >> edges[i].se;
        if (edges[i].fi & 1)
            swap(edges[i].fi, edges[i].se);
    }
    ll ans = 0;
    for (auto x : facts)
    {
        ll cnt = 0;
        for (ll i = 1; i <= n; i++)
        {
            ll y = a[i];
            while (y % x == 0)
                y /= x, vert[i].pb(++cnt);
        }
        Hopcroft_Karp hp(cnt);
        for (ll i = 1; i <= m; i++)
        {
            for (auto z : vert[edges[i].fi])
                for (auto w : vert[edges[i].se])
                    hp.addEdge(z, w);
        }
        ans += hp.max_matching();
        for (ll i = 1; i <= n; i++)
            vert[i].clear();
        // cout << x << " " << ans << "\n";
    }
    cout << ans << "\n";
}
