#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
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
#define N 2000006
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
string s;
v<char> cur(N);

using S = ll;

vector<S> a(N, 0);

typedef struct data
{
    S sum, minpref, maxpref;
} data;

struct data tree[4 * N];
// data lazy[4 * N];

struct data combine(struct data l, struct data r)
{
    struct data res;
    res.sum = l.sum + r.sum;
    res.maxpref = max(l.maxpref, l.sum + r.maxpref);
    res.minpref = min(l.minpref, l.sum + r.minpref);
    return res;
}
struct data make_data(S val)
{
    struct data res;
    res.sum = res.maxpref = res.minpref = val;
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

// Lazy updates... currently queries for minimum in a range... lazy may have to be modified for other queries.
S lazy[4 * N];

void push(S node)
{
    tree[node * 2].sum += lazy[node];
    lazy[node * 2] += lazy[node];
    tree[node * 2 + 1].sum += lazy[node];
    lazy[node * 2 + 1] += lazy[node];
    lazy[node] = 0;
}

void lazy_update(S node, S tl, S tr, S l, S r, S addend)
{
    if (l > r)
        return;
    if (l == tl && tr == r)
    {
        tree[node].sum += addend;
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
        return make_data(0);
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
    cin >> n;
    cin >> s;
    ll pos = 0;
    build(1, 0, N - 1);
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == 'L')
            pos = max(pos - 1, 0);
        else if (s[i] == 'R')
            pos++;
        else
        {
            ll diff = 0;
            if (cur[pos] == ')')
                diff++;
            else if (cur[pos] == '(')
                diff--;
            if (s[i] == ')')
                diff--;
            else if (s[i] == '(')
                diff++;
            cur[pos] = s[i];
            lazy_update(1, 0, N - 1, pos, pos, diff);
        }
        auto temp = lazy_query(1, 0, N - 1, 0, N - 1);
        if (temp.minpref >= 0 && temp.sum == 0)
            cout << temp.maxpref << " ";
        else
            cout << -1 << " ";
    }
    cout << "\n";
    return 0;
}