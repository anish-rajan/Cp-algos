#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
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
#define N 210
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

v<v<v<ll>>> dp(N, v<v<ll>>(N, v<ll>(N, -INF)));

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    ll n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    dp[0][0][0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j <= k; j++)
        {
            for (ll l = 0; l <= n; l++)
            {
                if (s[i - 1] == t[0])
                    dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j][l - 1] + (t[0] == t[1] ? l - 1 : 0));
                else if (s[i - 1] == t[1])
                    dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j][l] + l);
                else
                    dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j][l]);
                if (l - 1 >= 0 && j - 1 >= 0 && dp[i][j][l] <= dp[i - 1][j - 1][l - 1] + (t[0] == t[1] ? l - 1 : 0))
                    dp[i][j][l] = dp[i - 1][j - 1][l - 1] + (t[0] == t[1] ? l - 1 : 0);
                if (j - 1 >= 0 && dp[i][j][l] <= dp[i - 1][j - 1][l] + l)
                    dp[i][j][l] = dp[i - 1][j - 1][l] + l;
            }
        }
    }
    ll ans = 0;
    for (ll i = 0; i <= k; i++)
        for (ll j = 0; j <= n; j++)
            ans = max(ans, dp[n][i][j]);
    cout << ans << "\n";
}
