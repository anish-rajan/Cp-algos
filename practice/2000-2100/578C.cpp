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
v<ld> a(N);
ld maxsum(ld x)
{
    for (ld i = 1; i <= n; i++)
        a[i] -= x;
    ld max_so_far1 = INT64_MIN, max_so_far2 = INT64_MIN, max_ending_here = 0;
    for (ll i = 1; i <= n; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far1 < max_ending_here)
            max_so_far1 = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    for (ll i = 1; i <= n; i++)
        a[i] = -a[i];
    max_ending_here = 0;
    for (ll i = 1; i <= n; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far2 < max_ending_here)
            max_so_far2 = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    for (ll i = 1; i <= n; i++)
        a[i] = -a[i] + x;
    if (abs(max_so_far1) > abs(max_so_far2))
        return max_so_far1;
    else
        return -1 * max_so_far2;
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
        cin >> a[i];
    ld l = -1e4 - 1, r = 1e4 + 1;
    ld del = 1e-15;
    ld ans = abs(maxsum(0));
    while (l <= r)
    {
        ld mid = (l + r) / 2;
        ld ans1 = maxsum(mid);
        // printf("%0.15Lf %0.15Lf %0.15Lf %0.15Lf\n", l, mid, r, ans1);
        ll sgn1 = ans1 > 0 ? 1 : -1;
        ans = min(ans, abs(ans1));
        if (sgn1 == -1)
            r = mid - del;
        else
            l = mid + del;
    }
    printf("%0.8Lf\n", ans);
}