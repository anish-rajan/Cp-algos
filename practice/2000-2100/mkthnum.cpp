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
#define mod 1000000007
#define INF INT_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

v<ll> fact(N);
v<ll> prime_check(1e7 + 2);
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
    for (ll i = 2; i <= 1e7 + 1; i++)
    {
        if (prime_check[i])
            continue;
        primes.pb(i);
        for (ll j = 2 * i; j <= 1e7 + 1; j += i)
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

using S = ll;
vector<S> a(N);

struct PST
{
    S n;
    struct Vertex
    {
        Vertex *l, *r;
        S sum;

        Vertex(S val) : l(nullptr), r(nullptr), sum(val) {}
        Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0)
        {
            if (l)
                sum += l->sum;
            if (r)
                sum += r->sum;
        }
        Vertex(Vertex l, Vertex r)
        {
            sum = l.sum + r.sum;
        }
    };
    vector<Vertex *> roots;
    S last_upd;

    PST(S no, S m)
    {
        n = no;
        roots.resize(m + 1);
        roots[0] = build(1, n);
        last_upd = 0;
    }
    S qry(S l, S r, S k)
    {
        return get_ind(roots[l - 1], roots[r], 1, n, k);
    }
    void update(S time, S pos, S new_val)
    {
        roots[time] = upd(roots[last_upd], 1, n, pos, new_val);
        last_upd = time;
    }

    Vertex *build(S tl, S tr)
    {
        if (tl == tr)
            return new Vertex(a[tl]);
        S tm = (tl + tr) / 2;
        return new Vertex(build(tl, tm), build(tm + 1, tr));
    }

    S get_ind(Vertex *v, Vertex *v1, S l, S r, S k)
    {
        if (r == l)
            return l;
        ll mid = (l + r) / 2;
        if (v1->l->sum - v->l->sum >= k)
            return get_ind(v->l, v1->l, l, mid, k);
        else
            return get_ind(v->r, v1->r, mid + 1, r, k - v1->l->sum + v->l->sum);
    }

    Vertex get_sum(Vertex *v, S tl, S tr, S l, S r)
    {
        if (l > r)
            return Vertex(0);
        if (l == tl && tr == r)
            return *v;
        S tm = (tl + tr) / 2;
        Vertex temp = Vertex(get_sum(v->l, tl, tm, l, min(r, tm)), get_sum(v->r, tm + 1, tr, max(l, tm + 1), r));
        return temp;
    }

    Vertex *upd(Vertex *v, S tl, S tr, S pos, S new_val)
    {
        if (tl == tr)
            return new Vertex(new_val);
        S tm = (tl + tr) / 2;
        if (pos <= tm)
            return new Vertex(upd(v->l, tl, tm, pos, new_val), v->r);
        else
            return new Vertex(v->l, upd(v->r, tm + 1, tr, pos, new_val));
    }
};

ll n, m;
v<ll> b(N);
map<ll, ll> notoind;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
        cin >> b[i];
    v<ll> c = b;
    sort(c.begin() + 1, c.begin() + n + 1);
    c.erase(unique(c.begin() + 1, c.begin() + n + 1), c.end());
    for (ll i = 1; i < c.size(); i++)
        notoind[c[i]] = i;
    PST pst(n, n);
    for (ll i = 1; i <= n; i++)
    {
        // cout << (pst.get_sum(pst.roots[pst.last_upd], 1, n, notoind[b[i]], notoind[b[i]])).sum << " ";
        pst.update(i, notoind[b[i]], 1 + (pst.get_sum(pst.roots[pst.last_upd], 1, n, notoind[b[i]], notoind[b[i]])).sum);
    }
    while (m--)
    {
        ll l, r, k;
        cin >> l >> r >> k;
        // cout << pst.qry(l, r, k) << " ";
        cout << c[pst.qry(l, r, k)] << "\n";
    }
}