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

ll n, m, c, s, ans, ans1, timer;
vector<vector<ll>> adj(N), adj1(2 * N);
vector<ll> visited(2 * N), par(2 * N), tin(N), tout(N);
map<pair<ll, ll>, ll> to;
map<ll, pair<ll, ll>> invto;

void dfs(ll u, ll p = 0)
{
    visited[u] = 1;
    par[u] = p;
    auto temp = invto[u];
    if (adj[temp.fi].size() == 0 && temp.se == 0)
        ans = u;
    for (ll i = 0; i < adj1[u].size(); i++)
    {
        if (!visited[adj1[u][i]])
        {
            dfs(adj1[u][i], u);
        }
    }
}

void dfs1(ll u)
{
    visited[u] = 1;
    tin[u] = ++timer;
    for (ll i = 0; i < adj[u].size(); i++)
    {
        ll x = adj[u][i];
        if (!visited[adj[u][i]])
        {
            dfs1(adj[u][i]);
        }
        else if (tout[x] == 0)
            ans1 = 1;
    }
    tout[u] = ++timer;
}

void input_adj()
{
    for (long long int i = 1; i <= n; i++)
    {
        ll sz;
        cin >> sz;
        for (ll j = 1; j <= sz; j++)
        {
            ll u;
            cin >> u;
            adj[i].pb(u);
            if (to.find(mp(i, 0)) == to.end())
            {
                to[mp(i, 0)] = ++c;
                invto[c] = mp(i, 0);
                to[mp(i, 1)] = ++c;
                invto[c] = mp(i, 1);
            }
            if (to.find(mp(u, 0)) == to.end())
            {
                to[mp(u, 0)] = ++c;
                invto[c] = mp(u, 0);
                to[mp(u, 1)] = ++c;
                invto[c] = mp(u, 1);
            }
            adj1[to[mp(i, 0)]].pb(to[mp(u, 1)]);
            adj1[to[mp(i, 1)]].pb(to[mp(u, 0)]);
        }
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
    input_adj();
    cin >> s;
    dfs(to[mp(s, 1)]);
    if (ans)
    {
        cout << "Win\n";
        v<ll> seq;
        seq.pb(ans);
        while (par[ans] != 0)
            seq.pb(par[ans]), ans = par[ans];
        reverse(seq.begin(), seq.end());
        for (auto x : seq)
        {
            cout << invto[x].fi << " ";
        }
        cout << "\n";
        return 0;
    }
    fill(visited.begin(), visited.end(), false);
    dfs1(s);
    if (ans1 == 1)
    {
        cout << "Draw\n";
        return 0;
    }
    cout << "Lose\n";
    return 0;
}
