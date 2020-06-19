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
#define N 102
#define mod 1000000007
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

v<ll> fact(N);
v<ll> prime_check(1e7 + 2);
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

void init_fact()
{
    fact[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

ll C(ll n, ll r)
{
    if (n < r)
        return 0;
    ll temp = fact[n] * powmod(fact[r], mod - 2, mod) % mod;
    temp *= powmod(fact[n - r], mod - 2, mod);
    temp %= mod;
    return temp;
}

void Sieve()
{
    for (ll i = 2; i <= 1e7 + 1; i++)
    {
        if (prime_check[i])
            continue;
        primes.pb(i);
        for (ll j = 2 * i; j <= 1e7 + 1; j += i)
            prime_check[j] = i;
    }
}
ll phi(ll n)
{
    ll i, res = n;
    for (i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            res -= res / i;
        }
    if (n > 1)
        res -= res / n;
    return res;
}

/////////////////////////////////////START CODE HERE/////////////////////////////////////////////

ll n;
v<ll> a(N);
v<ll> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
v<ll> mask(64), ans(N);
v<v<ll>> rec(N, v<ll>(1 << 16, INF)), dp(N, v<ll>(1 << 16, INF));

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    for (ll i = 1; i <= 60; i++)
    {
        for (ll j = 0; j < p.size(); j++)
        {
            if (i % p[j] == 0)
                mask[i] |= (1 << j);
        }
    }
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    dp[0][0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j < (1 << 16); j++)
        {
            for (ll k = 1; k <= 58; k++)
            {
                if (dp[i - 1][j] != INF && (mask[k] & j) == 0)
                {
                    ll d = abs(a[i] - k);
                    if (dp[i][j | mask[k]] > dp[i - 1][j] + d)
                    {
                        dp[i][j | mask[k]] = dp[i - 1][j] + d;
                        rec[i][j | mask[k]] = k;
                    }
                }
            }
        }
    }
    ll ans1 = INF, no = 0;
    for (ll j = 0; j < (1 << 16); j++)
    {
        if (ans1 > dp[n][j])
            ans1 = dp[n][j], no = j;
    }
    // cout << no << "\n";
    for (ll i = n; i >= 1; i--)
        ans[i] = rec[i][no], no ^= mask[ans[i]];
    for (ll i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}