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
#define N 305
ll mod = 1000000007;
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

ll t, n, m, s, r;
vector<vector<ll>> d(N, v<ll>(N, INF));
v<v<ll>> c(N);
v<v<ll>> in(N);
v<v<ll>> invin(N);
using S = long long int;

vector<vector<S>> adj(N);

void dijkstra()
{
    using pii = pair<S, pair<S, S>>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for (ll i = 1; i <= n; i++)
        for (auto x : c[i])
            d[i][x] = 0, q.push(mp(0, mp(i, x)));

    while (!q.empty())
    {
        auto v = q.top().second;
        auto d_v = q.top().first;
        q.pop();
        if (d_v != d[v.fi][v.se])
            continue;

        for (auto edge : adj[v.fi])
        {
            S to1 = edge, to2 = v.se;
            S len = 1;
            if (d[v.fi][v.se] + len < d[to1][to2])
            {
                d[to1][to2] = d[v.fi][v.se] + len;
                q.push({d[to1][to2], mp(to1, to2)});
            }
        }
        for (auto i : invin[v.se])
        {
            ll cost = 0;
            for (auto x : in[i])
                cost += d[v.fi][x];
            cost -= d[v.fi][in[i].back()];
            if (cost < d[v.fi][in[i].back()])
            {
                d[v.fi][in[i].back()] = cost;
                q.push({cost, mp(v.fi, in[i].back())});
            }
        }
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
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        ll ans = INF;
        cin >> n >> m >> s >> r;
        input_adj(m + 1);
        for (ll i = 1; i <= n; i++)
        {
            ll no;
            cin >> no;
            for (ll j = 0; j < no; j++)
            {
                ll val;
                cin >> val;
                c[i].pb(val);
            }
        }
        for (ll i = 1; i <= r; i++)
        {
            ll no;
            cin >> no;
            for (ll j = 0; j < no; j++)
            {
                ll val;
                cin >> val;
                in[i].pb(val);
                invin[val].pb(i);
            }
            ll val;
            cin >> val;
            in[i].pb(val);
        }
        dijkstra();
        for (ll i = 1; i <= n; i++)
            ans = min(ans, d[i][1]);
        if (ans >= 1e12)
            ans = -1;
        cout << "Case #" << i << ": " << ans << "\n";
        for (ll i = 0; i <= max(s, max(n, r)); i++)
        {
            adj[i].clear(), c[i].clear(), in[i].clear(), invin[i].clear();
            fill(d[i].begin(), d[i].begin() + s + 2, INF);
        }
    }
}
