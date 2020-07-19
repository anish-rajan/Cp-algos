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
#define N 200005
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

ll n;
v<ll> x(N), y(N);
v<ll> f, s, t, e;

pair<ld, ld> comp(ll x1, ll y1, ll x2, ll y2)
{
    ld m = (y2 - y1 * 1.0) / (x2 - x1);
    ld c = y2 - m * x2;
    return mp(m, c);
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
        cin >> x[i] >> y[i];
    if (n <= 4)
    {
        cout << "YES\n";
        return 0;
    }
    ll pos = 0;
    for (ll i = 2; i <= 4; i++)
    {
        auto par = comp(x[1], y[1], x[i], y[i]);
        pair<ld, ld> temp;
        ll ind, pos1 = 1;
        if (i == 2)
            temp = comp(x[3], y[3], x[4], y[4]), ind = 3;
        else if (i == 3)
            temp = comp(x[4], y[4], x[2], y[2]), ind = 4;
        else
            temp = comp(x[2], y[2], x[3], y[3]), ind = 2;
        for (ll i = 5; i <= n; i++)
        {
            auto temp1 = comp(x[ind], y[ind], x[i], y[i]);
            auto temp2 = comp(x[1], y[1], x[i], y[i]);
            if (temp1 == temp || temp2 == par)
                continue;
            else
                pos1 = 0;
        }
        if (pos1 == 1)
            pos = 1;
    }
    if (pos == 1)
        cout << "YES\n";
    else
        cout << "NO\n";
}