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
#define mod 1000000007
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

// v<ll> fact(N);
// v<ll> prime_check(1e6 + 2);
// v<ll> primes;

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

// void Sieve()
// {
//     for (ll i = 2; i <= 1e6 + 1; i++)
//     {
//         if (prime_check[i])
//             continue;
//         primes.pb(i);
//         for (ll j = 2 * i; j <= 1e6 + 2; j += i)
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

ll n, m, x, y, k;
v<ll> a(N), b(N);
map<ll, ll> ind;

ll cmp1(ll len)
{
    ll ans = INF;
    ans = min(ans, y * (len % k) + x * (len / k));
    if (len / k > 0)
        ans = min(ans, x + y * (len - k));
    return ans;
}

ll cmp(ll i, ll j, ll c, ll d)
{
    if (i > j)
        return 0;
    ll ans = INF;
    ll len = j - i + 1;
    ll maxi = -1;
    for (ll l = i; l <= j; l++)
        maxi = max(maxi, a[l]);
    if (len < k && maxi > max(c, d))
        return -1;
    ans = min(ans, cmp1(len));
    if (maxi <= max(c, d))
        ans = min(ans, y * len);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n >> m >> x >> k >> y;
    for (ll i = 1; i <= n; i++)
        cin >> a[i], ind[a[i]] = i;
    ll f = 1;
    for (ll i = 1; i <= m; i++)
    {
        cin >> b[i];
        if (ind.find(b[i]) == ind.end())
            f = 0;
    }
    ll ans = 0;
    auto temp = cmp(1, ind[b[1]] - 1, 0, b[1]);
    if (temp == -1)
        f = 0;
    else
        ans += temp;
    for (ll i = 1; i < m; i++)
    {
        ll i1 = ind[b[i]], i2 = ind[b[i + 1]];
        if (i2 < i1)
            f = 0;
        temp = cmp(i1 + 1, i2 - 1, b[i], b[i + 1]);
        if (temp == -1)
            f = 0;
        else
            ans += temp;
    }
    temp = cmp(ind[b[m]] + 1, n, b[m], 0);
    if (temp == -1)
        f = 0;
    else
        ans += temp;
    if (f == 0)
        cout << -1 << "\n";
    else
        cout << ans << "\n";
}
