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
#define N 300005
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

ll n;
v<ll> a(N);
v<pair<ll, ll>> o, t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    o.pb(mp(a[n], 0)), t.pb(mp(a[n], 0));
    for (ll i = n - 1; i >= 1; i--)
    {
        ll a1 = INF, a2 = INF;
        ll l1 = -1, l2 = INF, l3, l4;
        while (o.size() > 1 && a[i] > o.back().fi)
        {
            a1 = min(a1, o.back().se + 1), l1 = o.back().fi, l3 = o.back().se;
            while (o.size() > 1 && o.back().fi == l1)
                o.pop_back();
        }
        while (t.size() > 1 && a[i] < t.back().fi)
        {
            a2 = min(a2, t.back().se + 1), l2 = t.back().fi, l4 = t.back().se;
            while (t.size() > 1 && t.back().fi == l2)
                t.pop_back();
        }
        if (t.size() == 1 && t.back().fi >= l2)
            a2 = min(a2, l4 + 1);
        else
            a2 = min(a2, t.back().se + 1);
        if (o.size() == 1 && o.back().fi <= l1)
            a1 = min(a1, l3 + 1);
        else
            a1 = min(a1, o.back().se + 1);
        ll ans = min(a1, a2);
        o.pb(mp(a[i], ans)), t.pb(mp(a[i], ans));
        // cout << a[i] << " " << ans << " " << o.size() << " " << t.size() << "\n";
    }
    cout << o.back().se << "\n";
}
