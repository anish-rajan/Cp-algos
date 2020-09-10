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
#define N 1000006
ll mod = 1000000007;
#define INF INT_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

// v<ll> fact(N);
// v<ll> prime_check(N);
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

ll t;
ll n, k, as, bs, cs, ds, ax, bx, cx, dx, ay, by, cy, dy;
v<ll> s, x, y;

ll mul(ll a, ll b, ll mod)
{
    return (a * b) % mod;
}

ll solve()
{
    ll ex = 0, lt = 0;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] > x[i] + y[i])
            ex += s[i] - x[i] - y[i];
        else if (s[i] < x[i])
            lt += x[i] - s[i];
    }
    if (ex > lt)
    {
        ex -= lt;
        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] <= x[i] + y[i])
                sum += min(x[i] + y[i] - s[i], y[i]);
        }
        if (ex <= sum)
            return ex + lt;
        return -1;
    }
    else
    {
        lt -= ex;
        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] >= x[i])
                sum += min(s[i] - x[i], y[i]);
        }
        if (lt <= sum)
            return ex + lt;
        return -1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    freopen("input.txt", "r", stdin);
    freopen("ouput.txt", "w", stdout);
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        cin >> n >> k;
        for (ll i = 0; i < k; i++)
        {
            ll val;
            cin >> val;
            s.pb(val);
        }
        cin >> as >> bs >> cs >> ds;
        for (ll i = 0; i < k; i++)
        {
            ll val;
            cin >> val;
            x.pb(val);
        }
        cin >> ax >> bx >> cx >> dx;
        for (ll i = 0; i < k; i++)
        {
            ll val;
            cin >> val;
            y.pb(val);
        }
        cin >> ay >> by >> cy >> dy;
        for (ll i = k; i < n; i++)
        {
            s.pb((mul(as, s[i - 2], ds) + mul(bs, s[i - 1], ds) + cs) % ds);
            x.pb((mul(ax, x[i - 2], dx) + mul(bx, x[i - 1], dx) + cx) % dx);
            y.pb((mul(ay, y[i - 2], dy) + mul(by, y[i - 1], dy) + cy) % dy);
        }
        ll ans = solve();
        cout << "Case #" << i << ": " << ans << "\n";
        s.clear(), x.clear(), y.clear();
    }
}
