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

ll t, n, x, y;

ll func(ll d, ll i)
{
    ll k1 = x / d;
    if (x % d == 0)
        k1--;
    k1 = min(k1, n - i - 2);
    ll req = max(0LL, n - k1 - i - 2);
    return y + req * d;
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
        cin >> n >> x >> y;
        ll ans = INF;
        ll no = -1;
        for (ll i = 0; i <= n - 2; i++)
        {
            ll diff = (y - x);
            if ((y - x) % (i + 1) == 0)
            {
                ll temp = func((y - x) / (i + 1), i);
                // cout << i << " " << temp << "\n";
                if (ans > temp)
                    ans = temp, no = i;
            }
        }
        // cout << no << "\n";
        ll d = (y - x) / (no + 1);
        ll k1 = x / d;
        if (x % d == 0)
            k1--;
        k1 = min(k1, n - no - 2);
        ll req = max(0LL, n - k1 - no - 2);
        v<ll> a;
        ll st = x - k1 * d;
        a.pb(st);
        for (ll i = 0; i < n - 1; i++)
            a.pb(a.back() + d);
        for (auto x : a)
            cout << x << " ";
        cout << "\n";
    }
}
