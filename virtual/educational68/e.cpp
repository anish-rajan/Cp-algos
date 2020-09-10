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
#define N 5005
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

ll n;
ll off = 5001;

struct Seg
{
    ll x1, y1, x2, y2;
    bool operator<(Seg other) const
    {
        if (y1 == y2)
            return y1 < other.y1;
        else
            return y2 > other.y2;
    }
};

v<Seg> hori, verti;

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
        return qry(r) - qry(l - 1);
    }

    void add(S idx, S delta)
    {
        for (; idx <= n; idx += idx & (-idx))
            bit[idx] += delta;
    }
};

pair<ll, ll> inter(Seg a, Seg b)
{
    if (a.x1 > b.x1)
        return inter(b, a);
    return mp(b.x1, min(a.x2, b.x2));
}

long long int C2(long long int x)
{
    return (x * (x - 1)) / 2;
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
        ll x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2)
        {
            if (y1 > y2)
                swap(y1, y2);
            verti.pb({x1, y1, x2, y2});
        }
        else
        {
            if (x1 > x2)
                swap(x1, x2);
            hori.pb({x1, y1, x2, y2});
        }
    }
    sort(ALL(verti));
    sort(ALL(hori));
    ll st = 0, en = 2 * N - 1;
    long long int ans = 0;
    FenwickTree ft(en + 1);
    for (ll i = 0; i < hori.size(); i++)
    {
        ll k = 0;
        for (auto x : verti)
        {
            ll temp = ft.sum(x.x1 + off, x.x1 + off);
            ft.add(x.x1 + off, -1 * temp);
        }
        for (ll j = hori.size() - 1; j >= i + 1; j--)
        {
            while (k < verti.size() && verti[k].y2 >= hori[j].y2)
            {
                if (verti[k].y1 <= hori[i].y2)
                    ft.add(verti[k].x1 + off, 1);
                k++;
            }
            if (hori[i].x1 > hori[j].x2 || hori[j].x1 > hori[i].x2)
                continue;
            auto temp = inter(hori[i], hori[j]);
            ans += C2(ft.sum(temp.fi + off, temp.se + off));
        }
    }
    cout << ans << "\n";
}
