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

ll t, n, m;
vector<vector<pair<ll, ll>>> adj(N);
vector<ll> visited(N), cnt(N);
v<ll> p(N);

ll dfs1(ll u)
{
    visited[u] = 1;
    ll c = 1;
    for (auto x : adj[u])
    {
        if (!visited[x.fi])
        {
            ll temp = dfs1(x.fi);
            cnt[x.se] = temp;
            c += temp;
        }
    }
    return c;
}

void input_adj(long long int n)
{
    for (long long int i = 1; i <= n - 1; i++)
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
    cin >> t;
    while (t--)
    {
        cin >> n;
        input_adj(n);
        cin >> m;
        ll j = 1;
        for (; j <= m; j++)
        {
            cin >> p[j];
        }
        for (; j <= n - 1; j++)
        {
            p[j] = 1;
        }
        sort(p.begin(), p.begin() + max(m, n - 1) + 1);
        for (ll i = n; i <= m; i++)
        {
            p[n - 1] = (p[n - 1] * p[i]) % mod;
        }
        dfs1(1);
        for (ll i = 1; i <= n - 1; i++)
        {
            cnt[i] *= (n - cnt[i]);
        }
        sort(cnt.begin() + 1, cnt.begin() + n);
        ll i = 1;
        ll ans = 0;
        for (ll i = 1; i <= n - 1; i++)
        {
            ans = (ans + ((p[i] * cnt[i]) % mod)) % mod;
        }
        cout << ans << "\n";
        for (ll i = 0; i <= n; i++)
        {
            visited[i] = 0;
            adj[i].clear();
            cnt[i] = 0;
        }
    }
}
