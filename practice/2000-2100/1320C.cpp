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
#define N1 200005
#define mod 1000000007
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

// v<ll> fact(N);
v<ll> prime_check(N);
v<ll> primes;

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

ll n, m, p;
v<pair<ll, ll>> arr(N1), b(N1);
v<pair<pair<ll, ll>, ll>> mon(N1);

using S = ll;

vector<S> a(N);

typedef struct data
{
    S val;
} data;

struct data tree[4 * N];

struct data combine(struct data l, struct data r)
{
    struct data res;
    res.val = max(l.val, r.val);
    return res;
}
struct data make_data(S val)
{
    struct data res;
    res.val = val;
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

S lazy[4 * N];

void push(S node)
{
    tree[node * 2].val += lazy[node];
    lazy[node * 2] += lazy[node];
    tree[node * 2 + 1].val += lazy[node];
    lazy[node * 2 + 1] += lazy[node];
    lazy[node] = 0;
}

void lazy_update(S node, S tl, S tr, S l, S r, S addend)
{
    if (l > r)
        return;
    if (l == tl && tr == r)
    {
        tree[node].val += addend;
        lazy[node] += addend;
    }
    else
    {
        push(node);
        S tm = (tl + tr) / 2;
        lazy_update(node * 2, tl, tm, l, min(r, tm), addend);
        lazy_update(node * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
        tree[node] = combine(tree[node * 2], tree[node * 2 + 1]);
    }
}

struct data lazy_query(S node, S tl, S tr, S l, S r)
{
    if (l > r)
        return make_data(-INF);
    if (l <= tl && tr <= r)
        return tree[node];
    push(node);
    S tm = (tl + tr) / 2;
    struct data temp = combine(lazy_query(node * 2, tl, tm, l, min(r, tm)), lazy_query(node * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    return temp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n >> m >> p;
    for (ll i = 1; i <= n; i++)
        cin >> arr[i].fi >> arr[i].se;
    for (ll i = 1; i <= m; i++)
        cin >> b[i].fi >> b[i].se;
    for (ll i = 1; i <= p; i++)
        cin >> mon[i].fi.fi >> mon[i].fi.se >> mon[i].se;
    sort(arr.begin() + 1, arr.begin() + n + 1);
    sort(b.begin() + 1, b.begin() + m + 1);
    sort(mon.begin() + 1, mon.begin() + p + 1);
    for (ll i = 1; i <= m; i++)
    {
        if (a[b[i].fi] == 0)
            a[b[i].fi] -= b[i].se;
    }
    for (ll i = 0; i < a.size(); i++)
        if (a[i] == 0)
            a[i] = -INF;
    build(1, 1, 1e6);
    ll j = 1, i = 1;
    ll ans = -INF;
    for (i = 1; i <= n && j <= p; i++)
    {
        while (j <= p && mon[j].fi.fi < arr[i].fi)
        {
            lazy_update(1, 1, 1e6, mon[j].fi.se + 1, 1e6, mon[j].se);
            j++;
        }
        ll temp = lazy_query(1, 1, 1e6, 1, 1e6).val;
        ans = max(ans, temp - arr[i].se);
    }
    while (i <= n)
    {
        ll temp = lazy_query(1, 1, 1e6, 1, 1e6).val;
        ans = max(ans, temp - arr[i].se);
        i++;
    }
    cout << ans << "\n";
}
