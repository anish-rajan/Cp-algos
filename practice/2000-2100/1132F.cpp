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
#define N 505
#define mod 1000000007
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

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
string s;
v<v<ll>> dp(N, v<ll>(N, INF));

ll d(ll i, ll j)
{
    if (j < i)
        return 0;
    else
        return dp[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n;
    cin >> s;
    for (ll i = 0; i < n; i++)
    {
        dp[i][i] = 1;
        if (i >= 1)
        {
            dp[i - 1][i] = s[i] == s[i - 1] ? 1 : 2;
            // cout << i << " " << dp[i - 1][i] << " ";
        }
    }
    for (ll i = 3; i <= n; i++)
    {
        for (ll j = 0; j + i - 1 < n; j++)
        {
            dp[j][j + i - 1] = d(j, j + i - 2) + 1;
            for (ll k = j; k < j + i - 1; k++)
            {
                if (s[j + i - 1] == s[k])
                {
                    dp[j][j + i - 1] = min(dp[j][j + i - 1], d(j, k) + d(k + 1, j + i - 2));
                }
            }
        }
    }
    cout << dp[0][n - 1] << "\n";
}