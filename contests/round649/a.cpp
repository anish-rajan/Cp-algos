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
#define N 100005
#define mod 1000000007
#define INF INT_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

v<ll> fact(N);
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
        ll n, x;
        cin >> n >> x;
        v<ll> a(n + 1), pre(n + 1, 0);
        ll i1 = 0, i2 = 0, i3 = n + 1, i4 = n + 1;
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
            if (pre[i] % x == 0)
                i1 = max(i1, i), i3 = min(i3, i);
            else
                i2 = max(i2, i), i4 = min(i4, i);
        }
        ll ans = i2;
        if (i1 && i4)
            ans = max(i1 - i4, ans);
        if (i2 && i3)
            ans = max(ans, i2 - i3);
        if (ans == 0)
            cout << -1 << "\n";
        else
            cout << ans << "\n";
    }
}