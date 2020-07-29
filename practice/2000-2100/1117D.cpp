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
#define N 400005
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

ll n, m;

const ll MAT = 101;
struct Mat
{
    ll v[MAT][MAT];
    Mat() { memset(v, 0, sizeof(v)); };
};
ll mo = mod;

Mat mulmat(Mat &a, Mat &b, ll n = MAT)
{
    ll mo2 = 4 * mo * mo;
    ll x, y, z;
    Mat r;
    for (x = 0; x < n; x++)
        for (y = 0; y < n; y++)
            r.v[x][y] = 0;
    for (x = 0; x < n; x++)
        for (z = 0; z < n; z++)
            for (y = 0; y < n; y++)
            {
                r.v[x][y] += a.v[x][z] * b.v[z][y];
                if (r.v[x][y] > mo2)
                    r.v[x][y] -= mo2;
            }
    for (x = 0; x < n; x++)
        for (y = 0; y < n; y++)
            r.v[x][y] %= mo;
    return r;
}

Mat powmat(ll p, Mat a, ll n = MAT)
{
    ll i, x, y;
    Mat r;
    for (x = 0; x < n; x++)
        for (y = 0; y < n; y++)
            r.v[x][y] = 0;
    for (i = 0; i < n; i++)
        r.v[i][i] = 1;
    while (p)
    {
        if (p % 2)
            r = mulmat(r, a, n);
        a = mulmat(a, a, n);
        p >>= 1LL;
    }
    return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n >> m;
    Mat A;
    A.v[0][m - 1] = A.v[m - 1][m - 1] = 1;
    for (ll i = 1; i < m; i++)
        A.v[i][i - 1] = 1;
    Mat B = powmat(n, A, m);
    ll ans = 0;
    // for (ll i = 0; i < m; i++)
    // {
    //     for (ll j = 0; j < m; j++)
    //         cout << B.v[i][j] << " ";
    //     cout << "\n";
    // }
    for (ll i = 0; i < m; i++)
        ans = (ans + B.v[i][0]) % mod;
    cout << ans << "\n";
}