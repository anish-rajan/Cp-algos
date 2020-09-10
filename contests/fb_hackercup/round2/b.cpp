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
#define N 1000006
ll mod = 1000000007;
#define INF INT_MAX

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

ll t;
ll n;
ld p;

ld f(ll x)
{
    if (x < 0)
        return 0;
    return (x * (x - 1)) / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    freopen("input.txt", "r", stdin);
    freopen("ouput.txt", "w", stdout);
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        cin >> n >> p;
        printf("Case #%lld:\n", i);
        v<v<ld>> dp(n + 1, v<ld>(n + 1, 0));
        dp[0][0] = 0;
        for (ll i = 0; i <= n - 1; i++)
        {
            for (ll j = 0; j <= n - 1; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                ld t1 = 0, t2 = 0;
                if (i > 0)
                {
                    t1 += (i * (j + 1) + f(i)) * dp[i - 1][j];
                    t2 += f(i) * dp[i - 1][j];
                }
                if (j > 0)
                {
                    t1 += f(j) * dp[i][j - 1];
                    t2 += (f(j) + (i + 1) * j) * dp[i][j - 1];
                }
                t1 /= f(i + j + 1), t2 /= f(i + j + 1);
                t1++, t2++;
                dp[i][j] = (t1 * p + t2 * (1 - p));
                // cout << dp[i][j] << " ";
            }
            // cout << "\n";
        }
        for (ll i = 1; i <= n; i++)
            printf("%0.8Lf\n", dp[i - 1][n - i]);
    }
}
