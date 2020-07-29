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
#define N 500005
#define mod 1000000009
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

// v<ll> fact(N);
v<ll> prime_check(2e5 + 2);
v<ll> primes;

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

void Sieve()
{
    for (ll i = 2; i <= 2e5; i++)
    {
        if (prime_check[i])
            continue;
        primes.pb(i);
        for (ll j = 2 * i; j <= 2e5; j += i)
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

ll n, k;
v<ll> a(N);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    cin >> n >> k;
    ll s = 0;
    for (ll i = 1; i <= n; i++)
        cin >> a[i], s += a[i];
    sort(a.begin() + 1, a.begin() + n + 1);
    ll mini = s / n, maxi = s / n;
    if (s % n)
        maxi++;
    ll l = a[1], r = mini;
    ll vl = 0, vr = INF;
    while (l <= r)
    {
        ll s1 = 0;
        ll mid = (l + r) / 2;
        for (ll i = 1; i <= n; i++)
            s1 += max(0LL, mid - a[i]);
        if (s1 <= k)
            l = mid + 1, vl = max(vl, mid);
        else
            r = mid - 1;
    }
    l = maxi, r = a[n];
    while (l <= r)
    {
        ll s1 = 0;
        ll mid = (l + r) / 2;
        for (ll i = 1; i <= n; i++)
            s1 += max(0LL, a[i] - mid);
        if (s1 <= k)
            r = mid - 1, vr = min(vr, mid);
        else
            l = mid + 1;
    }
    cout << vr - vl << "\n";
}