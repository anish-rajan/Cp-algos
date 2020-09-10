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

ll n, fs, ls;
v<pair<ll, ll>> query(N);
v<ll> nos;

using S = ll;

struct FenwickTree
{
    vector<S> bit; // binary indexed tree
    S n;

    FenwickTree(S n)
    {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    S search(S s) // for finding sumth number if arranged in ascending order.
    {
        S x = 0;
        for (S i = 22; i >= 0; i--)
        {
            S newX = x + (1 << i);
            if (newX <= n && s > bit[newX])
            {
                x = newX;
                s -= bit[x];
            }
        }
        return x + 1;
    }

    S qry(S r)
    {
        S ret = 0;
        for (; r >= 1; r -= r & (-r))
            ret += bit[r];
        return ret;
    }

    S sum(S l, S r)
    {
        if (r < l)
            return 0;
        return qry(r) - qry(l - 1);
    }

    void add(S idx, S delta)
    {
        for (; idx <= n; idx += idx & (-idx))
            bit[idx] += delta;
    }
};

ll findidx(ll no)
{
    auto ind = lower_bound(nos.begin(), nos.end(), no) - nos.begin();
    return ind + 1;
}

ll comp(FenwickTree &ft1, FenwickTree &ft2, FenwickTree &ft3, FenwickTree &ft4)
{
    ll l = 1, r = min(fs, ls), ind = 1, ans = 0;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        ll p1 = ft1.search(fs - mid + 1);
        ll p2 = ft2.search(mid);
        if (p2 <= p1)
            l = mid + 1, ind = max(ind, mid);
        else
            r = mid - 1;
    }
    ll p1 = ft1.search(fs - ind + 1), p2 = ft2.search(ind);
    if (ls > 0)
        ans = 2 * ft3.sum(p1, nos.size()) + ft3.sum(1, p1 - 1) + ft4.sum(1, p2) + 2 * ft4.sum(p2 + 1, nos.size());
    else
        ans += ft3.sum(1, nos.size());
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> query[i].fi >> query[i].se;
        if (query[i].se > 0)
            nos.pb(query[i].se);
    }
    UN(nos);
    FenwickTree ft1(nos.size() + 1), ft2(nos.size() + 1), ft3(nos.size() + 1), ft4(nos.size() + 1);
    for (ll i = 1; i <= n; i++)
    {
        ll x = query[i].fi, y = query[i].se;
        if (x == 0)
        {
            if (y > 0)
                ft1.add(findidx(y), 1), ft3.add(findidx(y), y), fs++;
            else
                ft1.add(findidx(-y), -1), ft3.add(findidx(-y), y), fs--;
        }
        else
        {
            if (y > 0)
                ft2.add(findidx(y), 1), ft4.add(findidx(y), y), ls++;
            else
                ft2.add(findidx(-y), -1), ft4.add(findidx(-y), y), ls--;
        }
        ll ans = comp(ft1, ft2, ft3, ft4);
        cout << ans << "\n";
    }
}
