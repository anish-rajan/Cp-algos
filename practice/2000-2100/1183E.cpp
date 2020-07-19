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
#define N 105
#define mod 1000000009
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

ll n, k;
v<v<ll>> dp(N, v<ll>(N));
v<ll> last(3 * N, -1), p(N), sum(N);
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n >> k;
    cin >> s;
    for (ll i = 0; i < n; i++)
    {
        p[i] = last[s[i]];
        if (last[s[i]] == -1)
            dp[i][1] = 1;
        last[s[i]] = i;
    }
    for (ll i = 0; i < n; i++)
        sum[1] += dp[i][1];
    for (ll i = 2; i <= n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            for (ll k = max(p[j], 0LL); k < j; k++)
            {
                dp[j][i] += dp[k][i - 1];
            }
            sum[i] += dp[j][i];
        }
    }
    ll ans = 0;
    sum[0] = 1;
    for (ll i = n; i >= 0 && k > 0; i--)
    {
        if (sum[i] <= k)
        {
            k -= sum[i];
            ans += (n - i) * sum[i];
        }
        else
        {
            ans += (k) * (n - i);
            k = 0;
        }
    }
    if (k <= 0)
        cout << ans << "\n";
    else
        cout << -1 << '\n';
}