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
#define mod 1000000009
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

v<ll> fact(N);
v<ll> prime_check(1e6 + 2);
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
    for (ll i = 2; i <= 1e6 + 1; i++)
    {
        if (prime_check[i])
            continue;
        primes.pb(i);
        for (ll j = 2 * i; j <= 1e6 + 2; j += i)
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

ll t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        v<ll> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0), d(n + 1, 0);
        ll ans = 0;
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (i % 2)
                ans += a[i];
        }
        b[1] = a[1], d[1] = -b[1];
        for (ll i = 2; i <= n; i++)
        {
            if (i % 2)
                b[i] = b[i - 1] + a[i], c[i] = c[i - 1];
            else
                c[i] = c[i - 1] + a[i], b[i] = b[i - 1];
            d[i] = c[i] - b[i];
        }
        ll diff = 0;
        ll mino = d[1], mine = 0;
        for (ll i = 2; i <= n; i++)
        {
            // cout << d[i] << " " << diff << "\n";
            if (i % 2)
                diff = max(diff, d[i] - mino), mino = min(mino, d[i]);
            else
                diff = max(diff, d[i] - mine), mine = min(mine, d[i]);
        }
        cout << ans + diff << "\n";
    }
}