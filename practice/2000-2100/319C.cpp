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

ll n;
v<ll> a(N), b(N), dp(N);

struct CHT
{
    //**CHT for decreasing slope and min query**//
    vector<ll> m, c;
    bool bad(ll f1, ll f2, ll f3) //change this for other query..
    {
        return 1.0 * (c[f3] - c[f1]) * (m[f1] - m[f2]) <= 1.0 * (c[f2] - c[f1]) * (m[f1] - m[f3]);
    }
    void add(ll _m, ll _c)
    {
        m.pb(_m), c.pb(_c);
        ll len = m.size();
        while (len >= 3 and bad(len - 3, len - 2, len - 1))
        {
            m.erase(m.end() - 2);
            c.erase(c.end() - 2);
            --len;
        }
    }
    ll f(ll i, ll x) { return m[i] * x + c[i]; }
    ll query(ll x)
    {
        ll l = 0, r = m.size() - 1;
        ll id = 0;
        while (l <= r)
        {
            ll del = (r - l) / 3;
            ll mid1 = l + del, mid2 = r - del;
            if (f(mid1, x) > f(mid2, x)) ///change this for another query.
                id = mid2, l = mid1 + 1;
            else
                id = mid1, r = mid2 - 1;
        }
        return f(id, x);
    }
};

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
    for (ll i = 1; i <= n; i++)
        cin >> b[i];
    CHT c;
    c.add(b[1], dp[1]);
    for (ll i = 2; i <= n; i++)
    {
        dp[i] = c.query(a[i]);
        c.add(b[i], dp[i]);
    }
    cout << dp[n] << "\n";
}