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

ll n, m;
v<ll> a(N);
v<ll> mini(N), maxi(N), last(N);

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

    S search(S sum) // for finding sumth number if arranged in ascending order.
    {
        S x = 0;
        for (S i = 22; i >= 0; i--)
        {
            S newX = x + (1 << i);
            if (newX <= n && sum > bit[newX])
            {
                x = newX;
                sum -= bit[x];
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n >> m;
    FenwickTree ft1(m), ft2(n);
    for (ll i = 1; i <= m; i++)
        cin >> a[i];
    for (ll i = 1; i <= n; i++)
        mini[i] = maxi[i] = i;
    for (ll i = 1; i <= m; i++)
    {
        mini[a[i]] = 1;
        if (!last[a[i]])
        {
            maxi[a[i]] += ft2.sum(a[i] + 1, n);
            ft2.add(a[i], 1);
            ft1.add(i, 1);
            last[a[i]] = i;
        }
        else
        {
            ft1.add(last[a[i]], -1);
            maxi[a[i]] = max(maxi[a[i]], ft1.sum(last[a[i]] + 1, i - 1) + 1);
            ft1.add(i, 1);
            last[a[i]] = i;
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        if (last[i])
            maxi[i] = max(maxi[i], ft1.sum(last[i] + 1, m) + 1);
        else
            maxi[i] += ft2.sum(i + 1, n);
    }
    for (ll i = 1; i <= n; i++)
        cout << mini[i] << " " << maxi[i] << "\n";
}
