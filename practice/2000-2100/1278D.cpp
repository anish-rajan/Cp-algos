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
#define N 500005
#define mod 1000000009
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

ll n;
v<pair<pair<ll, ll>, ll>> a(N);
set<pair<ll, ll>> nos;
v<v<ll>> adj(N);
v<ll> visited(N);

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

void dfs(ll u)
{
    visited[u] = 1;
    for (auto x : adj[u])
        if (!visited[x])
            dfs(x);
    // cout << u << " ";
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
        cin >> a[i].fi.fi >> a[i].fi.se, a[i].se = i;
    sort(a.begin() + 1, a.begin() + n + 1);
    FenwickTree ft(2 * n);
    ll ed = 0;
    for (ll i = 1; i <= n;)
    {
        ll j = i;
        while (j <= n && a[j] == a[i])
        {
            ll temp = ft.sum(a[j].fi.fi, a[j].fi.se);
            ed += temp;
            if (ed > n - 1)
                break;
            auto itr = nos.lower_bound(mp(a[j].fi.fi, -INF));
            for (; itr != nos.end() && itr->fi < a[j].fi.se; itr++)
                adj[a[j].se].pb(itr->se), adj[itr->se].pb(a[j].se); //cout << j << " " << itr->fi << " " << itr->se << "\n";
            j++;
        }
        if (ed > n - 1)
            break;
        j = i;
        while (j <= n && a[j] == a[i])
            ft.add(a[j].fi.se, 1), nos.insert(mp(a[j].fi.se, a[j].se)), j++;
        i = j;
    }
    ll pos = 1;
    dfs(1);
    for (ll i = 1; i <= n; i++)
        if (!visited[i])
            pos = 0;
    if (ed == n - 1 && pos == 1)
    {
        cout << "YES\n";
    }
    else
        cout << "NO\n";
}