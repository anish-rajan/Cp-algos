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
ll mod = 1000000007;
#define INF INT64_MAX

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

ll m, n, k, t;
v<ll> a(N);
v<pair<pair<ll, ll>, ll>> traps(N);

ll check(ll x)
{
    ll time = 0;
    v<pair<ll, ll>> seg;
    for (ll i = 1; i <= k; i++)
        if (traps[i].se > x)
            seg.pb(traps[i].fi);
    sort(ALL(seg));
    for (ll i = 0; i < seg.size();)
    {
        ll j = i, max1 = seg[i].se;
        while (j < seg.size() && seg[j].fi <= max1)
            max1 = max(seg[j].se, max1), j++;
        time += max1 - seg[i].fi + 1;
        i = j;
    }
    time = 2 * time + n + 1;
    if (time <= t)
        return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> m >> n >> k >> t;
    for (ll i = 1; i <= m; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.begin() + m + 1, greater<ll>());
    for (ll i = 1; i <= k; i++)
        cin >> traps[i].fi.fi >> traps[i].fi.se >> traps[i].se;
    ll l = 1, r = m, ans = 0;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (check(a[mid]))
            l = mid + 1, ans = max(ans, mid);
        else
            r = mid - 1;
    }
    cout << ans << "\n";
}
