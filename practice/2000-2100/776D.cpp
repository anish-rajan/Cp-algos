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

ll n, m;
v<set<pair<ll, ll>>> adj(N);
v<v<ll>> s(N, v<ll>(2)), doors(N);
v<ll> a(N);
v<ll> color(N);

ll dfs(ll u, ll c, ll par = 0)
{
    color[u] = c;
    ll temp = 1;
    for (auto y : adj[u])
    {
        ll x = y.fi;
        // cout << u << " " << x << " " << y.se << "\n";
        if (!color[x])
        {
            if (y.se == 1)
                temp = min(dfs(x, c == 1 ? 1 : 2, u), temp);
            else
                temp = min(dfs(x, c == 1 ? 2 : 1, u), temp);
        }
        else
        {
            if (y.se == 1 && color[x] != c)
                temp = 0;
            else if (y.se == 0 && color[x] == c)
                temp = 0;
        }
    }
    return temp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll i = 1; i <= m; i++)
    {
        ll sz;
        cin >> sz;
        for (ll j = 0; j < sz; j++)
        {
            ll x;
            cin >> x;
            s[x][1] = s[x][0], s[x][0] = i;
            doors[i].pb(x);
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        auto x = s[i];
        adj[x[0]].insert(mp(x[1], a[i]));
        adj[x[1]].insert(mp(x[0], a[i]));
    }
    ll f = 1;
    for (ll i = 1; i <= m; i++)
    {
        if (!color[i])
        {
            f = min(f, dfs(i, 1));
        }
    }
    if (f == 1)
        cout << "YES\n";
    else
        cout << "NO\n";
}