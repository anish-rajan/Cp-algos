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
#define bit(mask, i) ((mask >> i) & 1)
#define N 64
#define mod 1000000007
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

// v<ll> fact(N);

// long long powmod(long long x, long long y, long long m)
// {
//     long long res = 1LL;
//     while (y)
//     {
//         if (y & 1)
//             res = (res * x) % m;
//         // cout << x << " " << mod << "\n";
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

// ll lcm(ll a, ll b)
// {
//     if (a == 0 || b == 0)
//         return 0;
//     return (a * b) / __gcd(a, b);
// }

/////////////////////////////////////START CODE HERE////////////////////////////////////////////

ll m, k;
v<v<ll>> C(N, v<ll>(N));

void C_calc()
{
    C[0][0] = 1;
    for (int i = 1; i <= 63; i++)
        for (int j = 0; j <= i; j++)
            C[i][j] = C[i - 1][j] + ((j) ? (C[i - 1][j - 1]) : 0);
}

int bcount(long long x)
{
    int Res = 0;
    for (; x; x &= (x - 1))
        Res++;
    return Res;
}

ll F(ll x, ll k)
{
    long long Answer = (k == bcount(x));
    for (int i = 63; i >= 0 && k >= 0; i--)
        if (bit(x, i))
            Answer += C[i][k--];
    return Answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    C_calc();
    cin >> m >> k;
    ll l = 1, r = 1000000000000000000LL;
    while (l < r)
    {
        long long mid = l + (r - l) / 2;
        // cout << F(mid * 2, k) - F(mid, k) << " " << l << " " << r << "\n";
        if (F(mid * 2, k) - F(mid, k) < m)
            l = mid + 1;
        else
            r = mid;
    }
    // cout << F(2 * l, k) - F(l, k) << "\n";
    cout << l << "\n";
}