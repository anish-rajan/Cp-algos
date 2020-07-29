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
#define N 200005
#define mod 1000000009
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

// v<ll> fact(N);
v<ll> prime_check(2e5 + 2);
v<ll> primes;

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

void Sieve()
{
    for (ll i = 2; i <= 2e5; i++)
    {
        if (prime_check[i])
            continue;
        primes.pb(i);
        for (ll j = 2 * i; j <= 2e5; j += i)
            prime_check[j] = i;
    }
}
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

ll n;
vector<vector<ll>> adj(N);
v<ll> a(N);
v<map<ll, ll>> cnt(N);
v<ll> ans(N);

void upd(map<ll, pair<ll, ll>> &b, ll x, ll ind)
{
    if (b[ind].fi <= x)
        b[ind].se = b[ind].fi, b[ind].fi = x;
    else if (b[ind].se <= x)
        b[ind].se = x;
}

void dfs(ll u, ll p = 0)
{
    map<ll, pair<ll, ll>> b;
    for (auto x : adj[u])
        if (x != p)
            dfs(x, u);
    while (a[u] > 1)
    {
        ll x = prime_check[a[u]];
        if (x == 0)
            x = a[u];
        b[x].fi = 0, b[x].se = 0;
        for (auto y : adj[u])
        {
            if (y != p)
            {
                if (cnt[y].find(x) != cnt[y].end())
                    upd(b, cnt[y][x], x);
            }
        }
        cnt[u][x] = b[x].fi + 1;
        // cout << u << " " << x << " " << b[x].fi << " " << cnt[u][x] << " ";
        while (a[u] % x == 0)
            a[u] /= x;
        ans[x] = max(ans[x], max(cnt[u][x], b[x].fi + b[x].se + 1));
        // cout << cnt[u][x] << "\n";
    }
    // cout << u << " " << ans[2] << " " << cnt[u][2] << " " << b[2].fi << " " << b[2].se << "\n";
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
    Sieve();
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    input_adj(n);
    dfs(1);
    ll ans1 = 0;
    for (ll i = 2; i <= 2e5; i++)
        ans1 = max(ans1, ans[i]);
    cout << ans1 << "\n";
}