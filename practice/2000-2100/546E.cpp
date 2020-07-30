#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
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
#define N 103
#define mod 1000000007
#define INF INT_MAX

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

ll n, m;
v<ll> a(N), b(N);

typedef ll F;

#define MAXN 1000
#define MAXE 1000

struct maxFlow
{
    struct Edge
    {
        ll x, y;
        F cap, flow;
    };

    ll no, visited[MAXN], prev[MAXN];
    vector<Edge> E;
    vector<ll> g[MAXN];

    maxFlow(ll _N) : no(_N) {}

    ll res[300][300];

    void addEdge(ll x, ll y, F cap)
    {
        Edge e1 = {x, y, cap, 0}, e2 = {y, x, 0, 0};
        g[x].pb(E.size());
        E.pb(e1);
        g[y].pb(E.size());
        E.pb(e2);
    }

    bool bfs(ll s, ll t)
    {
        ll x, y;
        for (ll i = 1; i <= no; i++)
            visited[i] = prev[i] = -1;
        queue<ll> q;
        q.push(s);
        while (!q.empty())
        {
            x = q.front();
            q.pop();

            visited[x] = 1;

            for (auto it = g[x].begin(); it != g[x].end(); it++)
            {
                Edge &e = E[*it];
                y = e.y;

                if (e.cap == 0 or visited[y] == 1)
                    continue;

                visited[y] = 1, prev[y] = *it;
                q.push(y);
            }
        }

        return (visited[t] == 1);
    }

    F maxflow(ll s, ll t)
    {
        ll ans = 0;
        while (bfs(s, t))
        {
            F cap = INF;

            for (ll i = t; i != s; i = E[prev[i]].x)
                cap = min(cap, E[prev[i]].cap);
            for (ll i = t; i != s; i = E[prev[i]].x)
            {
                E[prev[i]].cap -= cap, E[prev[i] ^ 1].cap += cap;
                E[prev[i]].flow += cap;
                if (E[prev[i] ^ 1].flow > 0)
                    E[prev[i] ^ 1].flow -= cap;
            }

            ans += cap;
        }
        return ans;
    }
    void print()
    {
        for (ll i = 1; i <= n; i++)
        {
            for (auto it : g[i])
            {
                Edge &e = E[it];
                ll j = e.y;
                res[i][j - n] = e.flow;
            }
        }
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
                cout << res[i][j] << " ";
            cout << "\n";
        }
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
    ll tot = 0;
    for (ll i = 1; i <= n; i++)
        cin >> a[i], tot += a[i];
    for (ll i = 1; i <= n; i++)
        cin >> b[i], tot -= b[i];
    if (tot != 0)
    {
        cout << "NO\n";
        return 0;
    }
    maxFlow mf(2 * n + 2);
    ll S = 2 * n + 1, T = 2 * n + 2;
    for (ll i = 1; i <= n; i++)
    {
        mf.addEdge(S, i, a[i]);
        mf.addEdge(n + i, T, b[i]);
        mf.addEdge(i, n + i, INF);
        tot += a[i];
    }
    for (ll i = 1; i <= m; i++)
    {
        ll u, v;
        cin >> u >> v;
        mf.addEdge(u, v + n, INF);
        mf.addEdge(v, u + n, INF);
    }
    if (mf.maxflow(S, T) != tot)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        mf.print();
    }
}
