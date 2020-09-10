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

ll n, m;
v<pair<ll, ll>> mask(300);
v<v<ll>> a(N, v<ll>(10));

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j < m; j++)
            cin >> a[i][j];
    }
    for (ll i = 0; i < (1LL << m); i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            ll mini = INF;
            for (ll k = 0; k < m; k++)
            {
                if (i & (1LL << k))
                    mini = min(mini, a[j][k]);
            }
            if (mask[i].fi < mini)
                mask[i].fi = mini, mask[i].se = j;
        }
    }
    ll ans = -1, ind1 = 0, ind2 = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            ll nmask = 0;
            for (ll k = 0; k < m; k++)
            {
                if (a[i][k] >= a[i][j])
                    continue;
                else
                    nmask |= (1LL << k);
            }
            if (ans < a[i][j])
            {
                if (nmask == 0)
                    ans = a[i][j], ind1 = i, ind2 = i;
                else if (mask[nmask].fi >= a[i][j])
                    ans = a[i][j],
                    ind1 = i, ind2 = mask[nmask].se;
            }
        }
    }
    cout << ind1 << " " << ind2 << "\n";
}
