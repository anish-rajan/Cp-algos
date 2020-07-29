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
#define N 2003
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

ll n;
v<ll> x(N), y(N), c(N), k(N);
v<pair<ll, ll>> ct(N);
v<pair<ll, ll>> edges;
ll ans;
v<ll> sources;

ll comp(ll i, ll j)
{
    return (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
}

void func(ll s, v<ll> left)
{
    if (left.size() == 0)
        return;
    v<pair<pair<ll, ll>, ll>> dist;
    for (auto p : left)
    {
        ll temp = comp(p, s);
        if (temp < ct[p].fi)
            ct[p].fi = temp, ct[p].se = s;
        dist.pb(mp(ct[p], p));
    }
    sort(dist.begin(), dist.end());
    if (dist[0].fi.se == 0)
        sources.pb(dist[0].se);
    else
        edges.pb({dist[0].fi.se, dist[0].se});
    ans += dist[0].fi.fi;
    v<ll> newl;
    for (ll i = 1; i < dist.size(); i++)
        newl.pb(dist[i].se);
    func(dist[0].se, newl);
}

using S = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n;
    v<ll> newl;
    v<pair<ll, ll>> newc;
    for (ll i = 1; i <= n; i++)
        cin >> x[i] >> y[i], newl.pb(i);
    for (ll i = 1; i <= n; i++)
        cin >> c[i], ct[i].fi = c[i], ct[i].se = 0, newc.pb(mp(c[i], i));
    for (ll i = 1; i <= n; i++)
        cin >> k[i];
    sort(newc.begin(), newc.end());
    newl.erase(newl.begin() + newc[0].se - 1);
    sources.pb(newc[0].se);
    ans += newc[0].fi;
    func(newc[0].se, newl);
    cout << ans << "\n";
    cout << sources.size() << "\n";
    for (auto x : sources)
        cout << x << " ";
    cout << "\n";
    cout << edges.size() << "\n";
    for (auto x : edges)
        cout << x.fi << " " << x.se << "\n";
}