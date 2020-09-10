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

ll n, t, k, al, bl, cl, dl, aw, bw, cw, dw, ah, bh, ch, dh, p;

ll mul(ll a, ll b, ll m)
{
    return (a * b) % m;
}
v<ll> start, height, width;
set<pair<ll, ll>> a;

void insert(ll st, ll h, ll w)
{
    auto itr = a.lower_bound(mp(st, -INF));
    if (itr != a.begin())
    {
        itr--;
        if (itr->se < st)
            itr++;
    }
    if (a.size() == 0 || itr == a.end() || itr->fi > st + w)
    {
        a.insert(mp(st, st + w));
        p = (p + 2 * (w + h)) % mod;
        return;
    }
    pair<ll, ll> sti = *itr, eni = sti;
    ll no = 0, maxc = sti.fi;
    p = (p + 2 * max(0LL, sti.fi - st)) % mod;
    auto itr1 = itr;
    while (itr1 != a.end() && itr1->fi <= st + w)
    {
        auto itr2 = itr1;
        eni = *itr1;
        p = (p + 2 * (eni.fi - maxc)) % mod;
        // cout << eni.fi << " " << eni.se << " " << maxc << " " << p << "\n";
        maxc = itr1->se;
        no++;
        itr1++;
        if (itr1 == a.end())
        {
            a.erase(itr2);
            break;
        }
        a.erase(itr2);
    }
    p = (p + 2 * max(0LL, st + w - eni.se)) % mod;
    p = (p - (no - 1) * (2 * h) + 2 * mod * (no - 1)) % mod;
    a.insert(mp(min(sti.fi, st), max(eni.se, st + w)));
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
        cin >> n >> k;
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
            width.pb(val);
        }
        cin >> aw >> bw >> cw >> dw;
        for (ll i = 1; i <= k; i++)
        {
            ll val;
            cin >> val;
            height.pb(val);
        }
        cin >> ah >> bh >> ch >> dh;
        for (ll i = 0; i < k; i++)
        {
            insert(start[i], height[i], width[i]);
            // cout << start[i] << " " << height[i] << " " << width[i] << " " << p << "\n";
            ans = mul(ans, p, mod);
        }
        for (ll i = k; i < n; i++)
        {
            ll st = (mul(al, start[i - 2], dl) + mul(bl, start[i - 1], dl) + cl) % dl + 1;
            ll w = (mul(aw, width[i - 2], dw) + mul(bw, width[i - 1], dw) + cw) % dw + 1;
            ll h = (mul(ah, height[i - 2], dh) + mul(bh, height[i - 1], dh) + ch) % dh + 1;
            insert(st, h, w);
            // cout << st << " " << h << " " << p << "\n";
            start.pb(st), height.pb(h), width.pb(w);
            ans = mul(ans, p, mod);
        }
        cout << "Case #" << i << ": " << ans << "\n";
        a.clear(), start.clear(), height.clear(), width.clear(), p = 0;
    }
}
