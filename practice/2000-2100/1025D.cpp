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
#define N 707
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
v<ll> a(N);
v<v<v<ll>>> dp(N, v<v<ll>>(N, v<ll>(2)));
v<v<ll>> dp1(N, v<ll>(N));

ll cmp(ll a, ll b)
{
    if (__gcd(a, b) > 1)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i], dp[i][i][0] = 1, dp[i][i][1] = 1;
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= n; j++)
            dp1[i][j] = cmp(a[i], a[j]);
    for (ll i = 2; i <= n; i++)
    {
        for (ll j = 1; j + i - 1 <= n; j++)
        {
            ll l = j, r = j + i - 1;
            for (ll k = l + 1; k <= r; k++)
            {
                dp[l][r][0] = max(dp[l][r][0], dp[l + 1][k][1] & dp[k][r][0] & dp1[l][k]);
            }
            for (ll k = l; k < r; k++)
            {
                dp[l][r][1] = max(dp[l][r][1], dp[l][k][1] & dp[k][r - 1][0] & dp1[r][k]);
            }
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        ans = max(ans, dp[1][i][1] & dp[i][n][0]);
    }
    if (ans == 1)
        cout << "Yes\n";
    else
        cout << "No\n";
}
