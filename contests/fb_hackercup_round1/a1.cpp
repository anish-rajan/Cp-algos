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

ll n, t, k, w, al, bl, cl, dl, ah, bh, ch, dh, p;
struct Interval
{
    ll l, r, h;
};
v<Interval> a;
v<ll> start, height;

ll mul(ll a, ll b, ll m)
{
    return (a * b) % m;
}

void insert(ll st, ll h)
{
    while (a.size() > 0 && st <= a.back().l && h >= a.back().h)
    {
        p = (p - 2 * (a.back().r - a.back().l) - a.back().h + 5 * mod) % mod;
        ll ind = a.size() - 2;
        if (ind >= 0 && a.back().l <= a[ind].r)
            p = (p + min(a.back().h, a[ind].h) - max(0LL, a.back().h - a[ind].h) + 5 * mod) % mod;
        else
            p = (p - a.back().h + 5 * mod) % mod;
        a.pop_back();
    }
    if (a.size() > 0)
    {
        ll l1 = a.back().l, r1 = a.back().r, h1 = a.back().h;
        if (st > l1 && st <= r1)
        {
            if (h1 > h)
            {
                a.pb({r1, st + w, h});
                p = (p + 2 * (st + w - r1) + 5 * mod) % mod;
            }
            else
            {
                a.pop_back();
                a.pb({l1, st, h1});
                a.pb({st, st + w, h});
                p = (p + 2 * (h - h1) + 2 * (st + w - r1) + 5 * mod) % mod;
            }
        }
        else if (st > l1)
        {
            a.pb({st, st + w, h});
            p = (p + 2 * (w + h)) % mod;
        }
        else
        {
            a.pb({r1, st + w, h});
            p = (p + 2 * (st + w - r1) + 5 * mod) % mod;
        }
    }
    else
    {
        a.pb({st, st + w, h});
        p = (p + 2 * (w + h)) % mod;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    freopen("test.txt", "r", stdin);
    freopen("ouput.txt", "w", stdout);
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        cin >> n >> k >> w;
        ll ans = 1;
        for (ll i = 1; i <= k; i++)
        {
            ll val;
            cin >> val;
            start.pb(val);
        }
        cin >> al >> bl >> cl >> dl;
        for (ll i = 1; i <= k; i++)
        {
            ll val;
            cin >> val;
            height.pb(val);
        }
        cin >> ah >> bh >> ch >> dh;
        for (ll i = 0; i < k; i++)
        {
            insert(start[i], height[i]);
            // cout << start[i] << " " << height[i] << " " << p << "\n";
            ans = mul(ans, p, mod);
        }
        for (ll i = k; i < n; i++)
        {
            ll st = (mul(al, start[i - 2], dl) + mul(bl, start[i - 1], dl) + cl) % dl + 1;
            ll h = (mul(ah, height[i - 2], dh) + mul(bh, height[i - 1], dh) + ch) % dh + 1;
            insert(st, h);
            // cout << st << " " << h << " " << p << "\n";
            start.pb(st), height.pb(h);
            ans = mul(ans, p, mod);
        }
        cout << "Case #" << i << ": " << ans << "\n";
        a.clear(), start.clear(), height.clear(), p = 0;
    }
}
