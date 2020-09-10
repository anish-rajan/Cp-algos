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

ll n, m;
string s;
v<v<ll>> dp(N, v<ll>(2 * N));

ll mul(ll a, ll b)
{
    return (a * b) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n >> m;
    string s;
    cin >> s;
    dp[0][0] = 1;
    for (ll i = 1; i <= n - m; i++)
    {
        dp[i][0] = dp[i - 1][1];
        for (ll j = 1; j <= i; j++)
        {
            dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1]) % mod;
        }
    }
    ll ans = 0, bals = 0, minbalp = INF;
    for (auto x : s)
    {
        if (x == '(')
            bals++;
        else
            bals--;
        minbalp = min(minbalp, bals);
    }
    minbalp = -minbalp;
    for (ll i = 0; i <= n - m; i++)
    {
        for (ll j = max(minbalp, 0LL); j <= i; j++)
        {
            ll balp = j, balq = abs(j + bals);
            if (balq <= 2000)
                ans = (ans + mul(dp[i][j], dp[n - m - i][balq])) % mod;
            // cout << i << " " << j << " " << n - m - i << " " << balq << " " << dp[i][j] << " " << dp[n - m - i][balq] << "\n";
        }
    }
    cout << ans << "\n";
}
