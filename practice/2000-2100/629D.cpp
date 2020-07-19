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
#define N 100005
#define mod 1000000009
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

v<ll> fact(N);
v<ll> prime_check(1e6 + 2);
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

void init_fact()
{
    fact[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

ll C(ll n, ll r)
{
    if (n < r)
        return 0;
    ll temp = fact[n] * powmod(fact[r], mod - 2, mod) % mod;
    temp *= powmod(fact[n - r], mod - 2, mod);
    temp %= mod;
    return temp;
}

void Sieve()
{
    for (ll i = 2; i <= 1e6 + 1; i++)
    {
        if (prime_check[i])
            continue;
        primes.pb(i);
        for (ll j = 2 * i; j <= 1e6 + 2; j += i)
            prime_check[j] = i;
    }
}
ll phi(ll n)
{
    ll i, res = n;
    for (i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            res -= res / i;
        }
    if (n > 1)
        res -= res / n;
    return res;
}

/////////////////////////////////////START CODE HERE/////////////////////////////////////////////

ll n;
v<ll> r(N), h(N);
ll c;

using S = long long int;

vector<S> a(N);

typedef struct data
{
    S vol;
} data;

struct data tree[4 * N];
// data lazy[4 * N];

struct data combine(struct data l, struct data r)
{
    struct data res;
    res.vol = max(l.vol, r.vol);
    return res;
}
struct data make_data(S val)
{
    struct data res;
    res.vol = val;
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
        return make_data(0);
    if (l == tl && r == tr)
    {
        return tree[node];
    }
    S tm = (tl + tr) / 2;
    struct data temp = combine(query(node * 2, tl, tm, l, min(r, tm)), query(node * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    return temp;
}
void update(S node, S tl, S tr, S pos, S new_val)
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
    cin >> n;
    v<ll> vol;
    for (ll i = 1; i <= n; i++)
    {
        cin >> r[i] >> h[i];
        ll val = r[i] * r[i] * h[i];
        vol.pb(val);
    }
    build(1, 1, n);
    UN(vol);
    for (ll i = 1; i <= n; i++)
    {
        ll val = r[i] * r[i] * h[i];
        ll ind = lower_bound(ALL(vol), val) - vol.begin() + 1;
        ll maxvol = query(1, 1, n, 1, ind - 1).vol;
        // cout << maxvol + val << " " << ind << "\n";
        update(1, 1, n, ind, maxvol + val);
    }
    ld ans = 2 * asin(1.0) * query(1, 1, n, 1, n).vol;
    printf("%0.9Lf\n", ans);
}