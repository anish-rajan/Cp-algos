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
vector<ll> p(N), b(N);
using S = ll;

vector<S> a(N);

typedef struct data
{
    S data1, data2, minsum;
} data;

struct data tree[4 * N];
// data lazy[4 * N];

struct data combine(struct data l, struct data r)
{
    struct data res;
    res.data1 = l.data1 + r.data1;
    res.data2 = l.data2 + r.data2;
    res.minsum = min(l.minsum + r.data1, l.data2 + r.minsum);
    return res;
}
struct data make_data(S val, S label)
{
    struct data res;
    res.data1 = res.data2 = res.minsum = 0;
    if (label == 0)
        res.data1 = res.data2 = res.minsum = val;
    if (label == 1)
        res.data1 = val;
    else
        res.data2 = val;
    res.minsum = min(res.data1, res.data2);
    // cout << label << " " << res.data1 << " " << res.data2 << " " << res.minsum << " " << val << "\n";
    return res;
}

void build(S v, S tl, S tr)
{
    if (tl == tr)
    {
        tree[v] = make_data(a[tl], 0);
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
        return make_data(0, 0);
    if (l == tl && r == tr)
    {
        return tree[node];
    }
    S tm = (tl + tr) / 2;
    struct data temp = combine(query(node * 2, tl, tm, l, min(r, tm)), query(node * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    return temp;
}
void update(S node, S tl, S tr, S pos, S new_val, S label)
{
    if (tl == tr)
    {
        tree[node] = make_data(new_val, label);
    }
    else
    {
        S tm = (tl + tr) / 2;
        if (pos <= tm)
            update(node * 2, tl, tm, pos, new_val, label);
        else
            update(node * 2 + 1, tm + 1, tr, pos, new_val, label);
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
    for (ll i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    build(1, 1, n);
    for (ll i = 1; i <= n; i++)
    {
        cin >> b[i];
        update(1, 1, n, p[i], b[i], 2);
    }
    ll ans = INF;
    for (ll i = 1; i <= n - 1; i++)
    {
        update(1, 1, n, p[i], 0, 2);
        update(1, 1, n, p[i], b[i], 1);
        // cout << query(1, 1, n, 1, 2).minsum << "\n";
        ans = min(ans, query(1, 1, n, 1, n).minsum);
    }
    cout << ans << "\n";
}
