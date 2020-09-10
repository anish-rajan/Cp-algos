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

ll n, m, k, q;
v<v<ll>> t(N);
v<ll> b;
map<pair<ll, ll>, ll> dp;

ll comp(ll a, ll b)
{
    return abs(a - b);
}

ll comp1(ll x, ll y)
{
    auto itr = lower_bound(ALL(b), x) - b.begin(), itr1 = itr;
    itr1--;
    auto itr2 = lower_bound(ALL(b), y) - b.begin(), itr3 = itr2;
    itr3--;
    ll dist = INF;
    if (itr < b.size())
        dist = min(dist, comp(x, b[itr]) + comp(y, b[itr]));
    if (itr1 >= 0)
        dist = min(dist, comp(x, b[itr1]) + comp(y, b[itr1]));
    if (itr2 < b.size())
        dist = min(dist, comp(x, b[itr2]) + comp(y, b[itr2]));
    if (itr3 >= 0)
        dist = min(dist, comp(x, b[itr3]) + comp(y, b[itr3]));
    return dist;
}

ll f(ll r, ll c)
{
    if (r == 1)
        return comp(1, t[1].back());
    if (dp.find({r, c}) != dp.end())
        return dp[mp(r, c)];
    ll ans = 0;
    ll cf = t[r][0];
    if (c == cf)
        cf = t[r].back();
    ans += comp(cf, c);
    ll x = r - 1;
    while (t[x].size() == 0)
        x--;
    ll c1 = t[x][0], c2 = t[x].back();
    if (x == 1)
        c1 = t[x].back();
    ans += min(r - x + comp1(cf, c1) + f(x, c1), r - x + comp1(cf, c2) + f(x, c2));
    dp[mp(r, c)] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n >> m >> k >> q;
    for (ll i = 1; i <= k; i++)
    {
        ll x, y;
        cin >> x >> y;
        t[x].pb(y);
    }
    t[1].pb(1);
    for (ll i = 1; i <= q; i++)
    {
        ll val;
        cin >> val;
        b.pb(val);
    }
    sort(ALL(b));
    for (ll i = 1; i <= n; i++)
        UN(t[i]);
    ll ans = 0;
    ll last = n;
    while (t[last].size() == 0)
        last--;
    ans = min(f(last, t[last].back()), f(last, t[last][0]));
    cout << ans << "\n";
}
