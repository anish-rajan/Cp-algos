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
#define INF 1e15

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

//////DEQUE SOLUTION/////

ll n, s, l;
v<ll> a(N);
v<ll> f(N, INF), g(N);
deque<pair<ll, ll>> m, mx;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n >> s >> l;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    ll p = 0;
    m.pb(mp(0, 0));
    mx.pb(mp(0, 0));
    for (ll i = 1; i <= n; i++)
    {
        while (!m.empty() && m.back().fi >= a[i])
            m.pop_back();
        m.pb(mp(a[i], i));
        while (!mx.empty() && mx.back().fi <= a[i])
            mx.pop_back();
        mx.pb(mp(a[i], i));
        while (!mx.empty() && !m.empty() && mx.front().fi - m.front().fi > s)
        {
            p++;
            if (mx.front().se < p)
                mx.pop_front();
            if (m.front().se < p)
                m.pop_front();
        }
        g[i] = p;
        // cout << g[i] << " ";
    }
    // cout << "\n";
    m = deque<pair<ll, ll>>();
    ll pos = 1;
    f[0] = 0;
    for (ll i = l; i <= n; i++)
    {
        while (!m.empty() && m.back().fi >= f[i - l])
            m.pop_back();
        m.pb(mp(f[i - l], i - l));
        while (!m.empty() && m.front().se < g[i] - 1)
            m.pop_front();
        if (!m.empty())
            f[i] = m.front().fi + 1;
        // cout << i << " " << m.front().fi << " " << f[i] << " \n";
    }
    // cout << "\n";
    if (f[n] < INF)
        cout << f[n] << "\n";
    else
        cout << -1 << "\n";
}
