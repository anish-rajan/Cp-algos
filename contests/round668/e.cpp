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
#define N 300005
ll mod = 1000000007;
#define INF INT64_MAX

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

ll n, q;
v<ll> a(N);
v<pair<pair<ll, ll>, ll>> queries(N);
v<ll> ans(N);

using S = ll;

struct FenwickTree
{
    vector<S> bit; // binary indexed tree
    S n;
    S LOGN;

    FenwickTree(S n)
    {
        this->n = n;
        bit.assign(n + 1, 0);
        LOGN = log2(n);
    }

    S bit_search(S v, S r)
    {
        S sum = 0;
        S pos = 0;

        for (S i = LOGN; i >= 0; i--)
        {
            if (pos + (1 << i) <= r && sum + bit[pos + (1 << i)] >= v)
            {
                sum += bit[pos + (1 << i)];
                pos += (1 << i);
            }
        }

        return pos; // +1 because 'pos' will have position of largest value less than 'v'
    }

    S qry(S r)
    {
        S ret = 0;
        for (; r >= 1; r -= r & (-r))
            ret += bit[r];
        return ret;
    }

    void add(S idx, S delta)
    {
        for (; idx <= n; idx += idx & (-idx))
            bit[idx] += delta;
    }

    void add_r(S l, S r, S delta)
    {
        if (r < l)
            return;
        add(l, delta), add(r + 1, -delta);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n >> q;
    for (ll i = 1; i <= n; i++)
        cin >> a[i], a[i] = i - a[i];
    for (ll i = 1; i <= q; i++)
    {
        ll x, y;
        cin >> x >> y;
        queries[i] = mp(mp(1 + x, n - y), i);
    }
    sort(queries.begin() + 1, queries.begin() + q + 1, [](auto a, auto b) {
        return a.fi.se < b.fi.se;
    });
    FenwickTree ft(n);
    ll j = 1;
    for (ll i = 1; i <= n; i++)
    {
        ll pos = 0;
        if (a[i] >= 0)
            pos = ft.bit_search(a[i], i);
        ft.add_r(1, pos, 1);
        while (j <= q && queries[j].fi.se == i)
        {
            ans[queries[j].se] = ft.qry(queries[j].fi.fi);
            j++;
        }
    }
    for (ll i = 1; i <= q; i++)
        cout << ans[i] << "\n";
}
