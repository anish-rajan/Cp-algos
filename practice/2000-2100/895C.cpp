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
#define INF 1e15

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

// v<ll> fact(N);
v<ll> prime_check(73);
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

void Sieve()
{
    for (ll i = 2; i <= 70; i++)
    {
        if (prime_check[i])
            continue;
        primes.pb(i);
        for (ll j = 2 * i; j <= 70; j += i)
            prime_check[j] = i;
    }
}
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

//////DEQUE SOLUTION/////

ll n;
v<ll> a(N), dp(N), cnt(71), pow2(N);
v<ll> ind(71);

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
    Sieve();
    ll index = 0;
    for (auto x : primes)
    {
        ind[x] = index++;
    }
    pow2[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        pow2[i] = mul(pow2[i - 1], 2);
    }
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i], cnt[a[i]]++;
    dp[0] = 1;
    for (ll i = 2; i <= 70; i++)
    {
        ll no = 0;
        for (ll j = 0; j < primes.size() && primes[j] <= 70; j++)
        {
            ll count = 0, temp = i;
            while (temp % primes[j] == 0)
                count++, temp /= primes[j];
            if (count % 2)
                no |= (1LL << ind[primes[j]]);
        }
        if (cnt[i] > 0)
        {
            v<ll> dp1(N);
            for (ll j = 0; j < (1LL << 19); j++)
            {
                if (no > 0)
                {
                    dp1[j ^ no] = (dp1[j ^ no] + mul(pow2[cnt[i] - 1], dp[j])) % mod;
                    dp1[j] = (dp1[j] + mul(pow2[cnt[i] - 1], dp[j])) % mod;
                }
                else
                    dp1[j] = (dp1[j] + mul(pow2[cnt[i]], dp[j])) % mod;
            }
            dp = dp1;
        }
    }
    dp[0] = (mul(pow2[cnt[1]], dp[0])) % mod;
    dp[0] = (dp[0] - 1 + mod) % mod;
    cout << dp[0] << "\n";
}
