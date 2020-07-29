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

ll t;
v<ll> dp(N), dp1(N), cum(N), cum1(N);
ll terms;

ll var = powmod(6, mod - 2, mod);

ll mul(ll a, ll b)
{
    return (a * b) % mod;
}

ll cmp1(ll l, ll r)
{
    if (r < l)
        return 0;
    ll ans = 0;
    ans = mul(mul(mul(r, r + 1), 2 * r + 1), var);
    ll ans2 = mul(mul(mul(l - 1, l), 2 * l - 1), var);
    // cout << ans << " " << ans2 << "\n";
    ans = (ans - ans2 + mod) % mod;
    return ans;
}

ll cmp(ll x)
{
    if (x == 0)
        return 0;
    ll no = 0;
    ll ans = 0;
    auto i = upper_bound(cum.begin(), cum.begin() + terms + 1, x) - cum.begin();
    i--;
    no = cum[i];
    ans = cum1[i++];
    ll diff = x - no;
    ll t1 = diff / i, t2 = diff % i;
    ans = (ans + (cmp1(dp1[i], dp1[i] + t1 - 1) * i) % mod) % mod;
    ans = (ans + (cmp1(dp1[i] + t1, dp1[i] + t1) * t2) % mod) % mod;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    dp[1] = 1, dp1[1] = 1, cum[1] = 1, cum1[1] = 1;
    ll ans = 1;
    for (ll i = 2; i <= dp.size() && cum[i - 1] <= 1e10; i++)
    {
        dp[i] = 1 + dp[i - dp[dp[i - 1]]];
        terms++;
        cum[i] = cum[i - 1] + dp[i] * i;
        dp1[i] = dp[i - 1] + dp1[i - 1];
        ans = (ans + (cmp1(dp1[i], dp1[i] + dp[i] - 1) * i) % mod) % mod;
        cum1[i] = ans;
    }
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        cout << (cmp(r) - cmp(l - 1) + mod) % mod << "\n";
    }
}