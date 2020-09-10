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
ll mod = 1000000007;
#define INF INT_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

v<ll> fact(N);
// v<ll> prime_check(N);
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
    if (n == r)
        return 1;
    if (n < r)
        return 0;
    if (r < 0)
        return 0;
    ll temp = fact[n] * powmod(fact[r], mod - 2, mod) % mod;
    temp *= powmod(fact[n - r], mod - 2, mod);
    temp %= mod;
    return temp;
}

// void Sieve()
// {
//     for (ll i = 2; i < 1e8; i++)
//     {
//         if (prime_check[i])
//             continue;
//         primes.pb(i);
//         for (ll j = 2 * i; j < 1e8; j += i)
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

ll te;

ll mul(ll a, ll b)
{
    return (a * b) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init_fact();
    // Sieve();
    cin >> te;
    while (te--)
    {
        ll n, m;
        cin >> n >> m;
        v<ll> cnt(n + 2, 0);
        for (ll i = 2; i <= n; i++)
        {
            ll val;
            cin >> val;
            cnt[val]++;
        }
        ll ans = 1;
        ll pairs = (cnt[1] * (cnt[1] - 1)) / 2;
        for (ll i = 2; i <= n - 1; i++)
        {
            if (cnt[i] == 0)
                continue;
            if (cnt[i] > 0 && cnt[i - 1] == 0)
            {
                ans = 0;
                break;
            }
            ans = mul(ans, powmod(cnt[i - 1], cnt[i], mod));
            pairs += (cnt[i] * (cnt[i] - 1)) / 2;
        }
        if (pairs < m - n + 1)
            ans = 0;
        for (ll i = pairs - m + n; i <= pairs; i++)
        {
            ans = mul(ans, i);
        }
        ans = mul(ans, powmod(fact[m - n + 1], mod - 2, mod));
        cout << ans << "\n";
    }
}