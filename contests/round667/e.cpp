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

ll t;

using S = ll;

vector<pair<S, S>> a(N);

typedef struct data
{
    S data1, data2;
} data;

struct data tree[4 * N];
// data lazy[4 * N];

struct data combine(struct data l, struct data r)
{
    struct data res;
    res.data1 = max(l.data1, r.data1);
    res.data2 = max(l.data2, r.data2);
    return res;
}
struct data make_data(pair<S, S> val)
{
    struct data res;
    res.data1 = val.fi, res.data2 = val.se;
    return res;
}

void build(S v, S tl, S tr)
{
    if (tl == tr)
    {
        tree[v] = make_data(a[tl]);
    }
    else
    {
        S tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
    }
}
struct data query(S node, S tl, S tr, S l, S r)
{
    if (l > r)
        return make_data({0, 0});
    if (l == tl && r == tr)
    {
        return tree[node];
    }
    S tm = (tl + tr) / 2;
    struct data temp = combine(query(node * 2, tl, tm, l, min(r, tm)), query(node * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    return temp;
}
void update(S node, S tl, S tr, S pos, pair<S, S> new_val)
{
    if (tl == tr)
    {
        tree[node] = make_data(new_val);
    }
    else
    {
        S tm = (tl + tr) / 2;
        if (pos <= tm)
            update(node * 2, tl, tm, pos, new_val);
        else
            update(node * 2 + 1, tm + 1, tr, pos, new_val);
        tree[node] = combine(tree[node * 2], tree[node * 2 + 1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        v<ll> points;
        for (ll i = 1; i <= n; i++)
        {
            ll val;
            cin >> val;
            points.pb(val);
        }
        for (ll i = 1; i <= n; i++)
        {
            ll val;
            cin >> val;
        }
        sort(ALL(points));
        for (ll i = 0; i < n; i++)
        {
            ll ind = lower_bound(ALL(points), points[i] - k) - points.begin();
            ll ind1 = upper_bound(ALL(points), points[i] + k) - points.begin();
            ind1--;
            a[i].fi = i - ind + 1, a[i].se = ind1 - i + 1;
        }
        build(1, 0, n - 1);
        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
            ll t1 = a[i].fi, t2 = a[i].se;
            ll t3 = query(1, 0, n - 1, 0, i - a[i].fi).data1;
            ll t4 = query(1, 0, n - 1, i + 1, n - 1).data2;
            ll t5 = query(1, 0, n - 1, 0, i - 1).data1;
            ll t6 = query(1, 0, n - 1, a[i].se + i, n - 1).data2;
            ans = max(ans, t1 + max(t3, t4));
            ans = max(ans, t2 + max(t5, t6));
        }
        cout << ans << "\n";
    }
}
